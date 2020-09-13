//
//  Loops.cpp
//  Image Processing
//
//  Created by Magno Carlos on 22/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Loops.hpp"
#include "laplacian.hpp"
#include <iostream>
#include <vector>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;



vector<int> new_matrixVal;
int controller = 0;

int Sum_of_Matrix(Mat input) { // Returns the number used for the averaging
    
    int sum_result = 0;
    for (int i = 0; i < input.rows; i++) {
        
        for (int j =0; j < input.cols; j++) {
            sum_result += input.at<int>(i,j);
        }
        
    }
    
    return sum_result;
    
}
int Sum_of_Array(int input[]) { // Returns the number used for the averaging
    
    int sum_results = 0;
    for (int i = 0; i < 9; i++) {
        
        sum_results += input[i];
        
        
    }
    
    return sum_results;
    
}


void Beginning(Mat receiver_image, Mat kernel_vertical) {
    
    Mat result;
    
    int row_limit = kernel_vertical.rows - 1;
    int row_image = 0; int padding_row;
    int row_kernel = 0;
    //////////////////////////////////////////////#####################################/////////////////////////////////////
    int column_kernel = 0; int move_along_columns = 0;
    int column_limit = kernel_vertical.cols - 1; int column; int padding_column;
    //////////////////////////////////////////////#####################################/////////////////////////////////////
    int sum=0; int index=0, b=0; int storage[9];
    //////////////////////////////////////////////#####################################/////////////////////////////////////
    
    padding_column = receiver_image.cols/*size of the pic_column*/ - kernel_vertical.cols/*size of the filter_column*/ + 1; // Find the new number of columns
    padding_row = receiver_image.rows/*size of the pic_row*/ - kernel_vertical.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
    
BEGINNING:
    for(column = move_along_columns; column < receiver_image.cols /*number of columns*/; column++) { // Columns
        
        
        storage[index] = receiver_image.at<uint8_t>(row_image,column) * kernel_vertical.at<int>(row_kernel,column_kernel); // Save the Multiplication values
        
        if(column == column_limit) {
            if (row_image == row_limit) {
                
                for (int a = 0; a <  9 /*number of values in the kernel*/; a++) { //sum everything in storage variable
                    sum += storage[a];
                }
                new_matrixVal.push_back( sum ); // Adds the new pixel of the new matrix to the end of the array
                index = 0; row_kernel = 0; column_kernel = 0; sum=0;// Reset to 0 the index, sum, column_kernel and row_kernel values
                b++;
                Shifter(receiver_image, kernel_vertical);
            }
            row_image++; // Move to the next row
            row_kernel++;
            column = move_along_columns;
            column_kernel = 0;
            index++;
            goto BEGINNING;
        }
        index++; // Increments index for different positions in storage
        column_kernel++;
    }
    
}


void Shifter(Mat image, Mat kernel) {

    int padding_column, padding_row;
    int row_limit = kernel.rows - 1; int move_along_rows = 0;
    int row_image = 0;
    //////////////////////////////////////////////#####################################/////////////////////////////////////
    int move_along_columns = 0;
    int column_limit = kernel.cols - 1;
    //////////////////////////////////////////////#####################################/////////////////////////////////////
    int  padding_variable = 1;


    padding_column = image.cols/*size of the pic_column*/ - kernel.cols/*size of the filter_column*/ + 1; // Find the new number of columns
    padding_row = image.rows/*size of the pic_row*/ - kernel.rows/*size of the filter_row*/ + 1;  // Find the new number of rows

    if(padding_variable < padding_column) { // To move along the columns

        move_along_columns++; // Move to the next column
        row_image = move_along_rows; // Set row to the value of move_along_rows;
        padding_variable++;
        column_limit++;

        Beginning(image, kernel);

    } else if((padding_variable == padding_column) && (move_along_rows != padding_row)) { // To move along the rows

        move_along_rows++; // Move to the next row
        row_limit++;
        row_image = move_along_rows;
        move_along_columns = 0; // Reset move_along_columns to 0
        padding_variable = 1; // Reset padding_variable to 1
        column_limit = kernel.cols - 1; // Reset column_limit to 2

        Beginning(image, kernel);
    } else if( (padding_variable == padding_column) && (move_along_rows == padding_row) ) { // Check if that is the last element of the matrix in  order to finish the program
        
        
        Mat Laplacian_output = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
        int increment=0;
        
        for(int f = 0;f < padding_row;f++) {
            
            for(int j = 0;j < padding_column;j++) {
                
                Laplacian_output.at<int16_t>(f,j) =  new_matrixVal[increment];
                increment++;
            }
            
        }
        
        if( controller == 0) {
            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_output.png", Laplacian_output);
        } else if( controller == 1) {
            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_Gaussian_output.png", Laplacian_output);
        }
        
        controller++;
        
    }
}


