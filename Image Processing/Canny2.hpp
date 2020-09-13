//
//  Canny2.hpp
//  Image Processing
//
//  Created by Magno Carlos on 06/04/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef Canny2_hpp
#define Canny2_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Gaussian.hpp"
#include "Gradient.hpp"

using namespace std;
using namespace cv;

Mat Canny_Original(Mat src, Mat filtro);

#endif /* Canny2_hpp */
