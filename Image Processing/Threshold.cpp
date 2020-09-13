//
//  Threshold.cpp
//  Image Processing
//
//  Created by Magno Carlos on 13/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

// ADD real time edge detection

#include "Threshold.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

Mat img_threshloding7 = imread("/Users/GreatestBrain/Desktop/Lenna.png", 0); /*The 0 converts it to grayscale*/

int Sum_of_Matrix2() { // Returns the number used for the averaging
    
    int sum_result = 0;
    
    for (int i = 0; i < img_threshloding7.rows; i++) {
        
        for (int j =0; j < img_threshloding7.cols; j++) {
            sum_result += img_threshloding7.at<int>(i,j);
        }
        
    }
    
    
    return sum_result;
    
}

void Thresholding( Mat input) {
    
    int threshold = 127; // because is the half of 255
    int max_val = 255; // because that is the max value of a pixel in a grayscale image
    int mean;
//    int rows = input.rows;
//    int column = input.cols;

    Mat thresholded = Mat(input.size(), input.type()/*double check this type*/);
    
//    mean =  Sum_of_Matrix2() / (512 * 512);
    mean =  Sum_of_Matrix2() / (input.rows * input.cols);
    
    
    for (int i = 0; i < input.rows; i++) {
        
        for (int j =0; j < input.cols; j++) {
            
            if( input.at<int>(i,j) > threshold) {
                
                thresholded.at<int>(i,j) = max_val; // set new thresholded matrix to 1
                
            } else {
                
                thresholded.at<int>(i,j) = 0; // set new thresholded matrix to 0
                
            }
        }
        
    }
    
    
//    cout << thresholded << endl;
    
    
}