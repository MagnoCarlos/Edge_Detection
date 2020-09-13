//
//  Gradient.cpp
//  Image Processing
//
//  Created by Magno Carlos on 19/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Gradient.hpp"
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Sobel_Improved.hpp"


using namespace std;
using namespace cv;


int i = 0; // variable to control the output of Pythagoras
int numero_inteiro = 0;



void Pythagoras(Mat x, Mat y) {
    
    Mat Xsquare, Ysquare;
    Mat sum, direction; // = Mat(Xsquare.rows, Xsquare.cols, CV_32F/*double check this type*/);
    
    
    pow(x, 2, Xsquare);
    pow(y, 2, Ysquare);
    add((Xsquare), (Ysquare), sum);    
    //    Mat result = Mat(sum.rows, sum.cols, CV_32F/*double check this type*/);
    Mat result_conversion, output_image;
    sum.convertTo(result_conversion, CV_32F, 1/*scale value 0.125*/); // converts sum to float
    sqrt( result_conversion, output_image);
    
    if( i == 0) {
        
//        imshow("Sobel_Result" , output_image);
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_Result.png", output_image);
        
        
    } else if( i == 1) {
        
//        imshow("Canny_Result" , output_image);
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Canny_Result.png", output_image);
        
    } else if( i == 2) {
        
//        imshow("Sobel_Result_Noisy" , output_image);
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_Result_Noisy.png", output_image);
    } else if( i == 3) {
        
//        imshow("Canny_Result_Noisy" , output_image);
//        waitKey(0);
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Canny_Result_Noisy.png", output_image);
    }
    
    i++;
    
}


Mat Pythagoras_NMS(Mat x_NMS, Mat y_NMS) {
    
    Mat Xsquare_NMS, Ysquare_NMS;
    Mat sum_NMS, conv; // = Mat(Xsquare.rows, Xsquare.cols, CV_32F/*double check this type*/);
    
    
    pow(x_NMS, 2, Xsquare_NMS);
    pow(y_NMS, 2, Ysquare_NMS);
    add((Xsquare_NMS), (Ysquare_NMS), sum_NMS);

    Mat result_conversion_NMS, output_image_NMS;
    sum_NMS.convertTo(result_conversion_NMS, CV_32F, 1/*scale value 0.125*/); // converts sum to float
    sqrt( result_conversion_NMS, output_image_NMS);
//    convertScaleAbs( output_image_NMS, conv ); // to present in the imshow
    
    if( numero_inteiro == 0) {
    
//        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_ResultSecond.png", output_image_NMS);
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_ResultSecond.png", output_image_NMS);
        
        
    }
    
    return output_image_NMS;
    
}


void maior() { // Calculate the biggest direction
    
}



int maior(int numero_0, int numero_45, int numero_90, int numero_135, int numero_180, int numero_225, int numero_270, int numero_315 ) {
    int temp = 0;
    int array[8] = {numero_0, numero_45,numero_90, numero_135, numero_180, numero_225, numero_270, numero_315};

    for(int i=0; i < 8; i++) {
        
        if(array[i] > temp)
            temp=array[i];
    }

    return temp;
}


Mat Improved_Sobel(Mat testando_1, Mat testando_2, Mat testando_3, Mat testando_4, Mat testando_5, Mat testando_6, Mat testando_7, Mat testando_8, Mat img) { // output the improved sobel
    
//    int colunas = testando_1.cols;
//    int filas = testando_1.rows;
    Mat output = Mat(718, 1078, CV_16S /*image.type()*//* CV_16S double check this type*/);
    
    for (int i = 0; i < testando_3.rows; i++) {
        
        for (int j = 0; j < testando_3.cols; j++) {
            
            output.at<int16_t>(i,j) = maior(testando_1.at<int16_t>(i,j), testando_2.at<int16_t>(i,j), testando_3.at<int16_t>(i,j), testando_4.at<int16_t>(i,j), testando_5.at<int16_t>(i,j), testando_6.at<int16_t>(i,j), testando_7.at<int16_t>(i,j), testando_8.at<int16_t>(i,j) ) ;
            
        }
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Improved_Sobel.png", output);
    return output;
}














