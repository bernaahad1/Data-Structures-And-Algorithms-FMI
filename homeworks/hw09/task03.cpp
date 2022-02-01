#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1;
    string s2;
    cin >> s1 >> s2;
    int size1 = s1.size();
    int size2 = s2.size();
    int start = 0;
    int j = start;
    string copy1 = {};
    string copy2 = {};
    int maxSize = 0;
    while (start < size2) {
        copy2 += s2[j];
        int i = 0;
        copy1 += s1[i];
        
        j = start;
        while (j < size2 && i < size1) {
            if (copy1 == copy2) {
                if (maxSize < (int)copy1.size()) {
                    maxSize = copy1.size();
                    if (maxSize == size2) {
                        printf("%d", size2);
                        return 0;
                    }
                }
                i++;
                j++;
                copy1 += s1[i];
                copy2 += s2[j];
            }
            else {
                if (maxSize >= (size1 - i + 1)) {
                    break;
                }
                copy2 = s2[start];
                j = start;
                i++;
                copy1 = s1[i];
            }
        }
        start++;
    }
    printf("%d", maxSize);
    return 0;
}