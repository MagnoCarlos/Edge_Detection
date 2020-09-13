//
//  Trial.cpp
//  Image Processing
//
//  Created by Magno Carlos on 23/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Trial.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

vector<int> new_matrixVal1;
int row_image = 0;
//int controller123 = 0;
int move_along_rows = 0;
int move_along_columns = 0;
int index12 = 0;
int sum_numbers = 0;
int row_kernel = 0;
int column_kernel = 0;
int padding_variable2 = 1;



void Mask_Laplacian12345 (Mat kernel, Mat image) {
    
    //    VARIABLES DECLARATION
//    Mat Laplacian_output;
    int row_limit2 = kernel.rows - 1;
//    int row_image = 0;
    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int move_along_columns = 0;
    int column_limit2 = kernel.cols - 1;
    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable2 = 1;
    //////////////////////////////////////////////#####################################/////////////////////////////////////
    
    
    Beginning( kernel, image, /*move_along_columns,*/ column_limit2, /*row_image,*/ row_limit2);
    
    
//    return Laplacian_output;
    
}



void Beginning(Mat kernel2, Mat image, /*int move_along_columns,*/ int column_limit, /*int row_image,*/ int row_limit ) {
    
    
    //////////////////////////////////////////////#####################################/////////////////////////////////////
    int storage[9];
//    int index12 = 0;
//    int sum_numbers = 0;
//    int row_kernel = 0;
//    int column_kernel = 0;
    
    
BEGINNING:
    for(int column = move_along_columns; column < image.cols /*number of columns*/; column++) { // Columns
        
        
        storage[index12] = image.at<uint8_t>(row_image,column) * kernel2.at<int>(row_kernel,column_kernel); // Save the Multiplication values
        
        if(column == column_limit) {
            if (row_image == row_limit) {
                
                for (int a = 0; a <  9 /*number of values in the kernel*/; a++) { //sum everything in storage variable
                    sum_numbers += storage[a];
                }
                new_matrixVal1.push_back( sum_numbers ); // Adds the new pixel of the new matrix to the end of the array
                index12 = 0; row_kernel = 0; column_kernel = 0; sum_numbers=0;// Reset to 0 the index, sum, column_kernel and row_kernel values
                
                Shifter( kernel2,  image, /*move_along_columns,*/ column_limit, /*row_image,*/ row_limit);
            }
            row_image++; // Move to the next row
            row_kernel++;
            column = move_along_columns;
            column_kernel = 0;
            index12++;
            goto BEGINNING;
        }
        index12++; // Increments index for different positions in storage
        column_kernel++;
    }
    
}

Mat Shifter(Mat kernel3, Mat image3, /*int move_along_columns,*/ int column_limit3, /*int row_image,*/ int row_limit3) {
    
    Mat test;
    int padding_column; int padding_row;
    
    
    padding_column = image3.cols - kernel3.cols + 1; // Find the new number of columns
    padding_row = image3.rows - kernel3.rows + 1;  // Find the new number of rows
    
    if(padding_variable2 < padding_column) { // To move along the columns
        
        move_along_columns++; // Move to the next column
        row_image = move_along_rows; // Set row to the value of move_along_rows;
        padding_variable2++;
        column_limit3++;
        
        Beginning( kernel3, image3, /*move_along_columns,*/ column_limit3, /*row_image,*/ row_limit3 );
        
    } else if((padding_variable2 == padding_column) && (move_along_rows != padding_row)) { // To move along the rows
        
        move_along_rows++; // Move to the next row
        row_limit3++;
        row_image = move_along_rows;
        move_along_columns = 0; // Reset move_along_columns to 0
        padding_variable2 = 1; // Reset padding_variable to 1
        column_limit3 = kernel3.cols - 1; // Reset column_limit to 2
        
        Beginning( kernel3, image3, /*move_along_columns,*/ column_limit3, /*row_image,*/ row_limit3);
        
    } else if( (padding_variable2 == padding_column) && (move_along_rows == padding_row) ) { // Check if that is the last element of the matrix in  order to finish the program
        
        
        Mat Output_Image = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
        int increment=0;
        
        for(int f = 0;f < padding_row;f++) {
            
            for(int j = 0;j < padding_column;j++) {
                
                Output_Image.at<int16_t>(f,j) =  new_matrixVal1[increment];
                increment++;
            }
            
        }
        
//        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_Trial.png", Output_Image);
        
    }
    
    return test;
}













