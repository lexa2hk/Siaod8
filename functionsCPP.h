//
// Created by xale3k on 20.04.2022.
//

#ifndef SIAOD8_FUNCTIONSCPP_H
#define SIAOD8_FUNCTIONSCPP_H
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
    int current;
    int left, right, mid;
    for (int i = 0; i < n; i++){
        current = arr[i];
        left = 0;
        right = i;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (arr[mid] <= current){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        for (int j = i; j > left; j--){
            arr[j] = arr[j - 1];
        }

        arr[left] = current;
    }
}

//многофазная сортировка слиянием







#endif //SIAOD8_FUNCTIONSCPP_H
