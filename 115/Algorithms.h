//
//
//  115
//
//  Created by Harkaran Brar on 3/6/18.
//  Copyright © 2018 Harkaran Brar. All rights reserved.
//

#ifndef PROJECT_ALGORITHMS_H
#define PROJECT_ALGORITHMS_H


#include <iostream>
#include <fstream>              // For output file
#include <ctime>                // For clocks
#include <vector>               // For vector
#include <algorithm>

using namespace std;

class Algorithms {
public:
    Algorithms();               // Default Constructor for the class
    Algorithms(int);            // Copy Constructor with size
    ~Algorithms();              // Destructor for the class

    int sizeOfArry;             // Array size
    int *arrData;               // Integer Array
    int getSize();              // Function to access the size
    void displayArray();        // Display the content of the array
    void reverseArray();        // Function to Inverse the order of the elements in the array
    void swapArray(int,int);    // Function to Swapping elements in array


    /********* Sorting Algoritms ********/
    
    void selectionSort();         // Selection Sort Function
    void insertionSort();         // Insertion Sort Function
    void bubbleSort();            // Bubble Sort Function

    void mergeSort(int, int);     // Merge Sort Function
    void Merge(int,int,int,int);  // Function to Merge elements from MergeSort (HELPER FUNCTION)
    
    void quickSort(int, int);     // Quick Sort Function
    int Partition(int, int);      // Function to Partition the Arrays from quickSort (HELPER FUNCTION)
 

    
    /********* Array Generators ********/
    
    int *Random_Array_Generator(int);         // Function to generate random element array
    int *Sorted_Array_Generator(int);         // Function to generate sorted element array
    int *Reverse_Sorted_Array_Generator(int); // Function to generate reverse sorted element array
    int *TenPercent_Array_Generator(int);     // Function to generate 10% shuffled and 90% sorted array

    /********* Generator Caller ********/
    void Random_Array(int);                  // Random array generator caller function
    void Sorted_Array(int);                  // Sorted array generator caller function
    void Reverse_Sorted_Array(int);          // Reversed Sorted array generator caller function
    void Partially_Sorted_Array(int);        // TenPercent array generator caller function

protected:

private:
};



#endif //PROJECT_ALGORITHMS_H

