//
//  Fuzzy.cpp
//  Image Processing
//
//  Created by Magno Carlos on 15/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Fuzzy.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Gaussian.hpp"

using namespace std;
using namespace cv;



double bright;
double dark;