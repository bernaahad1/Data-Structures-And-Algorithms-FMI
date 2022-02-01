#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int size;
    long long int diff;

    cin >> size >> diff;
    vector<int> nums;


    for (int i = 0; i < size; i++) {
        long long int num;
        cin >> num;
        nums.push_back(num);
    }
    for (int i = 0; i < size; i++) {
        
        bool has = false;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i] && nums[i]-nums[j]<=diff){
                printf("%d ", j);
                has = true;
                break;
            }
        }
        if(!has){
            printf("%d ", -1);
        }
        
    }

    return 0;
}