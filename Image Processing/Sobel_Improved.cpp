//
//  Sobel_Improved.cpp
//  Image Processing
//
//  Created by Magno Carlos on 07/04/2019.
//  Copyright © 2019 C3R3BROMagno. All rights reserved.
//

#include "Sobel_Improved.hpp"
#include <iostream>
#include <vector>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;


Mat Mask_0(Mat kernel_vertical, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_0;
    
    
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
    
    output_0 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_0.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    cout<<output_0.size<<endl;
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_0.png", output_0);
    
    return output_0;
    
    
}

////////////////////////////////////////################## 4 5 ####################/////////////////////////////////////

Mat Mask_45(Mat kernel_horizontal, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_45;
    
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
    
    output_45 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_45.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_45.png", output_45);
    cout<<output_45.size<<endl;
    return output_45;
    
}

////////////////////////////////////////################## 9 0 ####################/////////////////////////////////////
Mat Mask_90(Mat kernel_vertical, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_90;
    
    
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
    
    output_90 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_90.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_90.png", output_90);
    cout<<output_90.size<<endl;
    return output_90;
    
    
}

////////////////////////////////////////################## 1 3 5 ####################/////////////////////////////////////

Mat Mask_135(Mat kernel_horizontal, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_135;
    
    
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
    
    output_135 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_135.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_135.png", output_135);
    
    return output_135;
    
}

////////////////////////////////////////################## 1 8 0 ####################/////////////////////////////////////
Mat Mask_180(Mat kernel_vertical, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_180;
    
    
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
    
    output_180 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_180.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_180.png", output_180);
    cout<<output_180.size<<endl;
    return output_180;
    
    
}

////////////////////////////////////////################## 2 2 5 ####################/////////////////////////////////////

Mat Mask_225(Mat kernel_horizontal, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_225;
    
    
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
    
    output_225 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_225.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_225.png", output_225);
    cout<<output_225.size<<endl;
    return output_225;
    
}

////////////////////////////////////////################## 2 7 0 ####################/////////////////////////////////////
Mat Mask_270(Mat kernel_vertical, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_270;
    
    
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
    
    ///////////////////////////////////////################## 2 7 0 ####################///////////////////////////////////
    
    output_270 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_270.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_270.png", output_270);
    cout<<output_270.size<<endl;
    return output_270;
    
    
}

////////////////////////////////////////################## 3 1 5 ####################/////////////////////////////////////

Mat Mask_315(Mat kernel_horizontal, Mat image) {
    
    
    //    VARIABLES DECLARATION
    
    
    Mat output_315;
    
    
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
    
    output_315 = Mat(padding_row,padding_column, depth /*image.type()*//* CV_16S double check this type*/);
    int increment=0;
    for(int f = 0;f < padding_row;f++) {
        
        for(int j = 0;j < padding_column;j++) {
            output_315.at< int16_t /*int16_t*/>(f,j) =  new_matrixVal[increment];
            
            increment++;
        }
        //            cout << endl;
    }
    
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Sobel_315.png", output_315);
    cout<<output_315.size<<endl;
    return output_315;
    
}

