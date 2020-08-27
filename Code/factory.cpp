#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> out(n); // for each station, how many outgoing conveyor belts does it have?
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        out[a]++;
    }

    int numZero = 0;    // number of stations with no outgoing conveyor belts
    for (int i=0; i<n; i++) {
        if (out[i] == 0) {
            numZero++;
        }
    }

    if (numZero > 1) {  // can't get from one station with no outgoing conveyor belts to the other
        cout << -1 << endl;
    } else {
        int answer; // find the one station with no outgoing conveyor belts, that's our answer
        for (int i=0; i<n; i++) {
            if (out[i] == 0) {
                answer = i;
            }
        }
        cout << answer + 1 << endl;
    }

    return 0;
}
