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
        rightGap = n - latestIndex - 1;
    }

    // special case: all 0's
    if (latestIndex == -1) {
        cout << n - 1 << endl;
        return 0;
    }

    // first, calculate initial value of D prior to adding any cows
    int d = n;
    for (int gap : gaps) {
        d = min(d, gap + 1);
    }

    // NOTE: throughout this solution, I take huge advantage of integer division (division for integers rounds down)
    // make sure you see why each of my formulas work
    int answer = 0;

    // case 1: place both cows in same gap
    if (leftGap != -1) {
        answer = max(answer, min(leftGap / 2, d));
    }
    if (rightGap != -1) {
        answer = max(answer, min(rightGap / 2, d));
    }
    for (int gap : gaps) {
        answer = max(answer, min((gap + 1) / 3, d));
    }

    // case 2: place both cows in separate gaps
    sort(gaps.begin(), gaps.end()); // I will sort the array for convenience, but it is possible to do this in just O(N)
    // hint for O(N): similar trick to what I did for reduce (code on Github)
    if (gaps.size() >= 2) {
        answer = max(answer, min((gaps[gaps.size() - 2] + 1) / 2, d));
    }
    if (leftGap != -1 && !gaps.empty()) {
        answer = max(answer, min(min(leftGap, (gaps[gaps.size() - 1] + 1) / 2), d));
    }
    if (rightGap != -1 && !gaps.empty()) {
        answer = max(answer, min(min(rightGap, (gaps[gaps.size() - 1] + 1) / 2), d));
    }
    if (leftGap != -1 && rightGap != -1) {
        answer = max(answer, min(min(leftGap, rightGap), d));
    }

    cout << answer << endl;

    return 0;
}
