//
//  Array2.cpp
//  115
//
//  Created by Harkaran Brar on 3/6/18.
//  Copyright © 2018 Harkaran Brar. All rights reserved.
//
#include "Algorithms.h"                                // Header File


Algorithms::Algorithms()                               // Default Constructor
{
    arrData = NULL;                                    // Intialize pointer to NULL
    sizeOfArry = 0;                                    // Intialize the size of array to 0
}

Algorithms::~Algorithms()                              // Destructor
{
}

Algorithms::Algorithms(int value)                       // Copy Constructor with size 
{
    sizeOfArry = value;                                 // Set the size of array to given size
    arrData = new int[sizeOfArry];                      // New pointer
    arrData =  Random_Array_Generator(sizeOfArry);      // Get a random Array of given size 
}


int Algorithms::getSize()                               // Get the size of array
{
    return sizeOfArry;                                  // return size of array 
}


void Algorithms::displayArray()                         // Display Function for debug 
{
    for(int i=0; i<sizeOfArry; i++)
    {
        cout<<arrData[i]<<" ";
    }
    cout<< endl;
}

void Algorithms::reverseArray()                          // Function to reverse the array of given size 
{
    int temp;

    for(int i=0; i<sizeOfArry/2; i++)
    {
        temp = arrData[i];
        arrData[i] = arrData[sizeOfArry-i-1];
        arrData[sizeOfArry-i-1] = temp;
    }
}



/* ************** SORTING ALGORITHMS ******************* */

void Algorithms::swapArray(int i, int j)                            // Function to swap the array
{
    int temp;
    temp = arrData[i];
    arrData[i] = arrData[j];
    arrData[j] = temp;
}

/* ***************** SELECTION SORT ******************* */

void Algorithms::selectionSort()                                   // Function for Selection Sort 
{
    
    int minVal;                     //store minimum value
    int i,j,minIndx;
    
    for(i=0;i<sizeOfArry;i++)       //outer loop
    {
        minVal = arrData[i];        //initial min val
        minIndx = i;                //initial min ind
        
        for(j=i;j<sizeOfArry;j++)   //inner loop
        {
            if(arrData[j]<minVal)
            {
                minVal = arrData[j];
                minIndx = j;
            }
        }
        if (minVal<arrData[i])      //swap if minimum
        {
            swapArray(minIndx,i);
        }
        
    }
    
  //  displayArray();
    
}

/* ***************** INSERTION SORT ******************* */

void Algorithms::insertionSort()                            // Function for Insertion Sort
{
    int val, j;

    for (int i=1;i<sizeOfArry;i++)
    {
        val = arrData[i];
        j = i-1;
        while (j>=0 && val<arrData[j])
        {
            swapArray(j, j+1);                               
            j--;
        }

    }

  //  displayArray();
}

/* ***************** BUBBLE SORT ******************* */

void Algorithms::bubbleSort()                                   // Function for Bubble Sort 
{
    for(int i=0; i<sizeOfArry;i++)
    {
        for(int j=0; j<sizeOfArry-1;j++)
        {
            if (arrData[j]>arrData[j+1])
            {
                swapArray(j,j+1);
            }
        }
    }
  //  displayArray();
}

/* ***************** MERGE SORT ******************* */

void Algorithms:: Merge(int leftBottom, int leftTop, int rightBottom, int rightTop)        // Function to Merge the array from Merge Sort
{
    
    int Size = rightTop-leftBottom+1;
    int temp[Size];
    int left = leftBottom;
    int right = rightBottom;
    for (int i = 0; i < Size; ++i)
    {
        if (left > leftTop)
        {
            temp[i] = arrData[right++];
        }
        else if (right > rightTop)
        {
            temp[i] = arrData[left++];
        }
        else if (arrData[left] <= arrData[right])
        {
            temp[i] = arrData[left++];
        }
        else
        {
            temp[i] = arrData[right++];
        }
    }

    for (int i=0; i< Size; ++i)
    {
        arrData[leftBottom++] = temp[i];
    }
    
}

void Algorithms::mergeSort(int left, int right)                     // Function for Merge Sort
{
    
    if (left>=right)
    {
        return;
    }else
    {
        int mid = (left + right)/2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        Merge(left,mid,mid+1,right);
    }
    
  //  displayArray();
}


