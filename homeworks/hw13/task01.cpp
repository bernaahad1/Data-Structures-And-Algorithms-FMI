#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 26;
int rows;
int cols;
char arr[N][N] = {'0'};
int freeSymb = 0;
pair<int, int> startingPoint;
int numPaths = 0;

void findPath(int r,int c) {
    if (r >= rows || r < 0 || c >= cols || c < 0) {
        return;
    }
    if (arr[r][c] == 'x'|| arr[r][c] == 's') {
        return;
    }
    if (arr[r][c] == 'e') {
        if (freeSymb == 0) {
            numPaths++;
            return;
        }
        return;
    }
    if (arr[r][c] == '+') {
        return;
    }
    freeSymb--;
    arr[r][c] = '+';
    findPath(r - 1, c);
    findPath(r + 1, c);
    findPath(r, c + 1);
    findPath(r, c - 1);
    freeSymb++;
    arr[r][c] = '-';
    return;
}

int main() {
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          
            cin >> arr[i][j];
            if (arr[i][j] == '-') {
                freeSymb++;
            }
            else if (arr[i][j] == 's') {
                startingPoint.first = i;
                startingPoint.second = j;
            }
        }
    }
    findPath(startingPoint.first+1, startingPoint.second);
    findPath(startingPoint.first-1, startingPoint.second);
    findPath(startingPoint.first, startingPoint.second+1);
    findPath(startingPoint.first, startingPoint.second-1);

    cout << numPaths << endl;
    
    return 0;
}
