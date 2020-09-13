//
//  Gaussian.cpp
//  Image Processing
//
//  Created by Magno Carlos on 01/03/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Gaussian.hpp"
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;


void Median_Filter(Mat image) { // calc the middle value of a 3x3 matrix and replace the noisy pixel
    cout;
    //
}





Mat gaussian_kernel = (Mat_<int>(3,3) << 1, 2, 1,
                                         2, 4, 2,
                                         1, 2, 1);
int i2 = 0;

int Sum_of_Matrix() { // Returns the sum of the values in the matrix
    
    int sum_result = 0;
    for (int i = 0; i < gaussian_kernel.rows; i++) {
        
        for (int j =0; j < gaussian_kernel.cols; j++) {
            sum_result += gaussian_kernel.at<int>(i,j);
        }
        
    }
    
    return sum_result;
    
}






Mat Gaussian__Filter(Mat g_filter, Mat image) {
    //    VARIABLES DECLARATION
    Mat gaussian_output;
    
    int padding_row;
    int row_img_incrementer = 0;
    int padding_column;
    int column_img_incrementer = 0;
    int sum=0; int storage[9] = {}, index=0;
    int padding_counter = 0;
    ////////////////////////////////////////////////////#####################################//////////////////////////////////////////
    
    
    padding_column = image.cols/*size of the pic_column*/ - g_filter.cols/*size of the filter_column*/ + 1; // Find the new number of columns
    padding_row = image.rows/*size of the pic_row*/ - g_filter.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
    
    vector<int> new_matrixVal;
    
    for (int row_image = 0; row_image < image.rows /*number of rows*/; row_image++) { // image rows loop
        
        row_img_incrementer = row_image;
        
        for (int column_image = 0; column_image < image.cols; column_image++) { // image columns loop
            
            column_img_incrementer = column_image;
            
            for (int row_kernel = 0; row_kernel < g_filter.rows; row_kernel++) { // kernel rows loop
                
                for (int column_kernel = 0; column_kernel < g_filter.cols; column_kernel++) { // kernel columns loop
                    
                    storage[index] = image.at<uint8_t /*uint8_t*/>(row_img_incrementer,column_img_incrementer) * g_filter.at<int>(row_kernel,column_kernel)  / Sum_of_Matrix(); // Same the Multiplication values
                    
                    //                    cout << "storage = " << image.at<int>(row_img_incrementer,column_img_incrementer) << " * " << kernel_lap.at<int>(row_kernel,column_kernel) << " = " << storage[index] << endl;
                    
                    column_img_incrementer ++;
                    index++;
                } // end kernel columns loop
                
                row_img_incrementer++;
                column_img_incrementer = column_image;
            } // end kernel rows loop
            
            for (int a = 0; a <  9 /*number of values in the kernel*/; a++) { // sum everything in the storage variable
                sum += storage[a];
            }
            //            cout << "sum = " << sum << endl;
            new_matrixVal.push_back(sum); // Adds the new pixel of the new matrix to the end of the array
            index = 0; sum=0;// Reset to 0 the index, sum, column_kernel and row_kernel values
            
            padding_counter++;
            if( padding_counter == padding_column) {
                padding_counter = 0;
                break;
            }
            
            row_img_incrementer = row_image;
            
        } // end image columns loop
        
    } // end image rows loop
    
    ///////////////////////////////////////################## O U T P U T ####################///////////////////////////////////
    
    gaussian_output = Mat(padding_row,padding_column, CV_8U /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            gaussian_output.at< int8_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    
    if( i2 == 0) {
        
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Gaussian_Output.png", gaussian_output);
        
    } else if( i2 == 1) {
        
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Gaussian_Output_Noisy.png", gaussian_output);
    }
                
    i2++;
    

    return gaussian_output;
}








////////////////////////////////////////////################## G A U S S I A N ####################/////////////////////////////////////

//Mat Gaussian__Filter(Mat g_filter, Mat image) {
//    //    VARIABLES DECLARATION
//    Mat gaussian_output;
//    
//    int row_limit = g_filter.rows - 1; int move_along_rows = 0;
//    int row_image = 0; int padding_row;
//    int row_kernel = 0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int column_kernel = 0; int move_along_columns = 0;
//    int column_limit = g_filter.cols - 1; int column; int padding_column;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable = 1; int sum=0; int storage[9] = {}, index=0, b=0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    
//    padding_column = image.cols/*size of the pic_column*/ - g_filter.cols/*size of the filter_column*/ + 1; // Find the new number of columns
//    padding_row = image.rows/*size of the pic_row*/ - g_filter.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
//    
//    vector<int> new_matrixVal;
//    vector<int> storage1;
//    
//    
//BEGINNING:
//    for(column = move_along_columns; column < image.cols /*number of columns*/; column++) { // Columns
//        
//        
//        storage[index] = (image.at<uint8_t>(row_image,column) * g_filter.at<int>(row_kernel,column_kernel)) / Sum_of_Matrix(); // Same the Multiplication values
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
//                b++;
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
//        column_limit = g_filter.cols - 1; // Reset column_limit to 2
//        
//        goto BEGINNING;
//    } else if( (padding_variable == padding_column) && (move_along_rows == padding_row) ) { // Check if that is the last element of the matrix in  order to finish the program
//       
//        gaussian_output = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                gaussian_output.at<int16_t>(f,j) =  new_matrixVal[increment];
//                //                cout << vertical_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
//            //            cout << endl;
//        }
//        
//        //        cout << vertical_output << endl;
//        if( i2 == 0) {
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Gaussian_Output.png", gaussian_output);
//            
//        } else if( i2 == 1) {
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Gaussian_Output_Noisy.png", gaussian_output);
//        }
//        
//        i2++;
//        
//    }
//    
//    return gaussian_output;
//}