/* ***************** QUICK SORT ******************* */

int Algorithms::Partition(int StartIndx, int endIndx)                     // Function for Divide the array for Quick Sort
{
    for(int i=StartIndx;i<endIndx;i++)
    {
        if(arrData[i]<=arrData[endIndx])
        {
            swapArray(i,StartIndx);
            StartIndx++;
        }
    }
    swapArray(StartIndx,endIndx);
    return StartIndx;
}

void Algorithms::quickSort(int left, int right)                         // Function for Quick Sort
{
    if(left<right)
    {
        int pivot = Partition(left, right);                             
        quickSort(left, pivot-1);
        quickSort(pivot+1, right);
    }
}



/* ************************************************* */



void Algorithms::Random_Array(int Size)                                 // Caller Function to Generate Random element array
{
    if (arrData != NULL)                                                // if it's not NULL delete 
        delete []arrData;
    sizeOfArry = Size;
    arrData = Random_Array_Generator(Size);                            
    
}

void Algorithms::Sorted_Array(int Size)                                 // Caller Function to Generate Sorted element array
{
    if (arrData != NULL)                                                // if it's not NULL delete
        delete []arrData;
    sizeOfArry = Size;
    arrData = Sorted_Array_Generator(Size);
}

void Algorithms::Reverse_Sorted_Array(int Size)                       // Caller Function to Generate Reverse Sort element array
{
    if (arrData != NULL)                                              // if it's not NULL delete
        delete []arrData;
    sizeOfArry = Size;
    arrData = Reverse_Sorted_Array_Generator(Size);
}

void Algorithms::Partially_Sorted_Array(int Size)                    // Caller Function to Generate Partially Sort element array
{
    if (arrData != NULL)                                             // if it's not NULL delete
        delete []arrData;
    arrData = TenPercent_Array_Generator(Size);
    sizeOfArry = Size;
}


/* *********** ARRAY GENERATORS  **************** */

// This function generate random array of given size.

int* Algorithms::Random_Array_Generator(int Size)                   // Function to Generate random element array
{
    int * RA = new int [Size];
    for(int counter = 0; counter < Size; counter++)                 // Counter 
    {
        RA[counter]=rand() % 100;                                   // Generate random element and assigning to array
    }
    return RA;
}


// This function generate sorted array of given size.

int * Algorithms::Sorted_Array_Generator(int Size)                   // Function to Generate Sorted element array
{
    int i = 0;
    
    arrData = Random_Array_Generator(Size);                         // Call to Random array Generator 
    vector<int> myvector (arrData, arrData+(Size));                 // Assigning data to vector 
    
    sort(myvector.begin(), myvector.end());                         // Sort algorithm form alogrithm c++ library
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it) // Iterator
    {
        arrData[i] = *it;                                           // Assigning to data to pointer array
        i++;
    }
    return arrData;
}


// This function generate Sorted array then reverse it.
// array will sorted in reverse order


int *Algorithms::Reverse_Sorted_Array_Generator(int Size)            // Function to Generate Reverse Sorted element array
{
    
    arrData = Sorted_Array_Generator(Size);                          // Generate Sorted array
    reverseArray();                                                  // Reverse the array 
    sizeOfArry = Size;
    
    return arrData;
}

// This function generate shuffled array and sort it 90%.
// 10% array will be shuffled 90% will be sorted

int *Algorithms::TenPercent_Array_Generator(int Size)                // Function to Generate Sorted and Ten percent Shuffled element array      
{
    int percent = 0;                                                 
    int i = 0;
    percent = (Size * .9);                                           // For getting how much array want to be sorted now it's at 90%
    
    arrData = Random_Array_Generator(Size);                         // Calling random array generator
    vector<int> myvector (arrData, arrData+(Size));                 // vector

    partial_sort (myvector.begin(), myvector.begin()+(percent), myvector.end());    // Partial Sort algorithm form alogrithm c++ library 
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)       // Iterator
    {
        arrData[i] = *it;                                           // Assigning to data to pointer array
        i++;
    }
    return arrData;                                                 // return array pointer
}




