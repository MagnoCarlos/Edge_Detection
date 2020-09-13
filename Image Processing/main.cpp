//
//  main.cpp
//  Image Processing
//
//  Created by Magno Carlos on 25/11/2018.
//  Copyright © 2018 C3R3BROMagno. All rights reserved.
//

// add a bar to change the threshold level

#include <iostream>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "sobel.hpp"
#include "canny.hpp"
#include "laplacian.hpp"
#include "Loops.hpp"
#include "Gaussian.hpp"
#include "Noise.hpp"
#include "Trial.hpp"
#include "Video_Capture.hpp"
#include "Threshold.hpp"
#include "Gradient.hpp"
#include "Canny2.hpp"
#include "Sobel_Improved.hpp"

using namespace std;
using namespace cv;



int main() {
    
    Mat kernel_vertical = (Mat_<int>(3,3) << -1, 0, 1,
                                             -2, 0, 2,
                                             -1, 0, 1); // Sobel x direction
    
    Mat kernel_horizontal = (Mat_<int>(3,3) << -1, -2, -1,
                                                0,  0,  0,
                                                1,  2,  1); // Sobel Y direction
    
        Mat kernel_0 = (Mat_<int>(3,3) << -1, -2, -1,
                                           0, 0, 0,
                                           1, 2, 1); // Sobel x direction
    
        Mat kernel_45 = (Mat_<int>(3,3) << -2, -1, 0,
                                           -1,  0,  1,
                                            0,  1,  2); // Sobel Y direction
    
        Mat kernel_90 = (Mat_<int>(3,3) << -1, 0, 1,
                                           -2, 0, 2,
                                           -1, 0, 1); // Sobel x direction
    
        Mat kernel_135 = (Mat_<int>(3,3) << 0, 1, 2,
                                           -1, 0, 1,
                                           -2, -1, 0); // Sobel Y direction
    
        Mat kernel_180 = (Mat_<int>(3,3) << 1, 2, 1,
                                            0, 0, 0,
                                           -1, -2, -1); // Sobel x direction
    
        Mat kernel_225 = (Mat_<int>(3,3) << 2,   1,  0,
                                            1,   0,  -1,
                                            0,  -1,  -2); // Sobel Y direction
    
        Mat kernel_270 = (Mat_<int>(3,3) << 1, 0, -1,
                                            2, 0, -2,
                                            1, 0, -1); // Sobel x direction
    
        Mat kernel_315 = (Mat_<int>(3,3) << 0, -1, -2,
                                            1,  0,  -1,
                                            2,  1,  0); // Sobel Y direction
    
    
    
    Mat kernel_Laplacian = (Mat_<int>(3,3) << 1,  1, 1,
                                               1, -8, 1,
                                              1,  1, 1); // Laplacian all directions
    
    Mat improved_kernel_Laplacian = (Mat_<int>(3,3) << -1,  2, -1,
                                                        2, -4, 2,
                                                       -1,  2, -1); // Laplacian all directions

    Mat improved_kernel_Laplacian2 = (Mat_<int>(3,3) << -2,  1, -2,
                                                         1, 4, 1,
                                                        -2,  1, -2); // Laplacian all directions

    
    Mat g_filter = (Mat_<int>(3,3) << 1, 2, 1,
                                      2, 4, 2,
                                      1, 2, 1); // Gaussian filter
    
    Mat img = imread("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Testing_img/Lenna.png", 0); /*The 0 converts it to grayscale*/
    Mat src = imread("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Testing_img/Lenna.png", IMREAD_COLOR); /*The 0 converts it to grayscale*/
    if( !img.data ){ // if no data is received
        return -1;
    }
    
    Mat testando_1, testando_2, testando_3, testando_4, testando_5, testando_6, testando_7, testando_8;
    Mat res;
    Mat filtered_img = Gaussian__Filter( g_filter, img);

//    testando_1 = Mask_0( kernel_0, img);
//    testando_2 = Mask_45( kernel_45, img);
//    testando_3 = Mask_90( kernel_90, img);
//    testando_4 = Mask_135( kernel_135, img);
//    testando_5 = Mask_180( kernel_180, img);
//    testando_6 = Mask_225( kernel_225, img);
//    testando_7 = Mask_270( kernel_270, img);
//    testando_8 = Mask_315( kernel_315, img);
//
//    
//    Improved_Sobel( testando_1, testando_2, testando_3, testando_4, testando_5, testando_6, testando_7, testando_8, img);
    

    //////////////////////////////////////////################## C A M ####################//////////////////////////////////////
//    const int fps = 20;
//    Mat web_frame, Grey_img, lap, filtered_img ; // stores the current frame process it n mve along to the next frame
//    VideoCapture webcamera(0);
//    
//
//    
//    if(!webcamera.isOpened()) {
//                return -1;
//    }
//    
//    while (webcamera.read(web_frame)) {
//        
//        
//        cvtColor(web_frame, Grey_img, COLOR_BGR2GRAY); // convert the RGB to Grayscale
//        Canny_Original( web_frame, g_filter);
////        imshow("camera", Canny_Original( web_frame, g_filter)); // Canny
////        imshow("SOBEL", Pythagoras_NMS( Mask_Horizontal(kernel_horizontal, Grey_img), Mask_Vertical(kernel_vertical, Grey_img) ) ); // Sobel
////        imshow("LAPLACIAN", Mask_Laplacian(kernel_Laplacian, Grey_img) ); // Laplacian
////        waitKey(0); // when key is pressed frame is changed
//        if (waitKey(100 /fps /*if changed to it will be ongoing*/ ) >= 0) { // needs to keep pressing a key in order to change frame
//                   break;
//        }
//    }
    //////////////////////////////////////////################## END CAM ####################//////////////////////////////////////
    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Greyscale.png", img);
    
    //////////////////////////////////////////################## SOBEL ####################//////////////////////////////////////

//    Pythagoras( Mask_Horizontal(kernel_horizontal, filtered_img), Mask_Vertical(kernel_vertical, filtered_img)); // Sobel

    
    //////////////////////////////////////////################## CANNY ####################//////////////////////////////////////
//    Gaussian__Filter( g_filter, img);
    
//    Canny_Original( src, g_filter);
//    Canny__trial_vertical( kernel_vertical, filtered_img);
//    Canny__trial_horizontal( kernel_horizontal, filtered_img);
//    Canny_Mask_Vertical(kernel_vertical, img);
//    Canny_Mask_Horizontal(kernel_horizontal, img);
    directionX(Canny__trial_horizontal( kernel_horizontal, filtered_img), Canny__trial_vertical( kernel_vertical, filtered_img)); // get angle
//    Mat testandoy = direction(Canny__trial_horizontal( kernel_horizontal, filtered_img), Canny__trial_vertical( kernel_vertical, filtered_img)); // get angle
//    Pythagoras( Canny__trial_horizontal( kernel_horizontal, filtered_img), Canny__trial_vertical( kernel_vertical, filtered_img)); // Canny
//    Pythagoras_NMS( Canny__trial_horizontal( kernel_horizontal, filtered_img), Canny__trial_vertical( kernel_vertical, filtered_img));
    //////////////////////////////////////////################## LAPLACIAN ####################//////////////////////////////////////

//    Mask_Laplacian(kernel_Laplacian, img);
//    add( Mask_Laplacian(improved_kernel_Laplacian, img), Mask_Laplacian(improved_kernel_Laplacian2, img), res ); // add the improved Lapl
//    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/summation.png", res);
//    Mask_Laplacian(kernel_Laplacian, filtered_img );
    




    
    
    //////////////////////////////////////////################## N O I S Y ####################//////////////////////////////////////
    
//    Mat noisy = Noise(img);
//    
//    testando_1 = Mask_0( kernel_0, noisy);
//    testando_2 = Mask_45( kernel_45, noisy);
//    testando_3 = Mask_90( kernel_90, noisy);
//    testando_4 = Mask_135( kernel_135, noisy);
//    testando_5 = Mask_180( kernel_180, noisy);
//    testando_6 = Mask_225( kernel_225, noisy);
//    testando_7 = Mask_270( kernel_270, noisy);
//    testando_8 = Mask_315( kernel_315, noisy);
//    
//    Improved_Sobel( testando_1, testando_2, testando_3, testando_4, testando_5, testando_6, testando_7, testando_8, img);

//    Mat noisy_gaussian = Gaussian__Filter( g_filter, noisy);
//    
//

//    
//    Mask_Laplacian(kernel_Laplacian, noisy);
//    //    Mask_Laplacian(kernel_Laplacian, Gaussian__2(g_filter, filtered_img) );
//    
//    
//    Pythagoras( Mask_Horizontal(kernel_horizontal, noisy), Mask_Vertical(kernel_vertical, noisy)); // Sobel
//    Pythagoras( Canny__trial_horizontal( kernel_horizontal, noisy_gaussian), Canny__trial_vertical( kernel_vertical, noisy_gaussian)); // Canny
    
//    imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/Images/Salt Pepper.png", Noise(img));
    
    return 0; //end the program
}
















































