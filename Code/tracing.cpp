#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    // handle input
    int n, t;
    string state;
    cin >> n >> t >> state;

    vector<pair<int, int>> interaction(251, make_pair(-1, -1)); // a vector of size 251 to represent all time values from 0 to 250
    // I initially populate the vector with (-1, -1) pairs to represent "no interaction"
    for (int i=0; i<t; i++) {
        int time, x, y;
        cin >> time >> x >> y;
        x--, y--;   // making the cows 0-indexed to ease implementation
        interaction[time] = make_pair(x, y);    // note: in this problem, only at most one interaction can happen at each time point
        // if more than one interaction could occur at a given time point, then I could store a vector instead of a single (x, y) pair at each time point

        // since we didn't learn what pairs were when assigned this problem, one could alternatively store two vectors x(251) and y(251) instead
    }

    /*
    IDEA: Brute force all possible starting cows with the disease, and all possible K values
    O(N * T * max_time)
    max_time = 250
    */
    int x = 0, y = t, z = 0;    // <- These x, y, z variables are the output variables described in the problem; don't get them confused with x and y from the input section!
    for (int start=0; start<n; start++) {
        // start is the cow that starts with the disease
        if (state[start] == '0') {
            // if in the string representing the state of the cows, the starting cow is healthy, then it couldn't have possibly been the starting cow
            continue;
        }
        bool canStart = false;
        for (int k=0; k<=t; k++) {    // a cow could shake hands at most t times, since that's how many interactions there were
            vector<bool> infected(n);   // a boolean vector to keep track of which cows are infected
            vector<int> shakes(n);  // an integer vector to keep track of how many times a given cow has shaken hands
            infected[start] = true;
            for (int time=0; time<=250; time++) {
                if (interaction[time].first != -1) {    // an interaction is present
                    // if the cows are currently infected prior to the shake, increase their number of shakes
                    if (infected[interaction[time].first]) {
                        shakes[interaction[time].first]++;
                    }
                    if (infected[interaction[time].second]) {
                        shakes[interaction[time].second]++;
                    }
                    // this if statement is really long, you could shorten it by storing interaction[time].first and interaction[time].second in new variables
                    if ((infected[interaction[time].first] && shakes[interaction[time].first] <= k) || (infected[interaction[time].second] && shakes[interaction[time].second] <= k)) { // checks if either cow is capable of spreading the disease
                        infected[interaction[time].first] = infected[interaction[time].second] = true;
                    }
                }
            }
            // after all interactions, double check that the infected cows are consistent with the observed state string
            bool ok = true;
            for (int i=0; i<n; i++) {
                if ((infected[i] && state[i] == '0') || (!infected[i] && state[i] == '1')) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                // this is a valid starting cow and K value, so let's update x, y, z
                canStart = true;
                y = min(y, k);
                z = max(z, k);
            }
        }
        if (canStart) {
            x++;
        }
    }

    // print output
    cout << x << " " << y << " ";
    if (z == t) {
        cout << "Infinity" << endl; // notice that if K = t, then any K value larger than t would also work, so t represents infinity
    } else {
        cout << z << endl;
    }

    return 0;
}
