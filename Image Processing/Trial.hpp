//
//  Trial.hpp
//  Image Processing
//
//  Created by Magno Carlos on 23/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef Trial_hpp
#define Trial_hpp

#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

void Beginning(Mat kernel, Mat image, /*int move_along_columns,*/ int column_limit, /*int row_image,*/ int row_limit );

Mat Shifter(Mat kernel, Mat image, /*int move_along_columns,*/ int column_limit,  /*int row_image,*/ int row_limit);

void Mask_Laplacian12345 (Mat kernel, Mat image);


#endif /* Trial_hpp */
