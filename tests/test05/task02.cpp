#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size;
    cin >> size;
    vector<int> arr;
    unordered_map<int,int> mp;
    for(int i=0;i<size;i++){
        int num;
        cin >> num;
        arr.push_back(num);
        mp[num]++;
    }
    int sum=0;
    for(auto curr:mp){
        if(curr.second%2!=0){
            sum+=curr.first*curr.second;
        }
    }
    cout<<sum;
    return 0;
}
