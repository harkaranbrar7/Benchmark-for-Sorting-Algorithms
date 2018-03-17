//
//  main.cpp
//  115
//
//  Created by Harkaran Brar on 3/3/18.
//  Copyright © 2018 Harkaran Brar. All rights reserved.
//
//
// main function which calls the other function to simulate and generate the results
// Results will be written to excel file which is easier to read
// For sorting algorithms test on different length
// LengthCounter is setup for length with power function
// Length 1 = 10, 2 = 100 , 3 = 1000, 4 = 10000 , 5 = 100000 , 6 = 1000000 respectively
// For different types of array generation typOfArr_Count is setup
// typOfArr_Count 0 = Sorted, 1 = Shuffled , 2 = Reverse , 3 = Tenpercent respectively
// For different types of sorting algorithms SortAL_Count counter is setup
// SortAL_Count 0 = Selection , 1 = Insertion , 2 = Bubble , 3 = Merge , 4 = Quick


#include "Algorithms.h"                 // Header file
#include <iostream>
#include <cmath>                        // For Power Function
#include <fstream>                      // For Output File

using namespace std;

int main(int argc, char *argv[])
{
    int InitialLength = 10;                 // Initial length for algorithm
    int arrayLength;                        // Length of array
    double duration;                        // Time taken by algorithm
    string arrayName,ordeR, sorT;           // String for Storing orders
    
    ofstream MyExcelFile;                   // For output file
    MyExcelFile.open("test.csv");           // Open the Excel file
    
    clock_t Clock_Start;                    // For starting time
    clock_t Clock_End;                      // For end time
    clock_t clockTicksTaken;                // For time taken
    
    
    Algorithms SORT(InitialLength);         // Call to class

    MyExcelFile.precision(5);               // Precision for output data

    
    // Length counter for getting different length
    for (int lengthCount = 1; lengthCount <= 6; lengthCount++)
    {
        arrayLength = pow(10, lengthCount);    // Getting an array length power function 10^lenghtCount
        MyExcelFile<<endl<<endl<<endl<<","<<","<<","<<","<<"Length of Array = " <<arrayLength<<endl<<endl;
        for (int SortAL_Count = 0; SortAL_Count <= 4; SortAL_Count++) // Counter for Sorting algorithms
        {
            MyExcelFile<<endl<<endl;    // End line in excel file to get data get its column
            for (int typOfArr_Count = 0; typOfArr_Count <= 3; typOfArr_Count++) // Counter for Array Types
            {
                switch (typOfArr_Count) {
                    case 0:
                        ordeR = "Sorted ";
                        break;
                    case 1:
                        ordeR = "Shuffled ";
                        break;
                    case 2:
                        ordeR = "Reverse ";
                        break;
                    case 3:
                        ordeR = "TenPercent ";
                        break;
                    default:
                        cout << "Error" << endl;
                        exit(0);
                        break;
                };


                switch (SortAL_Count)
                {
                    case 0:
                        sorT = "Selection";
                        break;
                    case 1:
                        sorT = "Insertion";
                        break;
                    case 2:
                        sorT = "Bubble";
                        break;
                    case 3:
                        sorT = "Merge";
                        break;
                    case 4:
                        sorT = "Quick";
                        break;
                    default:
                        cout << "Error" << endl;
                        exit(0);
                        break;
                };

                arrayName = sorT +" "+ ordeR;                              // get array name by concat both
                cout << endl << "****************************************************************" << endl;
                cout << arrayName <<" "<<arrayLength<< endl;
                MyExcelFile<<endl<<endl<< arrayName <<" "<<arrayLength<<",";   // Write name array name to file
                cout << "****************************************************************" << endl << endl;
                
                for (int counter = 0; counter <= 99; counter++)         // For loop runs 100 times
                {
                    switch (typOfArr_Count)
                    {
                        case 0:
                            SORT.Sorted_Array(arrayLength);             // Get Sorted Array
                            break;
                        case 1:
                            SORT.Random_Array(arrayLength);             // Random Array
                            break;
                        case 2:
                            SORT.Reverse_Sorted_Array(arrayLength);     // Reverse Sorted Array
                            break;
                        case 3:
                            SORT.Partially_Sorted_Array(arrayLength);    // Partially Sorted 10% Shuffled
                            break;
                        default:
                            cout << "Error" << endl;
                            exit(0);
                            break;
                    };


                    switch (SortAL_Count) {
                        case 0:
                            Clock_Start = clock();                      // To get start time
                            SORT.selectionSort();
                            Clock_End = clock();                        // To get end time
                            break;
                        case 1:
                            Clock_Start = clock();
                            SORT.insertionSort();
                            Clock_End = clock();
                            break;
                        case 2:
                            Clock_Start = clock();
                            SORT.bubbleSort();
                            Clock_End = clock();
                            break;
                        case 3:
                            Clock_Start = clock();
                            SORT.mergeSort(0, SORT.getSize() - 1);
                            Clock_End = clock();
                            break;
                        case 4:
                            Clock_Start = clock();
                            SORT.quickSort(0, SORT.getSize() - 1);
                            Clock_End = clock();
                            break;
                        default:
                            cout << "Error" << endl;
                            exit(0);
                            break;
                    };
                        clockTicksTaken = Clock_End - Clock_Start;              // Get time taken by algorithm
                        duration = clockTicksTaken /(double) CLOCKS_PER_SEC;    // Get time in seconds
                        cout <<duration<< endl;
                        MyExcelFile << duration << ",";                         // Write to file each row
                }
            }
        }
    }
     MyExcelFile.close();                           // To close file

    return 0;
}

