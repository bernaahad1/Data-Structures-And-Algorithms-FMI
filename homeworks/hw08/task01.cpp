#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << fixed << setprecision(1);
    priority_queue <int> maxHeaPLower;
    priority_queue <int,vector<int>,greater<int>> minHeaPUpper;

    int size;
    cin >> size;
    int num;
    cin >> num;
    maxHeaPLower.push(num);
    size--;
    double med = num * 1.0;
     printf("%.*f\n",1,med);
    while (size > 0) {
        cin >> num;
        if (maxHeaPLower.size() > minHeaPUpper.size()) {
            if (num > med) {
                minHeaPUpper.push(num);
            }
            else {
                minHeaPUpper.push(maxHeaPLower.top());
                maxHeaPLower.pop();
                maxHeaPLower.push(num);
            }
            med = 1.0 * (maxHeaPLower.top() + minHeaPUpper.top()) / 2;
        }
        else if (maxHeaPLower.size() < minHeaPUpper.size()) {
            if (num < med) {
                maxHeaPLower.push(num);
            }
            else {
                maxHeaPLower.push(minHeaPUpper.top());
                minHeaPUpper.pop();
                minHeaPUpper.push(num);
            }
            med = (maxHeaPLower.top() + minHeaPUpper.top()) / 2.0;
        }
        else {
            if (num < med) {
                maxHeaPLower.push(num);
                med = 1.0 * maxHeaPLower.top();
            }
            else {
                minHeaPUpper.push(num);
                med = 1.0 * minHeaPUpper.top();
            }
        }
        
        printf("%.*f\n",1,med);
        size--;
    }

    return 0;
}