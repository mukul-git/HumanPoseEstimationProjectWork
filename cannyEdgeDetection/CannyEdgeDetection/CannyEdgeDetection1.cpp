// CannyEdgeDetection.cpp : Defines the entry point for the application.
//

#include "CannyEdgeDetection.h"

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

#include <cv.h>
#include <highgui.h>
#include <math.h>

using namespace cv;

int main(int argc, char** argv)
{
	Mat img, gray;
	const char* imgFilename = "C:\\Users\\vyomkesh\\Documents\\UF\\S4\\Individual Study\\HumanPoseEstimationProjectWork\\cannyEdgeDetection\\building.jpg";
	if (argc != 2 && !(img = imread(imgFilename, 1)).data)
		return -1;
	cvtColor(img, gray, CV_BGR2GRAY);
	// smooth it, otherwise a lot of false circles may be detected
	GaussianBlur(gray, gray, Size(9, 9), 2, 2);
	std::vector<Vec3f> circles;
	HoughCircles(gray, circles, CV_HOUGH_GRADIENT,
		2, gray.rows / 4, 200, 100);
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// draw the circle center
		circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// draw the circle outline
		circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}
	namedWindow("circles", 1);
	imshow("circles", img);
	return 0;
}