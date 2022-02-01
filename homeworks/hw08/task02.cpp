#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Task {
public:
    long long int startTime = 0;
    long long int duration = 0;
    int index = 0;

    Task(long long int startTime = 0, long long int duration = 0,int index=0) :
        startTime(startTime), duration(duration),index(index) {
    }

    friend bool operator<(const Task& s1, const Task& s2) {
        return (s1.startTime < s2.startTime);
    }
};

struct compDuration {
    bool operator()(const Task& s1, const Task& s2) {
        if(s1.duration == s2.duration){
            return s1.index>s2.index;
        }
        return (s1.duration > s2.duration);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTasks;
    cin >> numTasks;

    vector<Task> tasks(numTasks);

    for (int i = 0; i < numTasks; i++) {
        long long int startTime;
        long long int duration;
        cin >> startTime >> duration;
        tasks[i].startTime = startTime;
        tasks[i].duration = duration;
        tasks[i].index = i;
    }
    sort(tasks.begin(), tasks.end());

    int i = 0;
    long long int currTime = tasks[i].startTime;
    priority_queue <Task, vector<Task>, compDuration> control;


    while (i < numTasks || (!control.empty())) {
        while (i < numTasks && tasks[i].startTime <= currTime) {
            control.push(tasks[i]);
            i++;
        }
        if ((!control.empty()) && control.top().startTime <= currTime) {
            currTime += control.top().duration;
            printf("%d ", control.top().index);
            control.pop();
            continue;
        }
        currTime++;
    }

    return 0;
}