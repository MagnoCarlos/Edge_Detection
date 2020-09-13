//
//  Noise.cpp
//  Image Processing
//
//  Created by Magno Carlos on 05/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Noise.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"



using namespace std;
using namespace cv;

Mat Noise(Mat img) {
    
    Mat saltpepper_noise = Mat::zeros(img.rows, img.cols,CV_8U);
    randu(saltpepper_noise,0,255);
    
    Mat black = saltpepper_noise < 30;
    Mat white = saltpepper_noise > 225;
    
    Mat saltpepper_img = img.clone();
    saltpepper_img.setTo(255,white);
    saltpepper_img.setTo(0,black);
//    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Salt Pepper.png", saltpepper_img);
    
    return saltpepper_img;
}