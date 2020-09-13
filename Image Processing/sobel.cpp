//
//  sobel.cpp
//  Image Processing
//
//  Created by Magno Carlos on 14/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "sobel.hpp"
#include <iostream>
#include <vector>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int i3 = 0;



///////////////////////////////////////////////############### M A I N  O N E ######################////////////////////////////////////////

Mat Mask_Vertical(Mat kernel_vertical, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat vertical_output;
    

    int padding_row;
    int row_img_incrementer = 0;
    int padding_column;
    int column_img_incrementer = 0;
    int sum=0; int storage[9] = {}, index=0;
    int padding_counter = 0;
    int depth = CV_16S;
    
    ////////////////////////////////////////////////////#####################################//////////////////////////////////////////
    
    padding_column = image.cols/*size of the pic_column*/ - kernel_vertical.cols/*size of the filter_column*/ + 1; // Find the new number of columns
    padding_row = image.rows/*size of the pic_row*/ - kernel_vertical.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
    
    vector<int> new_matrixVal;
    
    for (int row_image = 0; row_image < image.rows /*number of rows*/; row_image++) { // image rows loop
    
        row_img_incrementer = row_image;
    
        for (int column_image = 0; column_image < image.cols; column_image++) { // image columns loop
    
            column_img_incrementer = column_image;
    
            for (int row_kernel = 0; row_kernel < kernel_vertical.rows; row_kernel++) { // kernel rows loop
    
                for (int column_kernel = 0; column_kernel < kernel_vertical.cols; column_kernel++) { // kernel columns loop
    
                    storage[index] = image.at<uint8_t /*uint8_t*/>(row_img_incrementer,column_img_incrementer) * kernel_vertical.at<int>(row_kernel,column_kernel); // Same the Multiplication values
    
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
    
    vertical_output = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
    
        for(int j = 0;j < padding_column;j++) {
            vertical_output.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
    
            increment++;
        }
            //            cout << endl;
    }
        
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_Y_New.png", vertical_output);
        
    return vertical_output;
    
    
}

////////////////////////////////////////################## H O R I Z O N T A L ####################/////////////////////////////////////

Mat Mask_Horizontal(Mat kernel_horizontal, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat horizontal_output;
    
    
    int padding_row;
    int row_img_incrementer = 0;
    int padding_column;
    int column_img_incrementer = 0;
    int sum=0; int storage[9] = {}, index=0;
    int padding_counter = 0;
    int depth = CV_16S;
    ////////////////////////////////////////////////////#####################################//////////////////////////////////////////
    
    
    padding_column = image.cols/*size of the pic_column*/ - kernel_horizontal.cols/*size of the filter_column*/ + 1; // Find the new number of columns
    padding_row = image.rows/*size of the pic_row*/ - kernel_horizontal.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
    
    vector<int> new_matrixVal;
    
    for (int row_image = 0; row_image < image.rows /*number of rows*/; row_image++) { // image rows loop
        
        row_img_incrementer = row_image;
        
        for (int column_image = 0; column_image < image.cols; column_image++) { // image columns loop
            
            column_img_incrementer = column_image;
            
            for (int row_kernel = 0; row_kernel < kernel_horizontal.rows; row_kernel++) { // kernel rows loop
                
                for (int column_kernel = 0; column_kernel < kernel_horizontal.cols; column_kernel++) { // kernel columns loop
                    
                    storage[index] = image.at<uint8_t /*uint8_t*/>(row_img_incrementer,column_img_incrementer) * kernel_horizontal.at<int>(row_kernel,column_kernel); // Same the Multiplication values
                    
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
    
    horizontal_output = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            horizontal_output.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_X_New.png", horizontal_output);
    
    return horizontal_output;
    
}

















/////////////////////////////////////////////################## First Attempt ####################///////////////////////////////////////////
//
//Mat Mask_Vertical(Mat kernel_vertical, Mat image) {
//    
//    //    VARIABLES DECLARATION
//    Mat vertical_output;
//    
//    int row_limit = kernel_vertical.rows - 1; int move_along_rows = 0;
//    int row_image = 0; int padding_row;
//    int row_kernel = 0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int column_kernel = 0; int move_along_columns = 0;
//    int column_limit = kernel_vertical.cols - 1; int column; int padding_column;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable = 1; int sum=0; int storage[9] = {}, index=0, b=0;
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
//        storage[index] = (image.at<uint8_t>(row_image,column) * kernel_vertical.at<int>(row_kernel,column_kernel)) /8; // Same the Multiplication values
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
//        column_limit = kernel_vertical.cols - 1; // Reset column_limit to 2
//        
//        goto BEGINNING;
//    } else if( (padding_variable == padding_column) && (move_along_rows == padding_row) ) { // Check if that is the last element of the matrix in  order to finish the program
//        
//
//        
//        vertical_output = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                vertical_output.at<int16_t>(f,j) =  new_matrixVal[increment];
////                cout << vertical_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
////            cout << endl;
//        }
//        
////        cout << vertical_output << endl;
//        
//        if( i3 == 0) {
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_Y.png", vertical_output);
//            
//        } else if( i3 == 1) {
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_Y_Noisy.png", vertical_output);
//        }
//        
//        i3++;
//       
//    }
//    
//    return vertical_output;
//    
//}
//
//////////////////////////////////////////################## H O R I Z O N T A L ####################/////////////////////////////////////
//
//Mat Mask_Horizontal(Mat kernel_horizontal, Mat image) {
//    
//    
//    //    VARIABLES DECLARATION
//    Mat horizontal_output;
//    
//    int row_limit = kernel_horizontal.rows - 1; int move_along_rows = 0;
//    int row_image = 0; int padding_row;
//    int row_kernel = 0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int column_kernel = 0; int move_along_columns = 0;
//    int column_limit = kernel_horizontal.cols - 1; int column, padding_column;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable = 1; int sum=0; int storage2[9] = {}, index=0, b=0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    
//    padding_column = image.cols/*size of the pic_column*/ - kernel_horizontal.cols/*size of the filter_column*/ + 1; // Find the new number of columns
//    padding_row = image.rows/*size of the pic_row*/ - kernel_horizontal.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
//    
//    vector<int> new_matrixVal2;
//    
//    
//BEGINNING2:
//    for(column = move_along_columns; column < image.cols /*number of columns*/; column++) { // Columns
//        
//        
//        storage2[index] = (image.at<uint8_t>(row_image,column) * kernel_horizontal.at<int>(row_kernel,column_kernel)) /8; // Same the Multiplication values
//        
//        if(column == column_limit) {
//            if (row_image == row_limit) {
//                
//                for (int a = 0; a <  9 /*number of values in the kernel*/; a++) { //sum everything in storage variable
//                    sum += storage2[a];
//                }
//                
//                new_matrixVal2.push_back(sum);
//                index = 0; row_kernel = 0; column_kernel = 0; sum=0;// Reset to 0 the index, sum, column_kernel and row_kernel values
//                b++;
//                goto SHIFTER2;
//            }
//            row_image++; // Move to the next row
//            row_kernel++;
//            column = move_along_columns;
//            column_kernel = 0;
//            index++;
//            goto BEGINNING2;
//        }
//        index++; // Increments index for different positions in storage
//        column_kernel++;
//    }
//    
//SHIFTER2: // Shift along the columns
//    if(padding_variable < padding_column) { // To move along the columns
//        
//        move_along_columns++; // Move to the next column
//        row_image = move_along_rows; // Set row to the value of move_along_rows;
//        padding_variable++;
//        column_limit++;
//        
//        goto BEGINNING2;
//        
//    } else if( (padding_variable == padding_column) && (move_along_rows != padding_row) ) { // To move along the rows
//        
//        move_along_rows++; // Move to the next row
//        row_limit++;
//        row_image = move_along_rows;
//        move_along_columns = 0; // Reset move_along_columns to 0
//        padding_variable = 1; // Reset padding_variable to 1
//        column_limit = kernel_horizontal.cols - 1; // Reset column_limit to 2
//        
//        goto BEGINNING2;
//    } else if( (padding_variable == padding_column) && (move_along_rows == padding_row) ) { // Check if that is the last element of the matrix in  order to finish the program
//        
////        int controller = padding_row * padding_column;
////        
////        for(int i=0; i < controller; i++) {
////            
////            
////            cout  << " END OF THE PROGRAM " << " OUTPUT IMAGE " << endl << new_matrixVal2[i] << endl << endl;
////            
////        }
////        
//        horizontal_output = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                horizontal_output.at<int16_t>(f,j) =  new_matrixVal2[increment];
////                cout << horizontal_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
////            cout << endl;
//        }
//        
////        cout << horizontal_output << endl;
//        
//        if( i3 == 0) {
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_X.png", horizontal_output);
//            cout << "channels " << horizontal_output.channels() << endl;
//            cout << "type " << horizontal_output.type() << endl;
//            cout << "depth " << horizontal_output.depth() << endl;
//
//            
//        } else if( i3 == 1) {
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_X_Noisy.png", horizontal_output);
//        }
//        
//
//        
//    }
//    
//    return horizontal_output;
//    
//}

