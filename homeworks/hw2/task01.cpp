#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void merge(int arr[], const int start, const int middle, const int end) {
    const int size1 = middle - start + 1;
    const int size2 = end - middle;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    for (int i = 0; i < size1; i++) {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < size2; i++) {
        arr2[i] = arr[middle + i + 1];

    }

    int i = 0, j = 0, k = start;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        
        k++;
    }

    while (i < size1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    delete[] arr1;
    delete[] arr2;
}
void mergesort(int arr[], int leftEnd, int rightEnd)
{
    if (leftEnd < rightEnd) 
    {
        int middle;
        middle = (leftEnd + rightEnd) / 2;
        mergesort(arr, leftEnd, middle);
        mergesort(arr, middle + 1, rightEnd);
        merge(arr, leftEnd, middle, rightEnd);
    }
}

int main() {
    unsigned int size;
    unsigned int numEmployees;

    cin >> size;
    int* prices=new int[size];

    for (size_t i = 0; i < size; i++) {
        cin >> prices[i];
      
    }
    cin >> numEmployees;
    
    if(size>numEmployees){
       mergesort(prices, 0, size - 1);
    }
    
    long long int minMoney = 0;
    
    for (size_t i = 0; i < numEmployees; i++) {
         minMoney += prices[i];
    }
  
    cout << minMoney << endl;
    

    delete[] prices;
    return 0;
}
