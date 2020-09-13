//
//  Sobel_Improved.hpp
//  Image Processing
//
//  Created by Magno Carlos on 07/04/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef Sobel_Improved_hpp
#define Sobel_Improved_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

Mat Mask_0(Mat kernel_vertical, Mat image);
Mat Mask_45(Mat kernel_horizontal, Mat image);
Mat Mask_90(Mat kernel_vertical, Mat image);
Mat Mask_135(Mat kernel_horizontal, Mat image);
Mat Mask_180(Mat kernel_vertical, Mat image);
Mat Mask_225(Mat kernel_horizontal, Mat image);
Mat Mask_270(Mat kernel_vertical, Mat image);
Mat Mask_315(Mat kernel_horizontal, Mat image);


#endif /* Sobel_Improved_hpp */
