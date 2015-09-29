#include <stdio.h>
#include "cv.h"
#include "highgui.h"
/*
http://linuxconfig.org/use-opencv-to-separate-rgb-image-into-red-green-and-blue-components#h3-usage
*/ 

int main( int argc, char** argv )

{ 
	IplImage *img = cvLoadImage("Example1.jpeg", 1); 

	IplImage *red = cvCreateImage(
		cvSize(img->width, img->height ),
		img->depth, img->nChannels 
	);

	IplImage *green = cvCreateImage(
		cvSize(img->width, img->height ),
		img->depth, img->nChannels 
	);

	IplImage *blue = cvCreateImage(
		cvSize(img->width, img->height ),
		img->depth, img->nChannels 
	);

	// setup the pointer to access img data 
	uchar *pImg   = ( uchar* )img->imageData;

	// setup pointer to write data 
	uchar *pRed   = ( uchar* )red->imageData;
	uchar *pGreen = ( uchar* )green->imageData;
	uchar *pBlue  = ( uchar* )blue->imageData;    

	int i, j, rED, gREEN, bLUE, byte;
	for( i = 0 ; i < img->height ; i++ ) 
	{
	  for( j = 0 ; j < img->width ; j++ ) 
	  {
		  rED = pImg[i*img->widthStep + j*img->nChannels + 2];

		  gREEN = pImg[i*img->widthStep + j*img->nChannels + 1];
		  bLUE = pImg[i*img->widthStep + j*img->nChannels + 0];
		  // RED
		  pRed[i*img->widthStep + j*img->nChannels + 2] = rED;
		  
		  // GREEN
		  pGreen[i*img->widthStep + j*img->nChannels + 1] = gREEN;

		  // BLUE
		  pBlue[i*img->widthStep + j*img->nChannels + 0] = bLUE;
	  }
	}


	cvNamedWindow("rgb", CV_WINDOW_AUTOSIZE); 

	while(1){ 
		int c;
		scanf("%d", &c); 

		cvDestroyWindow( "rgb" );

		if (c == 1)
			cvShowImage("rgb", red); 
 		else if (c == 2)
 			cvShowImage("rgb", green);
 		else
 			cvShowImage("rgb", blue);
 	
		if( c == 27 ) break;
	}

	return 0;
}