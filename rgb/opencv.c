#include "cv.h"
#include "highgui.h"
#include <stdio.h>

void mouseEvent(int evt, int x, int y, int flags, void* param){ 
    IplImage* rgb = (IplImage*) param;
    if(evt==CV_EVENT_MOUSEMOVE)
    {
          char* data = rgb->imageData + rgb->widthStep * y + x * 3;
          printf("Current Position: x= %d y= %d B=%d G=%d R=%d\n",x,y,data[0],data[1],data[2]);
    }
}

int main() {
	cvNamedWindow("rgb", CV_WINDOW_AUTOSIZE); 
	IplImage* rgb = cvLoadImage("Example1.jpeg", 1);

	while(1){ 
		cvShowImage("rgb", rgb); 

		cvSetMouseCallback("rgb", mouseEvent, (void*) rgb);
		
		char c = cvWaitKey(33);
		if( c == 27 ) break;
	}

	cvDestroyWindow( "rgb" );
}
