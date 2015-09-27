#include "cv.h"
#include "highgui.h"


// Rotate the image clockwise (or counter-clockwise if negative).
// Remember to free the returned image.
IplImage* rotateImage(const IplImage* img, float angleDegrees)
{
	// Create a map_matrix, where the left 2x2 matrix
	// is the transform and the right 2x1 is the dimensions.
	float m[6];
	CvMat M = cvMat(2, 3, CV_32F, m);
	int width = img->width;
	int height = img->height;
	float angleRadians = angleDegrees * ((float)CV_PI / 180.0f);
	m[0] = (float)( cos(angleRadians) );
	m[1] = (float)( sin(angleRadians) );
	m[3] = -m[1];
	m[4] = m[0];
	m[2] = width * 0.5f;  
	m[5] = height * 0.5f;  

	// Make a spare image for the result
	CvSize sizeRotated;
	sizeRotated.width = cvRound(width);
	sizeRotated.height = cvRound(height);

	// Rotate
	IplImage* imageRotated = cvCreateImage( 
		sizeRotated,
		img->depth, 
		img->nChannels 
	);

	// Transform the image
	cvGetQuadrangleSubPix(img, imageRotated, &M);

	return imageRotated;
}

int main(int argc, char** argv)
{ 
	IplImage* image = cvLoadImage("Example1.jpeg", 1); 
	cvNamedWindow( "Display", CV_WINDOW_AUTOSIZE );//Create and Name the window 

	cvShowImage( "Display", rotateImage(image, 90));//Display the image
	 
	cvWaitKey(0);//wait until user hits a key,if number is +ve then that much milli seconds image will wait to be closed
	
	cvDestroyWindow( "Display" );//Destroy and De-allocate memory
	
	return 0;
}