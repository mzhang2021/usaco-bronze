#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct IntersectionPoint {
    int cow1, cow2, time1, time2;

    bool operator < (const IntersectionPoint &other) const {
        if (time2 == other.time2) {
            // completely arbitrary, since intersection points at same time are simultaneously processed anyways
            if (cow1 == other.cow1) {
                if (cow2 == other.cow2)
                    return time1 < other.time1;
                return cow2 < other.cow2;
            }
            return cow1 < other.cow1;
        }
        // main idea: sort by time 2
        return time2 < other.time2;
    }
};

int main() {
    int n;
    cin >> n;
    vector<char> dir(n);
    vector<int> x(n), y(n);
    for (int i=0; i<n; i++)
        cin >> dir[i] >> x[i] >> y[i];

    vector<IntersectionPoint> intersect;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++) {
            if (dir[i] != dir[j]) {
                // one of them is facing east, one is facing north
                int a = i, b = j;
                if (dir[a] == 'N')
                    swap(a, b);
                // guarantees a - faces east, b - faces north
                if (x[a] < x[b] && y[a] > y[b]) {
                    int timeA = x[b] - x[a], timeB = y[a] - y[b];
                    if (timeA > timeB) {
                        intersect.push_back({b, a, timeB, timeA});
                    } else if (timeA < timeB) {
                        intersect.push_back({a, b, timeA, timeB});
                    }
                    // no else because if timeA = timeB, both cows keep going
                }
            }
        }
    // possible to not sort, iterate each time to find minimum time intersection point
    // O(N^4)
    sort(intersect.begin(), intersect.end());

    const int INF = 2e9;
    vector<int> stopTime(n, INF);
    for (IntersectionPoint &ip : intersect) {
        if (ip.time1 < stopTime[ip.cow1] && ip.time2 < stopTime[ip.cow2]) {
            // cow2 gets stopped because it was the slower of the two
            stopTime[ip.cow2] = ip.time2;
        }
    }

    for (int i=0; i<n; i++) {
        if (stopTime[i] == INF)
            cout << "Infinity\n";
        else
            cout << stopTime[i] << "\n";
    }

    return 0;
}
