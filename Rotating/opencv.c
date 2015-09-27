#include "cv.h"
#include "highgui.h"


IplImage* rotateImage3(const IplImage* image, float angle)
{ 

	int width = image->width;
	int height = image->height;

	IplImage *rotatedImage = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, image->nChannels);
     
    CvPoint2D32f center;
	center.x = width/2.0f;
	center.y = height/2.0f; 
   
    CvMat* mapMatrix = cvCreateMat(2, 3, CV_32FC1);
    CvMat* rot = cv2DRotationMatrix(center, angle, 1.0, mapMatrix);
    CvRect bbox = cv2DRotatedRect(center,src.size(), degrees).boundingRect();

    cvWarpAffine(image, rotatedImage, mapMatrix, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0));
     
    return rotatedImage;
}

IplImage* rotateImage2(const IplImage* image, float angle)
{ 

	int width = image->width;
	int height = image->height;

	IplImage *rotatedImage = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, image->nChannels);
     
    CvPoint2D32f center;
	center.x = width/2.0f;
	center.y = height/2.0f; 
 
    CvMat* mapMatrix = cvCreateMat(2, 3, CV_32FC1);
 
    cv2DRotationMatrix(center, angle, 1.0, mapMatrix);
    cvWarpAffine(image, rotatedImage, mapMatrix, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0));
    cvReleaseImage(&image);
    cvReleaseMat(&mapMatrix);
 
    return rotatedImage;
}

// Rotate the imsage clockwise (or counter-clockwise if negative).
// Remember to free the returned image.
IplImage* rotateImage1(const IplImage* img, float angleDegrees)
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
 
IplImage* rotateImage(const IplImage* img, float angleDegrees)
{
	int height    = img->height;
	int width     = img->width;
	int step      = img->widthStep;
	int channels  = img->nChannels; 

	IplImage *rotatedImg = cvCreateImage(
							cvSize(height, width), 
							IPL_DEPTH_8U, 
							channels
							);

  	CvPoint2D32f center;
	center.x = width/2.0f;
	center.y = height/2.0f;

	CvMat *mapMatrix = cvCreateMat( 2, 3, CV_32FC1 );

	float x = width - 1.0f;
	float y = 0.0f;

	cv2DRotationMatrix(center, angleDegrees, 1, mapMatrix);
	cvmSet(mapMatrix, 0, 2 ,y);
	cvmSet(mapMatrix, 1, 2 ,x);
	cvWarpAffine(img, rotatedImg, mapMatrix, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0));

	return(rotatedImg);
}



int main(int argc, char** argv)
{ 
	IplImage* image = cvLoadImage("Example1.jpeg", 1); 
	
	cvNamedWindow( "Display", CV_WINDOW_AUTOSIZE );//Create and Name the window 

	cvShowImage( "Display", rotateImage2(image, 120));//Display the image
	 
	cvWaitKey(0);//wait until user hits a key,if number is +ve then that much milli seconds image will wait to be closed
	
	cvDestroyWindow( "Display" );//Destroy and De-allocate memory
	
	return 0;
}