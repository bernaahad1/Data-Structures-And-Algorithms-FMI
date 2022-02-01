#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
   char left;
   

   cin >> input;
   cin >> left;
   int size = input.size();
   vector<int> result;

   for (int i = 0; i < size; i++) {
       if (input[i] == left) {
           result.push_back(0);
           continue;
       }
       int countR = size;
       for (int j = i + 1; j < size; j++) {
           if (input[j] == left) {
               countR = j - i;
               break;
           }
       }
       int countL = size;
       for (int j = i -1; j >= 0; j--) {
           if (input[j] == left) {
               countL = i - j;
               break;
           }
       }
       if (countL <= countR) {
           result.push_back(countL);
       }
       else {
           result.push_back(countR);
       }
   }
   for (int i = 0; i < size; i++) {
       cout << result[i] << " ";
   }

    return 0;
}
