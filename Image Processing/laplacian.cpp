//
//  laplacian.cpp
//  Image Processing
//
//  Created by Magno Carlos on 14/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "laplacian.hpp"
#include "Trial.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Loops.hpp"


using namespace std;
using namespace cv;


int controller = 0; // variable to control the Laplacian output


Mat Mask_Laplacian (Mat kernel_lap, Mat image) {
    
    
    
    Mat Output_matrix, Laplacian_output;
    
    int padding_row;
    int row_img_incrementer = 0;
    int padding_column;
    int column_img_incrementer = 0;
    int sum=0; int storage[9] = {}, index=0;
    int padding_counter = 0;
    int depth_lap = CV_16S;
    ////////////////////////////////////////////////////#####################################//////////////////////////////////////////
    
    
    padding_column = image.cols/*size of the pic_column*/ - kernel_lap.cols/*size of the filter_column*/ + 1; // Find the new number of columns
    padding_row = image.rows/*size of the pic_row*/ - kernel_lap.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
    
    vector<int> new_matrixVal;
    
    for (int row_image = 0; row_image < image.rows /*number of rows*/; row_image++) { // image rows loop
        
        row_img_incrementer = row_image;
        
        for (int column_image = 0; column_image < image.cols; column_image++) { // image columns loop
            
            column_img_incrementer = column_image;
            
            for (int row_kernel = 0; row_kernel < kernel_lap.rows; row_kernel++) { // kernel rows loop
                
                for (int column_kernel = 0; column_kernel < kernel_lap.cols; column_kernel++) { // kernel columns loop
                    
                    storage[index] = (image.at<uint8_t /*uint8_t*/>(row_img_incrementer,column_img_incrementer) * kernel_lap.at<int>(row_kernel,column_kernel)); // Same the Multiplication values
                    
                    
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
    
    Output_matrix = Mat(padding_row,padding_column, depth_lap /* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            Output_matrix.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];

            increment++;
        }
        //            cout << endl;
    }
    
    // converting back to CV_8U
    convertScaleAbs( Output_matrix, Laplacian_output );
    
    if( controller == 0) {
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Lap_Output_matrix.png", Output_matrix);
        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_output.png", Laplacian_output);
    } //else if( controller == 1) {
//        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Lap_Noisy_Output_matrix.png", Output_matrix);
//        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_Noisy_output.png", Laplacian_output);
//    }
    
    controller++;
    
    
    return Laplacian_output;
    
}


























//
//
//Mat Mask_Laplacian (Mat kernel_vertical, Mat image) {
//
//    //    VARIABLES DECLARATION
//    Mat Laplacian_output;
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
//        storage[index] = image.at<uint8_t /*uint8_t*/>(row_image,column) * kernel_vertical.at<int>(row_kernel,column_kernel); // Same the Multiplication values
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
//        Laplacian_output = Mat(padding_row,padding_column, CV_16S/* CV_16S double check this type*/);
//        int increment=0;
//
//        for(int f = 0;f < padding_row;f++) {
//
//            for(int j = 0;j < padding_column;j++) {
//                Laplacian_output.at<int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
//                //                cout << vertical_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
//            //            cout << endl;
//        }
//
//        //        cout << vertical_output << endl;
//
//        if( controller == 0) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_output.png", Laplacian_output);
//        } else if( controller == 1) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_Gaussian_output.png", Laplacian_output);
//        }
//
//        controller++;
//
//    }
//
//    return Laplacian_output;
//
//}
//




























//void Mask_Laplacian12345 (Mat kernel, Mat image) {
//    
//    //    VARIABLES DECLARATION
//    //    Mat Laplacian_output;
//    int row_limit = kernel.rows - 1;
//    //    int row_image = 0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    //    int move_along_columns = 0;
//    int column_limit = kernel.cols - 1;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable = 1;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    
//    
//    Beginning( kernel, image, /*move_along_columns,*/ column_limit, /*row_image,*/ row_limit, padding_variable);
//    
//    
//    //    return Laplacian_output;
//    
//}







//
//Mat LAP_yebba(Mat kernel_lap, Mat image) {
//    //    VARIABLES DECLARATION
//    Mat Laplacian_output;
//    
//    int row_limit = kernel_lap.rows - 1; int move_along_rows = 0;
//    int row_image = 0; int padding_row;
//    int row_kernel = 0;
//    int row_img_incrementer;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int column_kernel = 0; int move_along_columns = 0; int column_image = 0;
//    int column_limit = kernel_lap.cols - 1; int column; int padding_column; int row;
//    int column_img_incrementer;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable = 1; int sum=0; int storage[9] = {}, index=0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    
//    int row_kernel_reset = 0;
//    int column_kernel_reset = 0;
//    int row_img_reset = 0;
//    int column_img_reset = 0;
//    
//    padding_column = image.cols/*size of the pic_column*/ - kernel_lap.cols/*size of the filter_column*/ + 1; // Find the new number of columns
//    padding_row = image.rows/*size of the pic_row*/ - kernel_lap.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
//    
//    vector<int> new_matrixVal;
//    
//    
//BEGINNING:
//    for(row_image = 0; row_image < image.rows /*number of rows*/; row_image++) { // image rows loop
//        
//        row_img_incrementer = row_image;
//        
//        for (column_image = 0; column_image < image.cols; column_image++) { // image columns loop
//            
//            column_img_incrementer = column_image;
//            
//            for(row_kernel = row_kernel_reset; row_kernel < kernel_lap.rows; row_kernel++) { // kernel rows loop
//                
//                for (column_kernel = column_kernel_reset; column_kernel < kernel_lap.cols; column_kernel++) { // kernel columns loop
//                    
//                    storage[index] = image.at<uint8_t /*uint8_t*/>(row_img_incrementer,column_img_incrementer) * kernel_lap.at<int>(row_kernel,column_kernel); // Same the Multiplication values
//                    column_img_incrementer ++;
//                }
//                row_img_incrementer++;
//            }
//            
//            for (int a = 0; a <  9 /*number of values in the kernel*/; a++) { // sum everything in the storage variable
//                sum += storage[a];
//            }
//            
//            new_matrixVal.push_back(sum); // Adds the new pixel of the new matrix to the end of the array
//            index = 0; row_kernel = 0; column_kernel = 0; sum=0;// Reset to 0 the index, sum, column_kernel and row_kernel values
//            row_img_incrementer = row_image;
//        }
//        
//    }
//    
//    ////////////////////////////////////////################## O U T P U T ####################/////////////////////////////////////
//    
//        Laplacian_output = Mat(padding_row,padding_column, CV_16S/* CV_16S double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                Laplacian_output.at<int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
//                //                cout << vertical_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
//            //            cout << endl;
//        }
//        
//        //        cout << vertical_output << endl;
//        
//        if( controller == 0) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_output.png", Laplacian_output);
//        } else if( controller == 1) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_Gaussian_output.png", Laplacian_output);
//        }
//        
//        controller++;
//        
//    return Laplacian_output;
//}










//
//Mat Mask_Laplacian (Mat kernel_vertical, Mat image) {
//    
//    //    VARIABLES DECLARATION
//    Mat Laplacian_output;
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
//        storage[index] = image.at<uint8_t /*uint8_t*/>(row_image,column) * kernel_vertical.at<int>(row_kernel,column_kernel); // Same the Multiplication values
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
//        Laplacian_output = Mat(padding_row,padding_column, CV_16S/* CV_16S double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                Laplacian_output.at<int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
//                //                cout << vertical_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
//            //            cout << endl;
//        }
//        
//        //        cout << vertical_output << endl;
//        
//        if( controller == 0) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_output.png", Laplacian_output);
//        } else if( controller == 1) {
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Laplacian_Gaussian_output.png", Laplacian_output);
//        }
//        
//        controller++;
//        
//    }
//    
//    return Laplacian_output;
//    
//}