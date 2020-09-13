//
//  Resoration.cpp
//  Image Processing
//
//  Created by Magno Carlos on 25/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Resoration.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

Mat gaussian_filter = (Mat_<int>(3,3) << 1, 2, 1,
                       2, 4, 2,
                       1, 2, 1);

int Sum_of_Matrix() { // Returns the number used for the averaging
    
    int sum_result = 0;
    for (int i = 0; i < gaussian_filter.rows; i++) {
        
        for (int j =0; j < gaussian_filter.cols; j++) {
            sum_result += gaussian_filter.at<int>(i,j);
        }
        
    }
    
    return sum_result;
    
}
