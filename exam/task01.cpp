#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int row;
int colls;
unordered_map<string,int> mp;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>row>>colls;
    while(row--){
        string general="";
        for(int i=0;i<colls;i++){
            string num;
            cin>>num;
            general+=num;
        }
        mp[general]++;
    }
    int count=0;
    for(auto curr:mp){
        if(curr.second==1){
            count++;
        }
    }
    cout<<count;
    return 0;
}