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
    cin>>size;
    unordered_map<string,int> mp;
    vector<string> arr;
    
    for(int i=0;i<size;i++){
        string st;
        cin>>st;
        mp[st]++;
        arr.push_back(st);
    }
    for(int i=0;i<size;i++){
        cout<<mp[arr[i]]<<" ";
    }
    return 0;
}
