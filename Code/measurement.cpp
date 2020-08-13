// #include <bits/stdc++.h>    // this an option, but compile times get much longer
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    // general solution that doesn't rely on there only being 3 cows, and only 100 days
    // pair<string, int> update; // <- represent an update

    int n;
    cin >> n;
    vector<pair<int, pair<string, int>>> updates;   // pair of (int, pair of (string, int))
    // O(N)
    for (int i=0; i<n; i++) {
        int day;
        string name;
        int change;
        cin >> day >> name >> change;
        updates.push_back(make_pair(day, make_pair(name, change)));
    }

    // when you sort a pair, it sorts by the first value of the pair
    sort(updates.begin(), updates.end());   // O(N log N)

    // sanity check that we sorted correctly
//    for (auto p : updates) {
//        cout << p.first << ", " << p.second.first << ", " << p.second.second << endl;
//    }

    // how could we store the wall?
    int answer = 0;
    vector<string> wall;
    map<string, int> cowOutputs;
    // populate the wall with everybody
    // O(N) loop
    for (auto p : updates) {
        // wall.push_back(p.second.first); // Bessie, Bessie
        cowOutputs[p.second.first] = 7; // O(log (# cows))
    }
    // O(# cows)
    for (auto q : cowOutputs) {
        wall.push_back(q.first);    // now each cow appears exactly once
    }
    sort(wall.begin(), wall.end()); // O(# cows * log(# cows))

    // O(N)
    for (auto p : updates) {
        // p.first - day
        // p.second.first - name
        // p.second.second - change
        cowOutputs[p.second.first] += p.second.second;
        vector<string> newWall;
        int maximum = -1000000000;
        // O(# cows)
        for (auto q : cowOutputs) { // key, value pairs
            if (q.second > maximum) {
                newWall.clear();
                maximum = q.second;
                newWall.push_back(q.first);
            } else if (q.second == maximum) {
                newWall.push_back(q.first);
            }
        }

        // ["Bessie", "Elsie", "Mildred"]
        // ["Elsie", "Bessie", "Mildred"]
        // ^ these are equivalent
        sort(newWall.begin(), newWall.end());   // O(# cows * log(# cows))
        if (newWall != wall) {
            wall = newWall;
            answer++;
        }
    }

    cout << answer << endl;

    // O(N log N + N * # cows * log(# cows))
    // # cows = 3

    return 0;
}
