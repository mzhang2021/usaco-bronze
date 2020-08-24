#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    // handle input
    int n;
    string s;
    cin >> n >> s;

    // generate gap sizes
    int leftGap = -1, rightGap = -1, latestIndex = -1;  // leftGap and rightGap represent the sizes of the gaps on the ends
    vector<int> gaps;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            if (latestIndex == -1) {    // leftGap
                leftGap = i;
            } else {    // gap sandwiched between two 1s
                gaps.push_back(i - latestIndex - 1);
            }
            latestIndex = i;
        }
    }
    // rightGap
    if (latestIndex < n - 1) {
        rightGap = n - latestIndex;
    }

    // NOTE: throughout this solution, I take huge advantage of integer division (division for integers rounds down)
    // are my formulas correct though?
    int answer = 0;

    // case 1: place both cows in same gap
    if (leftGap != -1) {
        answer = max(answer, leftGap / 2);
    }
    if (rightGap != -1) {
        answer = max(answer, rightGap / 2);
    }
    for (int gap : gaps) {
        answer = max(answer, gap / 3);
    }

    // case 2: place both cows in separate gaps
    sort(gaps.begin(), gaps.end()); // I will sort the array for convenience, but it is possible to do this in just O(N)
    // hint for O(N): similar trick to what I did for reduce (code on Github)
    answer = max(answer, (gaps[gaps.size() - 2] + 1) / 2);
    if (leftGap != -1 && !gaps.empty()) {
        answer = max(answer, min(leftGap / 2, (gaps[gaps.size() - 1] + 1) / 2));
    }
    if (rightGap != -1 && !gaps.empty()) {
        answer = max(answer, min(rightGap / 2, (gaps[gaps.size() - 1] + 1) / 2));
    }
    if (leftGap != -1 && rightGap != -1) {
        answer = max(answer, min(leftGap / 2, rightGap / 2));
    }

    cout << answer << endl;

    return 0;
}
