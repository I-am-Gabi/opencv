#include "cv.h"
#include "cxcore.h" 
#include "highgui.h"
 
// https://codezone4.wordpress.com/2013/02/03/create-negative-image-using-opencv/

// i can pass image  as constante, to make sure that no change
int negative(IplImage* image)
{ 
	IplImage *dest = cvCloneImage(image);
	 
	cvNamedWindow("Original:", 1);
	cvShowImage("Original:", image);
	 
	cvNot(image, dest); //Create a negative image from source image
	cvNamedWindow("Negative:", 1);
	cvShowImage("Negative:", dest);
	 
	cvWaitKey(0);
	 
	cvDestroyWindow("Original:");
	cvReleaseImage(&image);

	cvDestroyWindow("Negative:");
	cvReleaseImage(&dest);

	return 0;
}
 
int main( void )
{ 
  IplImage* image = cvLoadImage("Example1.jpeg", 1); 
  negative(image);
  return 0;
}