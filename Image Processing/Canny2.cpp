//
//  Canny2.cpp
//  Image Processing
//
//  Created by Magno Carlos on 06/04/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Canny2.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Gaussian.hpp"
#include "Gradient.hpp"

using namespace std;
using namespace cv;

Mat grayscale_img;
Mat dst, detected_edges;
Mat filtro2;
Mat detected_edges2;
int lowThreshold = 0;
const int max_lowThreshold = 100;
const int kernel_size = 3; // Sobel Kernel


void CannyThreshold(int, void*) {
    detected_edges2 = Gaussian__Filter( filtro2, grayscale_img); // blurs the image
    Canny( detected_edges2, detected_edges, lowThreshold, lowThreshold*3 /*ratio*/, kernel_size );
    dst = Scalar::all(0);
    imshow( "Edge Map", detected_edges );
}

Mat Canny_Original( Mat colored_img, Mat filtro) {
    filtro2 = filtro;
    dst.create( colored_img.size(), colored_img.type() );
    cvtColor( colored_img, grayscale_img, COLOR_BGR2GRAY );
    namedWindow( "Edge Map", WINDOW_AUTOSIZE );
    createTrackbar( "Min Threshold: 0 ", "Edge Map", &lowThreshold, max_lowThreshold, CannyThreshold );
    CannyThreshold(0, 0);
    waitKey(0);

    return detected_edges;
    
}

