#pragma once

void Mat_to_vector_Point2f( cv::OutputArray& , std::vector<cv::Point2f>& );

void Createline(cv::Mat inputma, cv::Point a, cv::Point b, int i);

void calcChessboardCorners(cv::Size boardSize, float squareSize, std::vector<cv::Point3f> &object, std::vector<cv::Point2f> &corners);
