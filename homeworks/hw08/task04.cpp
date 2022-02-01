#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sizeClient;
    int sizeOperators;
    cin >> sizeClient >> sizeOperators;
    
    map<int, int> opWork;
    map<int,int> currOpWork;

    int maxTimes = 0;
    priority_queue<int,vector<int>,greater<int>> maxRange;
    
    for (int i = 0; i < sizeOperators; i++) {
        opWork[i] = 0; 
        currOpWork[i] = 0;

    }
    for (int i = 1; i <= sizeClient; i++) {
        int start;
        int end;
        cin >> start >> end;
        int findOp = i % sizeOperators;
        int j = findOp;
        if (findOp == 0) {
            j = sizeOperators - 1;
        }
        else {
            j--;
        }
        findOp = j;
        while (j < sizeOperators) {
            if (currOpWork[j] <= start) {
                currOpWork[j] = start + end;
                opWork[j]++;
                if (opWork[j] > maxTimes) {
                    maxTimes = opWork[j];
                    maxRange = priority_queue<int, vector<int>, greater<int>>();
                    maxRange.push(j);
                }
                else if(opWork[j] == maxTimes){
                    maxRange.push(j);
                }
                break;
            }
            else {
                if (j == sizeOperators - 1) {
                    j = 0;
                }
                else {
                    j++;
                }
                if (j == findOp) {
                    break;
                }
                
            }
        }
        
    }
    while (!maxRange.empty()){
        printf("%d ",maxRange.top());
        maxRange.pop();
    }
  
    return 0;
}
