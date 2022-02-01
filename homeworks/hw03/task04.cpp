#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int size;
    unsigned int numInput;
    cin >> size;
    cin >> numInput;
    unsigned long int S;
    unsigned int P;

    vector<unsigned int> arr;
    for (size_t i = 0; i < size; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    vector<int> result;
    while (numInput > 0) {
        cin >> S;
        cin >> P;
        int index;
        if (arr[size - 1] < P) {
            index = size - 1;
        }
        else {
            index = (upper_bound(arr.begin(), arr.end(), P) - arr.begin());
            index--;
        }

        unsigned int res = 0;
        int i = index - 1;
        for (i = index - 1; i >= 0; i -= 2) {
            if ((arr[i] + arr[i+1]) <= S) {
                res+=2;
                S -= (arr[i] + arr[i + 1]);
            }
            else  if (arr[i + 1] <= S) {
                res++;
                S -= arr[i + 1];
                break;
            }
            else {
                break;
            }
            if (S == 0) {
                break;
            }
        }
        if (i == -1 && arr[i+1] < S) {
            res++;
        }
        result.push_back(res);
        numInput--;
    }

    for (size_t i = 0; i < result.size(); i++) {
        printf("%i \n",result[i]);
    }
    return 0;
}