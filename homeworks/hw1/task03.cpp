#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   string word;
    int numSymbols;
    char neededSymbol;

    cin >> word >> numSymbols >> neededSymbol;

    int size = word.size();
    int numNeededSymbInWord = 0;
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (word[i] == neededSymbol) {
            numNeededSymbInWord++;
        }
    }
    if (numNeededSymbInWord == 0) {
        cout << numNeededSymbInWord;
       
    }
    else {
        result = numNeededSymbInWord * (numSymbols / size);
        if (numSymbols % size != 0) {
            numSymbols -= (size * (numSymbols / size));
            for (int i = 0; i < numSymbols; i++) {
                if (word[i] == neededSymbol) {
                    result++;
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}