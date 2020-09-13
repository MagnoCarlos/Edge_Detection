//
//  Video_Capture.cpp
//  Image Processing
//
//  Created by Magno Carlos on 15/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Video_Capture.hpp"
#include <iostream>
#include <vector>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "laplacian.hpp"

using namespace std;
using namespace cv;

const int fps = 20;

Mat Video_cap() {
    
    Mat frame, imagem; // stores the current frame process it n mve along to the next frame
    VideoCapture cam(0);
    
    namedWindow("Camera");
    
    
    // pressing a key to move frames
    
//    while (1) {
//        cam >> frame;
//        imshow("camera", frame);
//        
//        if(!cam.isOpened()) {
//            return -1;
//        }
//        if (waitKey(0 /*if changed to it will be ongoing*/ ) == 27) { // needs to keep pressing a key in order to change frame
//            break;
//        }
//    }
    
    
    // without  pressing a key to move frames
    if(!cam.isOpened()) {
//        return -1;
    }
    
    while (cam.read(frame)) {
        
        cvtColor(frame, imagem, COLOR_BGR2GRAY); // convert the RGB to Grayscale
        imshow("camera", imagem);
//        imshow("camera", Mask_Laplacian(kernel_Laplacian, img);
        
        if (waitKey(1000/fps /*if changed to it will be ongoing*/ ) >= 0) { // needs to keep pressing a key in order to change frame
            break;
        }
    }
    return imagem;
    
}