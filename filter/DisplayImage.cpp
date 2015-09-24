#include <stdio.h>
#include <opencv2/opencv.hpp>  
using namespace cv;

int main( int argc, char** argv )
{
 char* imageName = argv[1];

 Mat image;
 /*
 We begin by loading an image using imread, located in the path given by imageName. 
 For this example, assume you are loading a RGB image.
 */
 image = imread( imageName, 1 );

 if( argc != 2 || !image.data )
 {
   printf( " No image data \n " );
   return -1;
 }

 Mat gray_image;
 /*
 Now we are going to convert our image from BGR to Grayscale format. 
 OpenCV has a really nice function to do this kind of transformations
 arguments:
 	a source image (image)
	a destination image (gray_image), in which we will save the converted image.
	an additional parameter that indicates what kind of transformation will be performed. 
	In this case we use CV_BGR2GRAY (because of imread has BGR default channel order in case of color images).
 */
 cvtColor( image, gray_image, CV_BGR2GRAY );

 /*
 So now we have our new gray_image and want to save it on disk 
 (otherwise it will get lost after the program ends). 
 To save it, we will use a function analagous to imread: imwrite
 */
 imwrite( "../../images/DisplayImage.jpeg", gray_image );

 /*
 We create two windows and use them to show the original image as well as the new one:
 */
 namedWindow( imageName, CV_WINDOW_AUTOSIZE );
 namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

 imshow( imageName, image );
 imshow( "Gray image", gray_image );

 waitKey(0);

 return 0;
}