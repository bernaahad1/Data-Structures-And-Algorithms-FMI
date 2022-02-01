#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

void merge(vector<pair<string, unsigned int>>& arr, const int start, const int middle, const int end) {

    const int size1 = middle - start + 1;
    const int size2 = end - middle;
    vector<pair<string, unsigned int>> arr1(size1);
    vector<pair<string, unsigned int>> arr2(size2);

    for (int i = 0; i < size1; i++) {
        arr1[i].first = arr[start + i].first;
        arr1[i].second = arr[start + i].second;

    }
    for (int i = 0; i < size2; i++) {
        arr2[i].first = arr[middle + i + 1].first;
        arr2[i].second = arr[middle + i + 1].second;


    }

    int i = 0, j = 0, k = start;
    while (i < size1 && j < size2) {
        if (arr1[i].first <= arr2[j].first) {
            arr[k].first = arr1[i].first;
            arr[k].second = arr1[i].second;

            i++;
        }
        else {
            arr[k].first = arr2[j].first;
            arr[k].second = arr2[j].second;

            j++;
        }

        k++; 
    }

    while (i < size1) {
        arr[k].first = arr1[i].first;
        arr[k].second = arr1[i].second;
        i++;
        k++;
    }
    while (j < size2) {
        arr[k].first = arr2[j].first;
        arr[k].second = arr2[j].second;
        j++;
        k++;
    }
}
void mergesort(vector<pair<string, unsigned int>>& arr, int leftEnd, int rightEnd)
{
    if (leftEnd < rightEnd) 
    {
        int middle;
        middle = (rightEnd + leftEnd) / 2;
        mergesort(arr, leftEnd, middle);
        mergesort(arr, middle + 1, rightEnd);
        merge(arr, leftEnd, middle, rightEnd);
    }
}


int main() {
    unsigned int size;
    vector<pair<string, unsigned int>> times;

    cin >> size;
    cin.ignore();

    for (unsigned int i = 0; i < size; i++) {
        string row;
        string number="";
        getline(cin, row);
       
        number += row.substr(15, 4);
        number += row.substr(12, 2);
        number += row.substr(9, 2);
        number += row.substr(0, 2);
        number += row.substr(3, 2);
        number += row.substr(6, 2);

        times.push_back(make_pair(number, i + 1));
    }
    mergesort(times, 0, times.size() - 1);

    for (unsigned int i = 0; i < size; i++) {
        cout << times[i].second << endl;
    }

    return 0;
}