//
//  canny.cpp
//  Image Processing
//
//  Created by Magno Carlos on 14/02/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "canny.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Gaussian.hpp"
#include "Gradient.hpp"

using namespace std;
using namespace cv;

int i4 = 0;
Mat test2;
Mat bar;
int Thre_Low = 90;
const int Thre_High = 150;

float maior2(float numero_1, float numero_2, float numero_3 ) {
    float temp = 0.0;
    float array[3] = {numero_1, numero_2, numero_3};
    
    for(int i=0; i < 3; i++) {
        
        if(array[i] > temp)
            temp=array[i];
    }
    
    return temp;
}


void CannyThreshold2(int, void*) {

    
    imshow( "Edge Map",  Hysteresis(test2) );
}


Mat directionX(Mat xdirection, Mat ydirection) {
    Mat x_conversion, y_conversion;
    Mat output_image_X = Mat(xdirection.rows,xdirection.cols, CV_32F, Scalar::all(0) );
    int a, b, c, d, e, f, g, k, l;
    Mat test = Pythagoras_NMS( xdirection, ydirection );
    test2 = Pythagoras_NMS( xdirection, ydirection );
    Mat output_image_Y = Mat(ydirection.rows,ydirection.cols, CV_16S, Scalar::all(0) );
    float degree_orientationX = 0.0 ;
    float PI = 3.141592654;
    xdirection.convertTo(x_conversion, CV_32F, 1/*scale value 0.125*/); // converts gx to float
    ydirection.convertTo(y_conversion, CV_32F, 1/*scale value 0.125*/); // converts gy to float
    
    
    for(int i=0; i<test.rows; i++) { // loop for the x axis
        
        for(int j=0; j<test.cols; j++) {
            
            a = test.at<int>(i,j);
            b = test.at<int>(i,j+1); // 0
            c = test.at<int>(i,j-1); // 0
            d = test.at<int>(i+1,j+1); // 135
            e = test.at<int>(i-1,j-1); // 135
            f = test.at<int>(i+1,j); // 90
            g = test.at<int>(i-1,j); // 90
            k = test.at<int>(i-1,j+1); // 45
            l = test.at<int>(i+1,j-1); // 45
            
            if (x_conversion.at<float>(i,j) != 0) { // to avoid y_conversion/x_conversion = 0/0
                degree_orientationX = atan( y_conversion.at<float>(i,j) / x_conversion.at<float>(i,j) ) * 180/PI  ;
//                cout << "valor da orientationt " << degree_orientationX << endl;
                
                
                if( ((degree_orientationX <= 180.0   && degree_orientationX >= 157.5) || (degree_orientationX <= 22.5 && degree_orientationX >= 0.0)) /*|| ((degree_orientationY >= -180.0   && degree_orientationY <= -157.5) || (degree_orientationY >= -22.5 && degree_orientationY <= 0.0))*/) { // maps 0
                    
                    
                    test2.at<float>(i,j) = maior2(a, b, c);
                    
                    if (test2.at<float>(i,j) == a) {
                        
                        test2.at<float>(i,j+1) = 0;
                        test2.at<float>(i,j-1) = 0;
                        
                    } else if (test2.at<float>(i,j) == b) {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i,j-1) = 0;
                        
                    } else {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i,j+1) = 0;
                    }
                    
                    
                }  if( (degree_orientationX < 157.5   && degree_orientationX >= 112.5) /*|| (degree_orientationX > -157.5 && degree_orientationX <= -112.5)*/ ) { // maps 135
                    
                    test2.at<float>(i,j) = maior2(a, d, e);
                    
                    if (test2.at<float>(i,j) == a) {
                        
                        test2.at<float>(i+1,j+1) = 0;
                        test2.at<float>(i-1,j-1) = 0;
                        
                    } else if (test2.at<float>(i,j) == d) {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i-1,j-1) = 0;
                        
                    } else {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i+1,j+1) = 0;
                    }
                    
                    
                }  if( (degree_orientationX < 112.5 && degree_orientationX >= 67.5) /*|| (degree_orientationX > -112.5 && degree_orientationX < -67.5)*/ ) { // maps 90
                    
                    test2.at<float>(i,j) = maior2(a, f, g);
                    
                    
                    if (test2.at<float>(i,j) == a) {
                        
                        test2.at<float>(i+1,j) = 0;
                        test2.at<float>(i-1,j) = 0;
                        
                    } else if (test2.at<float>(i,j) == f) {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i-1,j) = 0;
                        
                    } else {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i+1,j) = 0;
                    }
                    
                    
                }  if( (degree_orientationX < 67.5 && degree_orientationX > 22.5) /*|| (degree_orientationX > -67.5 && degree_orientationX < -22.5)*/ ) { // maps 45
                    
                    test2.at<float>(i,j) = maior2(a, k, l);
                    
                    if (test2.at<float>(i,j) == a) {
                        
                        test2.at<float>(i-1,j+1) = 0;
                        test2.at<float>(i+1,j-1) = 0;
                        
                    } else if (output_image_X.at<float>(i,j) == k) {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i+1,j-1) = 0;
                        
                    } else {
                        
                        test2.at<float>(i,j) = 0;
                        test2.at<float>(i-1,j+1) = 0;
                    }
                    
                    
                }
                
                
            } else if( (x_conversion.at<float>(i,j) == 0) && (y_conversion.at<float>(i,j) == 0) ) {
                
                degree_orientationX = 0;
                test2.at<float>(i,j) = maior2(a, b, c);
                
                if (test2.at<float>(i,j) == a) {
                    
                    test2.at<float>(i,j+1) = 0;
                    test2.at<float>(i,j-1) = 0;
                    
                } else if (test2.at<float>(i,j) == b) {
                    
                    test2.at<float>(i,j) = 0;
                    test2.at<float>(i,j-1) = 0;
                    
                } else {
                    
                    test2.at<float>(i,j) = 0;
                    test2.at<float>(i,j+1) = 0;
                }
                
            } else if( (x_conversion.at<float>(i,j) == 0) && (y_conversion.at<float>(i,j) != 0) ) {
                
                degree_orientationX = 90;
                test2.at<float>(i,j) = maior2(a, f, g);
                
                if (test2.at<float>(i,j) == a) {
                    
                    test2.at<float>(i+1,j) = 0;
                    test2.at<float>(i-1,j) = 0;
                    
                } else if (test2.at<float>(i,j) == f) {
                    
                    test2.at<float>(i,j) = 0;
                    test2.at<float>(i-1,j) = 0;
                    
                } else {
                    
                    test2.at<float>(i,j) = 0;
                    test2.at<float>(i+1,j) = 0;
                }
            }
            
        }
        
    }
    
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_testando_xdirection.png", test2);
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/preto.png", output_image_X);
//    Hysteresis(test2);
    createTrackbar( "Min Threshold: 0 ", "Edge Map", &Thre_Low, Thre_High, CannyThreshold2 );
    CannyThreshold2(0, 0);
    waitKey(0);
    
    return test2;
}


