#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <opencv2/core/utility.hpp>
#include "PoseEstimation.h"

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:\\Users\\vyomkesh\\Documents\\UF\\S4\\Individual Study\\HumanPoseEstimationProjectWork\\poseEstimation\\resources\\images\\right01.jpg", IMREAD_COLOR); 
	Mat outputMat, rvec, tvec;
	cv::Size boardSize(6,9);
	const float squaresize = 3.0;
	cv::OutputArray ptVec = outputMat;
	
	String filename("C:\\Users\\vyomkesh\\Documents\\UF\\S4\\Individual Study\\HumanPoseEstimationProjectWork\\poseEstimation\\resources\\univ_intrinsics.yml");
	FileStorage fs(filename, FileStorage::READ); 
	Mat intrinsics, distortion;
	fs["camera_matrix"] >> intrinsics;
	fs["dist_coefs"] >> distortion;

	std::vector<Point3f> boardPoints; // fill the array as described at 3. ... 
	boardPoints.push_back(Point3f(3, 0, 0));
	boardPoints.push_back(Point3f(0, 3, 0));
	boardPoints.push_back(Point3f(0, 0, 3));

	vector<Point3f> objectpoints, testobjectpoints;

	testobjectpoints.push_back(Point3f(9.0, 0, 0)); 
	testobjectpoints.push_back(Point3f(0, 9.0, 0)); 
	testobjectpoints.push_back(Point3f(0, 0, -9.0)); 
	testobjectpoints.push_back(Point3f(0, 0, 0)); 

	bool found = findChessboardCorners(img, boardSize, ptVec, CALIB_CB_ADAPTIVE_THRESH);

	vector<Point2f> point2fVecFromMat, resultCorners;
	Mat_to_vector_Point2f(ptVec, point2fVecFromMat);

	calcChessboardCorners(boardSize, squaresize, objectpoints, point2fVecFromMat);

	Point p0, p1, p2, p3;
	if (found)
	{
		solvePnP(Mat(objectpoints), point2fVecFromMat, intrinsics, distortion, rvec, tvec, false);
		projectPoints(Mat(testobjectpoints), rvec, tvec, intrinsics, distortion, resultCorners);
		std::cout << resultCorners;

		p1.x = resultCorners[0].x;
		p1.y = resultCorners[0].y;
		p2.x = resultCorners[1].x;
		p2.y = resultCorners[1].y;
		p3.x = resultCorners[2].x;
		p3.y = resultCorners[2].y;
		p0.x = resultCorners[3].x;
		p0.y = resultCorners[3].y;

		Createline(img, p0, p1, 1);
		Createline(img, p0, p2, 2);
		Createline(img, p0, p3, 3);

		namedWindow("Project 3 lines of chessboard plane"); 
		imshow("Project 3 lines of chessboard plane", img);
		waitKey(0);
	}

	testobjectpoints.push_back(Point3f(9, 9, -9.0));
	testobjectpoints.push_back(Point3f(9, 9, 0));
	testobjectpoints.push_back(Point3f(0, 9, -9.0)); 
	testobjectpoints.push_back(Point3f(9, 0, -9.0));

	projectPoints(Mat(testobjectpoints), rvec, tvec, intrinsics, distortion, resultCorners);
	std::cout << resultCorners;
	Point p4, p5, p6, p7;
	p1.x = resultCorners[0].x; p1.y = resultCorners[0].y;
	p2.x = resultCorners[1].x; p2.y = resultCorners[1].y;
	p3.x = resultCorners[2].x; p3.y = resultCorners[2].y;
	p0.x = resultCorners[3].x; p0.y = resultCorners[3].y;
	p4.x = resultCorners[4].x; p4.y = resultCorners[4].y;
	p5.x = resultCorners[5].x; p5.y = resultCorners[5].y;
	p6.x = resultCorners[6].x; p6.y = resultCorners[6].y;
	p7.x = resultCorners[7].x; p7.y = resultCorners[7].y;


	std::vector<cv::Point>drawpic; 
	drawpic.push_back(p0);
	drawpic.push_back(p2); 
	drawpic.push_back(p5); 
	drawpic.push_back(p1);
	std::vector<std::vector<cv::Point>>contours;
	contours.push_back(drawpic);
	fillPoly(img, contours, Scalar(255, 0, 0));
	Createline(img, p0, p1, 3);
	Createline(img, p0, p2, 3);


	Scalar color;
	Createline(img, p0, p1, 1);
	Createline(img, p0, p2, 2);
	Createline(img, p0, p3, 3);
    //Createline(img, p0, p3, 2); 
	Createline(img, p2, p5, 3); 
	Createline(img, p1, p5, 3);
	Createline(img, p2, p6, 2); 
	Createline(img, p5, p4, 2);
	Createline(img, p1, p7, 2); 
	Createline(img, p6, p4, 1); 
	Createline(img, p4, p7, 1); 
	Createline(img, p7, p3, 1); 
	Createline(img, p6, p3, 1);



	namedWindow("Project cube on chessboard plane");
	imshow("Project cube on chessboard plane", img);
	waitKey(0);

	return 0;
}


//vector_Point2f
void Mat_to_vector_Point2f(OutputArray& oa, std::vector<Point2f>& v_point)
{
	v_point.clear();

	// Should Work on any OpenCV version
	cv::Mat mat = oa.getMat();
	Point2f *data = (Point2f *)mat.data;
	int length = mat.total();
	std::vector<Point2f> input;
	v_point.assign(data, data + length);
	
}

void calcChessboardCorners(Size boardSize, float squareSize, vector<Point3f> &object, vector<Point2f> &corners){
	for (int i = 0; i < boardSize.height; i++)
		for (int j = 0; j < boardSize.width; j++)
			object.push_back(Point3f(float(j*squareSize), float(i*squareSize), 0)); 
}

void Createline(Mat inputma, Point a, Point b, int i)
{
	Scalar colors = Scalar(255, 0, 0);
	if (i == 1){
		colors = Scalar(0, 0, 255);
	}
	else if(i == 2) { 
		colors = Scalar(0, 255, 0); 
	}
	line(inputma, a, b, colors, 2, LINE_8); 
}


