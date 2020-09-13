//
//  Loops.hpp
//  Image Processing
//
//  Created by Magno Carlos on 22/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#ifndef Loops_hpp
#define Loops_hpp

#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int Sum_of_Matrix(Mat input);
void Beginning(Mat receiver_image, Mat kernel_vertical);
void Shifter(Mat image, Mat kernel);

#endif /* Loops_hpp */
