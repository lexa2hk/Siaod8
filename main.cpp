#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include <cmath>
#include "functionsCPP.h"
#include "listStack.h"
using namespace std;


int main() {
    //system("chcp 65001");
    srand(time(NULL));


    int choose;
    cin>>choose;
    switch(choose){
        case 1: {
            int n;
            cin >> n;
            int *arrM = new int[n];
            for (int i = 0; i < n; i++) arrM[i]=i;
            fill_array(arrM,n);
            for (int i = 0; i < n; i++) cout<<  arrM[i]<<" ";
            cout<<endl;
            //cout << "Сортировка простого выбора" << endl;
            //selectionSort(arrM, n);
            //cout << "Сортировка бинарными вставками" << endl;
            InsertionSortBinary(arrM, n);
            for (int i = 0; i < n; i++) {
                cout << arrM[i] << " ";
            }
            break;
        }
        case 2:{
            for(int n1=100;n1<=pow(10,5);n1*=10){
                int *arr1 = new int[n1];
                //fill_array(arr1, n1);
                for (int i = 0; i < n1; i++) arr1[i]=n1-i;
                cout<<"Бинарная сортировка вставками("<<n1<<")"<<endl;
                auto start = chrono::steady_clock::now();
                InsertionSortBinary(arr1, n1);
                auto end = chrono::steady_clock::now();
                auto diff = end - start;
                cout << "Время выполнения: " << chrono::duration <double, milli> (diff).count() << " мс" << endl<<endl;
                delete[] arr1;
            }

            break;
        }
        case 3:{
            for(int n1=100;n1<=pow(10,5);n1*=10){
                int *arr1 = new int[n1];
                //fill_array(arr1, n1);
                cout<<"Сортировка простого выбора("<<n1<<")"<<endl;
                auto start = chrono::steady_clock::now();
                selectionSort(arr1, n1);
                auto end = chrono::steady_clock::now();
                auto diff = end - start;
                cout << "Время выполнения: " << chrono::duration <double, milli> (diff).count() << " мс" << endl<<endl;
                delete[] arr1;
            }
            break;
        }
        case 4:{
            for(int n1=100;n1<=pow(10,6);n1*=10) {
                cout << "Сортировка слиянием(" << n1 << ")" << endl;
                int *arr1 = new int[n1];
                //for(int i=0;i<n1;i++) arr1[i]=n1-i;
                fill_array(arr1, n1);


                auto start = chrono::steady_clock::now();

                mergeSort(arr1, 0, n1 - 1);

                auto end = chrono::steady_clock::now();
                auto diff = end - start;
                cout << "Время выполнения: " << chrono::duration<double, milli>(diff).count() << " мс" << endl << endl;
            }
            break;
        }
        default:
            break;

    };


    return 0;

}
