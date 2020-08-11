#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    // getting input
    int n, b;
    cin >> n >> b;
    vector<int> x(n), y(n);
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    // try each vertical line between the gaps
    int answer = 1000000000;    // initialize answer to some large value
    for (int i=0; i<n; i++) {
        int xLine = x[i] - 1;   // to the left of cow i

        // try each horizontal line between the gaps
        for (int j=0; j<n; j++) {
            int yLine = y[j] - 1;   // underneath cow j

            vector<vector<int>> cnt(2, vector<int>(2)); // 2-dimensional vector representing the number of cows in the 4 regions
            // check each of the cows and determine which region they belong in
            for (int k=0; k<n; k++) {
                int above, right;
                if (x[k] > xLine) {
                    right = 1;
                } else {
                    right = 0;
                }
                if (y[k] > yLine) {
                    above = 1;
                } else {
                    above = 0;
                }
                cnt[above][right]++;    // implementation trick: I use indices "above" and "right" to save myself from writing lots of if statements
                // for example, cnt[0][1] is the number of cows in the bottom right region
            }

            // take the maximum of the four regions
            int maximum = 0;
            for (int k=0; k<2; k++) {
                for (int l=0; l<2; l++) {
                    maximum = max(maximum, cnt[k][l]);
                }
            }

            // update answer
            answer = min(answer, maximum);
        }
    }

    // print the answer
    cout << answer << endl;

    /*
    THINGS TO CONSIDER:
    1. I never check the horizontal line above all of the cows, and I never check the vertical line to the left of all cows, yet my program still works. Why?
    2. I never sorted the list of coordinates, yet my program still works. Why?
    3. Is the value of "B" relevant to the solution of this problem?
    4. This solution can actually be optimized to O(N^2). Can you see how? The O(N^2) solution solves the silver division version of this problem.
    */

    return 0;
}
