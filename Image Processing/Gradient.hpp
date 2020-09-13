//
//  Gradient.hpp
//  Image Processing
//
//  Created by Magno Carlos on 19/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef Gradient_hpp
#define Gradient_hpp

#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

void Pythagoras(Mat x, Mat y);
Mat Pythagoras_NMS(Mat x, Mat y);
Mat Improved_Sobel(Mat kernel_0, Mat kernel_45, Mat kernel_90, Mat kernel_135, Mat kernel_180, Mat kernel_225, Mat kernel_270, Mat kernel_315, Mat img);


#endif /* Gradient_hpp */