////////////////////////////////////////################## D I R E C T I O N ####################/////////////////////////////////////

Mat Hysteresis(Mat ted) {
    
    Mat t_res = Mat(ted.rows,ted.cols, CV_32F, Scalar::all(0) );
    t_res = ted;
    Mat gf = Mat(ted.rows,ted.cols, CV_8U, Scalar::all(0) );
//    int Thre_Low = 90;
//    int Thre_High = 100;
   
    for(int i=0; i<ted.rows; i++) { // loop for the y axis
        
        for(int j=0; j<ted.cols; j++) {
            
            if (ted.at<float>(i,j) < Thre_Low) {
                
                t_res.at<float>(i,j) = 0;
                
            } else if (ted.at<float>(i,j) > Thre_High) {
                
                t_res.at<float>(i,j) = 1;
                
            } else if(ted.at<float>(i+1,j)>Thre_High || ted.at<float>(i-1,j)>Thre_High || ted.at<float>(i,j+1)>Thre_High || ted.at<float>(i,j-1)>Thre_High || ted.at<float>(i-1, j-1)>Thre_High || ted.at<float>(i-1, j+1)>Thre_High || ted.at<float>(i+1, j+1)>Thre_High || ted.at<float>(i+1, j-1)>Thre_High) {
                
                t_res.at<float>(i,j) = 1;
            }
            
        }
        
    }
    
    
    for (int i = 0; i < t_res.rows; i++) {
        
        for (int j = 0; j < t_res.cols; j++) {
            gf.at<uint8_t>(i,j) = t_res.at<float>(i,j) * 255;
        }
    }
    
    createTrackbar( "Min Threshold: 0 ", "Edge Map", &Thre_Low, Thre_High, CannyThreshold2 );
    CannyThreshold2(0, 0);
    waitKey(0);
//    imshow("sd", gf);
//    waitKey(0);
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/hysteresis.png", t_res);
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/hysteresisLast.png", gf);
    return t_res;
}