//
//Mat Mask_Laplacian123 (Mat kernel_vertical, Mat image) {
//    
//    //    VARIABLES DECLARATION
//    Mat Laplacian_output123;
//    
//    int row_limit = kernel_vertical.rows - 1; int move_along_rows = 0;
//    int row_image = 0; int padding_row;
//    int row_kernel = 0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int column_kernel = 0; int move_along_columns = 0;
//    int column_limit = kernel_vertical.cols - 1; int column; int padding_column;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable = 1; int sum=0; int storage[9] = {}, index=0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    
//    padding_column = image.cols/*size of the pic_column*/ - kernel_vertical.cols/*size of the filter_column*/ + 1; // Find the new number of columns
//    padding_row = image.rows/*size of the pic_row*/ - kernel_vertical.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
//    
//    vector<int> new_matrixVal;
//    
//    
//BEGINNING:
//    for(column = move_along_columns; column < image.cols /*number of columns*/; column++) { // Columns
//        
//        
//        storage[index] = image.at<uint8_t>(row_image,column) * kernel_vertical.at<int>(row_kernel,column_kernel); // Same the Multiplication values
//        
//        if(column == column_limit) {
//            if (row_image == row_limit) {
//                
//                for (int a = 0; a <  9 /*number of values in the kernel*/; a++) { //sum everything in storage variable
//                    sum += storage[a];
//                }
//                
//                new_matrixVal.push_back(sum); // Adds the new pixel of the new matrix to the end of the array
//                index = 0; row_kernel = 0; column_kernel = 0; sum=0;// Reset to 0 the index, sum, column_kernel and row_kernel values
//                
//                goto SHIFTER;
//            }
//            row_image++; // Move to the next row
//            row_kernel++;
//            column = move_along_columns;
//            column_kernel = 0;
//            index++;
//            goto BEGINNING;
//        }
//        index++; // Increments index for different positions in storage
//        column_kernel++;
//    }
//    
//SHIFTER: // Shift along the columns
//    if(padding_variable < padding_column) { // To move along the columns
//        
//        move_along_columns++; // Move to the next column
//        row_image = move_along_rows; // Set row to the value of move_along_rows;
//        padding_variable++;
//        column_limit++;
//        
//        goto BEGINNING;
//        
//    } else if((padding_variable == padding_column) && (move_along_rows != padding_row)) { // To move along the rows
//        
//        move_along_rows++; // Move to the next row
//        row_limit++;
//        row_image = move_along_rows;
//        move_along_columns = 0; // Reset move_along_columns to 0
//        padding_variable = 1; // Reset padding_variable to 1
//        column_limit = kernel_vertical.cols - 1; // Reset column_limit to 2
//        
//        goto BEGINNING;
//    } else if( (padding_variable == padding_column) && (move_along_rows == padding_row) ) { // Check if that is the last element of the matrix in  order to finish the program
//        
//        Laplacian_output123 = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                Laplacian_output123.at<int16_t>(f,j) =  new_matrixVal[increment];
//                increment++;
//            }
//
//        }
//        
//        
//        
//        if( controller123 == 0) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_output.png", Laplacian_output123);
//        } else if( controller123 == 1) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_Gaussian_output.png", Laplacian_output123);
//        }
//        
//        controller123++;
//        
//    }
//    
//    return Laplacian_output123;
//    
//}