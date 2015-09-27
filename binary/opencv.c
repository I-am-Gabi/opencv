#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
 
int toBinary(IplImage* rgb)
{ 
	IplImage *gray = cvCreateImage(cvSize(rgb->width,rgb->height), 8, 1);
	 
	cvCvtColor(rgb, gray, CV_RGB2GRAY); //Change from RGB to GrayScale
	IplImage *binary = cvCloneImage(gray);
	 
	cvNamedWindow("RGB:", 1);
	cvShowImage("RGB:", rgb);
	 
	cvNamedWindow("Grayscale:", 1);
	cvShowImage("Grayscale:", gray);
	 
	cvThreshold(gray, binary, 80, 255, CV_THRESH_BINARY);   //Change from Grayscale to Binary
	cvNamedWindow("Binary:", 1);
	cvShowImage("Binary:", binary);
	 
	cvWaitKey(0);
	 
	cvDestroyWindow("RGB:");
	cvReleaseImage(&rgb);
	cvDestroyWindow("Grayscale:");
	cvReleaseImage(&gray);
	cvDestroyWindow("Binary:");
	cvReleaseImage(&binary);
	return 0;
}

int main( void )
{ 
  IplImage* image = cvLoadImage("Example1.jpeg", 1); 
  toBinary(image);
  return 0;
}