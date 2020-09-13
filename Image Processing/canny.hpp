//
//  canny.hpp
//  Image Processing
//
//  Created by Magno Carlos on 14/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef canny_hpp
#define canny_hpp

#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;


//Mat Gaussian__2(Mat g_filter, Mat image);
Mat Canny__trial_vertical(Mat kernel_vertical, Mat image);
Mat Canny__trial_horizontal(Mat kernel_horizontal, Mat image);
Mat Hysteresis(Mat ted);
Mat directionX(Mat xdirection, Mat ydirection);
float maior2(float numero_1, float numero_2, float numero_3 );
void CannyThreshold2(int, void*);


#endif /* canny_hpp */