////  main.cpp
////  Image Processing
////
////  Created by Magno Carlos on 25/11/2018.
////  Copyright © 2018 C3R3BROMagno. All rights reserved.
////
//
//// add a bar to change the threshold level
//
//#include <iostream>
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main() {
//    
//    Mat kernel = (Mat_<int>(3,3) << -1, 0, 1,
//                                    -2, 0, 2,
//                                    -1, 0, 1);
//    
//    //    VARIABLES DECLARATION
//    Mat image;
//        image = imread("/Users/GreatestBrain/Desktop/Lenna.png", 0); /*The 0 converts it to grayscale*/
//    
//    int row_limit = kernel.rows - 1; int move_along_rows = 0;
//    int row_image = 0; int padding_row;
//    int row_kernel = 0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int column_kernel = 0; int move_along_columns = 0;
//    int column_limit = kernel.cols - 1; int column, padding_column;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    int  padding_variable = 1; int sum=0; int storage[9] = {}, index=0, b=0;
//    //////////////////////////////////////////////#####################################/////////////////////////////////////
//    
//    padding_column = image.cols/*size of the pic_column*/ - kernel.cols/*size of the filter_column*/ + 1; // Find the new number of columns
//    padding_row = image.rows/*size of the pic_row*/ - kernel.rows/*size of the filter_row*/ + 1;  // Find the new number of rows
//
//    int storage_array[260100] = {}; // need to define the size of the array always
//    
//    
//BEGINNING:
//    for(column = move_along_columns; column < image.cols /*number of columns*/; column++) { // Columns
//        
//        
//        storage[index] = image.at<uint8_t>(row_image,column) * kernel.at<int>(row_kernel,column_kernel); // Same the Multiplication values
//        
//        if(column == column_limit) {
//            if (row_image == row_limit) {
//                
//                for (int a = 0; a <  9 /*number of values in the kernel*/; a++) { //sum everything in storage variable
//                    sum += storage[a];
//                }
//                
//                storage_array[b] = sum;
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
//    if( (padding_variable == padding_column) && (move_along_rows == padding_row) ) { // Check if that is the last element of the matrix in order to finish the program
//        int controller = padding_row * padding_column;
//        
//                for(int i=0; i < controller; i++) {
//                    
//        
//                    cout  << " END OF THE PROGRAM " << " OUTPUT IMAGE " << endl << storage_array[i] << endl << endl;
//                  
//                }
//
//        Mat output = Mat(padding_row,padding_column, CV_16S/*double check this type*/);
//        int increment=0;
//        
//        for(int f = 0;f < padding_row;f++) {
//        
//            for(int j = 0;j < padding_column;j++) {
//                output.at<int16_t>(f,j) =  storage_array[increment];
//                cout << output.at<int16_t>(f,j) << "  ";
//                increment++;
//            }
//            cout << endl;
//        }
//    
//        cout << output << endl;
//        imwrite("/Users/GreatestBrain/Documents/MagnoDocs/Dissertation/Coding/Image Processing/Image Processing/output1.png", output);
//        
//        return 0; //end the program
//        
//    } else if(padding_variable < padding_column) { // To move along the columns
//        
//        move_along_columns++; // Move to the next column
//        row_image = move_along_rows; // Set row to the value of move_along_rows;
//        padding_variable++;
//        column_limit++;
//        
//    } else if(padding_variable == padding_column) { // To move along the rows
//        
//        move_along_rows++; // Move to the next row
//        row_limit++;
//        row_image = move_along_rows;
//        move_along_columns = 0; // Reset move_along_columns to 0
//        padding_variable = 1; // Reset padding_variable to 1
//        column_limit = kernel.cols - 1; // Reset column_limit to 2
//    }
//    
//    goto BEGINNING;
//    
//    return 0; //end the program
//}
//


