# Opencv

This project is part of the material for the book "O Reilly - Learning OpenCV"

## IplImage
Is the basic structure used to encode what we generally call “images”. These images may be grayscale, color, four-channel (RGB+alpha), and each channel may contain any of several types of integer or floating- point numbers. Hence, this type is more general than the ubiquitous three-channel 8-bit RGB image that immediately comes to mind.

Even though OpenCV is implemented in C, the structures used in OpenCV have an object-oriented design; in effect, IplImage is derived from CvMat, which is derived from CvArr

OpenCV provides a vast arsenal of useful operators that act on these images, including tools to resize images, extract individual channels, find the largest or smallest value of a particular channel, add two images, threshold an image, and so on.

##CVMat Matrix 

First, there is no “vector” construct in OpenCV. Whenever we want a vector, we just use a matrix with one column (or one row, if we want a transpose or conjugate vector). 

Second, the concept of a matrix in OpenCV is somewhat more abstract than the concept we learned in your linear algebra class.