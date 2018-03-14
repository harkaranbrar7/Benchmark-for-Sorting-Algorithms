//
//  Array2.cpp
//  115
//
//  Created by Harkaran Brar on 3/6/18.
//  Copyright © 2018 Harkaran Brar. All rights reserved.
//
#include "Algorithms.h"


Algorithms::Algorithms()
{
    arrData = NULL;
    sizeOfArry = 0;
}

Algorithms::~Algorithms()
{
}

Algorithms::Algorithms(int value)
{
    sizeOfArry = value;
    arrData = new int[sizeOfArry];
    arrData =  Random_Array_Generator(sizeOfArry);
}


int Algorithms::getSize()
{
    return sizeOfArry;
}


void Algorithms::displayArray()
{
    for(int i=0; i<sizeOfArry; i++)
    {
        cout<<arrData[i]<<" ";
    }
    cout<< endl;
}

void Algorithms::reverseArray()
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

void Algorithms::swapArray(int i, int j)
{
    int temp;
    temp = arrData[i];
    arrData[i] = arrData[j];
    arrData[j] = temp;
}

/* ***************** SELECTION SORT ******************* */

void Algorithms::selectionSort()
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

void Algorithms::insertionSort()
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

void Algorithms::bubbleSort()
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

void Algorithms:: Merge(int leftBottom, int leftTop, int rightBottom, int rightTop)
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

void Algorithms::mergeSort(int left, int right)
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

int Algorithms::Partition(int StartIndx, int endIndx)
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

void Algorithms::quickSort(int left, int right)
{
    if(left<right)
    {
        int pivot = Partition(left, right);
        quickSort(left, pivot-1);
        quickSort(pivot+1, right);
    }
}



/* ************************************************* */



void Algorithms::Random_Array(int Size)
{
    if (arrData != NULL)
        delete []arrData;
    sizeOfArry = Size;
    arrData = Random_Array_Generator(Size);
    
}

void Algorithms::Sorted_Array(int Size)
{
    if (arrData != NULL)
        delete []arrData;
    sizeOfArry = Size;
    arrData = Sorted_Array_Generator(Size);
}

void Algorithms::Reverse_Sorted_Array(int Size)
{
    if (arrData != NULL)
        delete []arrData;
    sizeOfArry = Size;
    arrData = Reverse_Sorted_Array_Generator(Size);
}

void Algorithms::Partially_Sorted_Array(int Size)
{
    if (arrData != NULL)
        delete []arrData;
    arrData = TenPercent_Array_Generator(Size);
    sizeOfArry = Size;
}


/* *********** ARRAY GENERATORS  **************** */

int* Algorithms::Random_Array_Generator(int Size)
{
    int * RA = new int [Size];
    for(int counter = 0; counter < Size; counter++)
    {
        RA[counter]=rand() % 100;
    }
    return RA;
}


int * Algorithms::Sorted_Array_Generator(int Size)
{
    int i = 0;
    
    arrData = Random_Array_Generator(Size);
    vector<int> myvector (arrData, arrData+(Size));
    
    sort(myvector.begin(), myvector.end());
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    {
        arrData[i] = *it;
        i++;
    }
    return arrData;
}


int *Algorithms::Reverse_Sorted_Array_Generator(int Size)
{
    
    arrData = Sorted_Array_Generator(Size);
    reverseArray();
    sizeOfArry = Size;
    
    return arrData;
}

int *Algorithms::TenPercent_Array_Generator(int Size)
{
    int percent = 0;
    int i = 0;
    percent = (Size * .9);
    
    arrData = Random_Array_Generator(Size);
    vector<int> myvector (arrData, arrData+(Size));

    // using default comparison (operator <):
    partial_sort (myvector.begin(), myvector.begin()+(percent), myvector.end());
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    {
        arrData[i] = *it;
        i++;
    }
    return arrData;
}