///////////////////////////////////////////////############### M A I N  O N E ######################////////////////////////////////////////

Mat Canny__trial_vertical(Mat kernel_vertical, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat canny_output_y;
    
    
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
    
    canny_output_y = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            canny_output_y.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_output_y.png", canny_output_y);

    return canny_output_y;
    
    
}

////////////////////////////////////////################## H O R I Z O N T A L ####################/////////////////////////////////////

Mat Canny__trial_horizontal(Mat kernel_horizontal, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat canny_output_x;
    
    
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
    
    canny_output_x = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            canny_output_x.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_output_x.png", canny_output_x);
    
    return canny_output_x;
    
}















//
///////////////////////////////////////////////################## V E R T I C A L ####################//////////////////////////////////////////
//
//Mat Canny__trial_vertical(Mat g_filter, Mat image) {
//    //    VARIABLES DECLARATION
//    Mat canny_output_y;
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
//        storage[index] = (image.at<uint16_t>(row_image,column) * g_filter.at<int>(row_kernel,column_kernel)) / Sum_of_Matrix(); // Same the Multiplication values
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
//        //        int controller = padding_row * padding_column;
//        //
//        //        for(int i=0; i < controller; i++) {
//        //
//        //
//        //            cout  << " END OF THE PROGRAM " << " OUTPUT IMAGE " << endl << new_matrixVal[i] << endl << endl;
//        //
//        //        }
//        
//        canny_output_y = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                canny_output_y.at<int16_t>(f,j) =  new_matrixVal[increment];
//                //                cout << vertical_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
//            //            cout << endl;
//        }
//        
//        //        cout << vertical_output << endl;
//        
//        if( i4 == 0) {
////            cout << canny_output_y.size << endl;
////            cout << "canny vertical ysize " << canny_output_y.size << endl;
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_Output_Y.png", canny_output_y);
//            
//        } else if( i4 == 1) {
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_Output_Y_Noisy.png", canny_output_y);
//        }
//        
//        i4++;
////        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_Output_y.png", canny_output_y);
//        
//    }
//    
//    return canny_output_y;
//}
//
//////////////////////////////////////////################## H O R I Z O N T A L ####################/////////////////////////////////////
//
//Mat Canny__trial_horizontal(Mat g_filter, Mat image) {
//    //    VARIABLES DECLARATION
//    Mat canny_output_x;
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
//        storage[index] = (image.at<uint16_t>(row_image,column) * g_filter.at<int>(row_kernel,column_kernel)) / Sum_of_Matrix(); // Same the Multiplication values
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
//        //        int controller = padding_row * padding_column;
//        //
//        //        for(int i=0; i < controller; i++) {
//        //
//        //
//        //            cout  << " END OF THE PROGRAM " << " OUTPUT IMAGE " << endl << new_matrixVal[i] << endl << endl;
//        //
//        //        }
//        
//        canny_output_x = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//            
//            for(int j = 0;j < padding_column;j++) {
//                canny_output_x.at<int16_t>(f,j) =  new_matrixVal[increment];
//                //                cout << vertical_output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
//            //            cout << endl;
//        }
//        
//        //        cout << vertical_output << endl;
//        
//        if( i4 == 0) {
////            cout << canny_output_x << endl;
////            cout << "canny horizontal xsize " << canny_output_x.size << endl;
//            
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_Output_X.png", canny_output_x);
//            
//        } else if( i4 == 1) {
//
//            imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_Output_X_Noisy.png", canny_output_x);
//        }
////        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/canny_Output_x.png", canny_output_x);
//        
//    }
//    
//    return canny_output_x;
//}
//
//
//
//
//
