//
//  Gaussian.hpp
//  Image Processing
//
//  Created by Magno Carlos on 01/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef Gaussian_hpp
#define Gaussian_hpp

#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;


int Sum_of_Matrix();
Mat Gaussian__Filter(Mat g_filter, Mat image);

#endif /* Gaussian_hpp */
