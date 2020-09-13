//
//  laplacian.hpp
//  Image Processing
//
//  Created by Magno Carlos on 14/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef laplacian_hpp
#define laplacian_hpp

#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

Mat Mask_Laplacian (Mat kernel, Mat image);
void Mask_Laplacian12345 (Mat kernel, Mat image);

#endif /* laplacian_hpp */
