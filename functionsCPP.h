//
// Created by xale3k on 20.04.2022.
//

#ifndef SIAOD8_FUNCTIONSCPP_H
#define SIAOD8_FUNCTIONSCPP_H
#include "listStack.h"
//случайное заполнение массива
using namespace std;
void fill_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_id = i;

        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_id])
                min_id = j;
        }
        int temp = arr[min_id];
        arr[min_id] = arr[i];
        arr[i] = temp;
        //if(i%10000==0) cout<<"Selection sort: "<<i<<"/"<<n<<endl;

    }
}

void InsertionSortBinary(int *arr, int n){
    long long int count = 0;
    int current;
    int left, right, mid;
    for (int i = 0; i < n; i++){
        count+=4;
        current = arr[i];
        left = 0;
        right = i;
        while (left < right)
        {
            count+=4;
            mid = (left + right) / 2;
            if (arr[mid] <= current){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        for (int j = i; j > left; j--){
            count+=2;
            arr[j] = arr[j - 1];
        }

        arr[left] = current;
    }
    cout<<"Insertion sort binary: "<<count<<endl;
}

//сортировка слиянием


void merge(int *array, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;


    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}


void mergeSort(int *array, int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}









#endif //SIAOD8_FUNCTIONSCPP_H
