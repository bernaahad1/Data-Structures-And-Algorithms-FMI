#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Submits {
public:
    long long int submitTime = 0;
    long long int lines = 0;

    Submits(long long int submitTime=0,long long int lines=0):
        submitTime(submitTime),lines(lines){
    }

    friend bool operator<(const Submits& s1, const Submits& s2) {
        return (s1.submitTime < s2.submitTime);
    }
};

struct compLines {
    bool operator()(const Submits& s1, const Submits& s2) {
        return (s1.lines > s2.lines);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numStud;
    cin >> numStud;

    vector<Submits> submits(numStud);

    for (int i = 0; i < numStud; i++) {
        long long int subTime;
        long long int lines;
        cin >> subTime >> lines;
        submits[i].submitTime = subTime;
        submits[i].lines = lines;
    }
    sort(submits.begin(), submits.end());

    int i = 0;
    long long int currTime = submits[i].submitTime;
    long long int waitTime = 0;
    priority_queue <Submits, vector<Submits>, compLines> control;
    
    while (i < numStud || (!control.empty())) {
        while (i < numStud && submits[i].submitTime<=currTime) {
            control.push(submits[i]);
            i++;
        }
        if ((!control.empty()) && control.top().submitTime <= currTime) {
            waitTime += (currTime - control.top().submitTime) + control.top().lines;
            currTime += control.top().lines;
            control.pop();
            continue;
        }
       
         currTime++;
        
    }
    long long int minTime = (waitTime / numStud);
    printf("%lld", minTime);

   return 0;
}