#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    // handling input
    int n;
    cin >> n;
    vector<vector<string>> cow(n);
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        for (int j=0; j<k; j++) {
            string s;
            cin >> s;
            cow[i].push_back(s);
        }
    }

    // iterate over all pairs of characteristics for each cow: AB
    for (int i=0; i<n; i++) {
        for (int a=0; a<cow[i].size(); a++) {
            for (int b=0; b<cow[i].size(); b++) {
                if (a != b) {
                    // check for each cow, is there a cow with solely A, is there a cow with solely B?
                    bool onlyA = false, onlyB = false;
                    for (int j=0; j<n; j++) {
                        bool hasA = false, hasB = false;
                        for (int c=0; c<cow[j].size(); c++) {
                            if (cow[i][a] == cow[j][c]) {
                                hasA = true;
                            } else if (cow[i][b] == cow[j][c]) {
                                hasB = true;
                            }
                        }
                        // check if cow is A or cow is B
                        if (hasA && !hasB) {
                            onlyA = true;
                        } else if (!hasA && hasB) {
                            onlyB = true;
                        }
                    }
                    if (onlyA && onlyB) {
                        cout << "no" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "yes" << endl;

    return 0;
}
