#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include <cmath>
#include "functionsCPP.h"
using namespace std;


int main() {
    system("chcp 65001");
    srand(time(NULL));


    int choose;
    cin>>choose;
    switch(choose){
        case 1: {
            int n;
            cin >> n;
            int *arrM = new int[n];
            //for (int i = 0; i < n; i++) cin >> arrM[i];
            fill_array(arrM,n);
            for (int i = 0; i < n; i++) cout<<  arrM[i]<<" ";
            cout<<endl;
            cout << "Сортировка простого выбора" << endl;
            selectionSort(arrM, n);
            for (int i = 0; i < n; i++) {
                cout << arrM[i] << " ";
            }
            break;
        }
        case 2:{
            for(int n1=100;n1<=pow(10,5);n1*=10){
                int *arr1 = new int[n1];
                fill_array(arr1, n1);
                cout<<"Бинарная сортировка вставками("<<n1<<")"<<endl;
                auto start = chrono::steady_clock::now();
                selectionSort(arr1, n1);
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
                fill_array(arr1, n1);
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
            break;
        }
        case -1:{
            ofstream fout("output.txt");
            int*arr=new int[100000];
            fill_array(arr, pow(10,5));
            for(int i=100;i<=pow(10,5);i+=1000){
                int *arr1;
                //copy arr to arr1
                arr1=new int[i];
                for(int j=0;j<i;j++){
                    arr1[j]=arr[j];
                }

                auto start = chrono::steady_clock::now();
                selectionSort(arr1, i);
                auto end = chrono::steady_clock::now();
                auto diff = end - start;
                fout <<i<<" "<< chrono::duration <double, milli> (diff).count()<< endl;
                delete[] arr1;
            }
            delete[] arr;
            fout.close();
            break;
        }
        default:
            break;

    };


    return 0;

}
