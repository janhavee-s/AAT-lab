// Fractional Knapsack Problem
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
};

bool compare(Item a, Item b) {
    return (double)a.profit / a.weight >
           (double)b.profit / b.weight;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter profit and weight of item " << i+1 << ": ";
        cin >> items[i].profit >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double totalProfit = 0.0;

    for(int i = 0; i < n && capacity > 0; i++) {
        if(items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].profit *
                          ((double)capacity / items[i].weight);
            break;
        }
    }

    cout << "Maximum profit: " << totalProfit;

    return 0;
}


// Activity Selection Problem
#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity act[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter start and finish time of activity " << i+1 << ": ";
        cin >> act[i].start >> act[i].finish;
    }

    sort(act, act + n, compare);

    cout << "Selected activities:\n";

    int lastFinish = act[0].finish;
    cout << "(" << act[0].start << "," << act[0].finish << ")\n";

    for(int i = 1; i < n; i++) {
        if(act[i].start >= lastFinish) {
            cout << "(" << act[i].start << "," << act[i].finish << ")\n";
            lastFinish = act[i].finish;
        }
    }

    return 0;
}


// Job Sequencing with Deadline
#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter job id, deadline and profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;
    for(int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    char slot[maxDeadline];
    bool filled[maxDeadline] = {false};

    int totalProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(!filled[j]) {
                filled[j] = true;
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Job sequence:\n";
    for(int i = 0; i < maxDeadline; i++) {
        if(filled[i])
            cout << slot[i] << " ";
    }

    cout << "\nTotal profit: " << totalProfit;

    return 0;
}