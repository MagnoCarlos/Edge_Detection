//
//  sobel.hpp
//  Image Processing
//
//  Created by Magno Carlos on 14/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef sobel_hpp
#define sobel_hpp


#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

Mat Mask_Vertical(Mat kernel_vertical, Mat image);
Mat Mask_Horizontal(Mat kernel_horizontal, Mat image);

#endif /* sobel_hpp */
