#include <iostream>
#include <vector>
using namespace std;

int main() {
    // step 1: get the input
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;
    // storing all the turns in three vectors
    vector<int> a, b, g;
    for (int i=0; i<n; i++) {
        int a_item, b_item, g_item;
        cin >> a_item >> b_item >> g_item;
        a_item--;   // converting from 1, 2, 3 to 0, 1, 2
        b_item--;
        g_item--;
        a.push_back(a_item);
        b.push_back(b_item);
        g.push_back(g_item);
    }

    // sanity check to see if we took in the input correctly
    /*for (int x : a)
        cout << x << " ";
    cout << endl;
    for (int x : b)
        cout << x << " ";
    cout << endl;
    for (int x : g)
        cout << x << " ";
    cout << endl;*/

    // step 2: simulate for each of three potential pebble starting locations
    // int shell1, shell2, shell3; <- you're gonna be writing a lot of if statements DX
    vector<int> shell(3);   // 0, 1, 2
    int maximum = 0;
    for (int i=0; i<3; i++) {   // iterate over starting locations for pebble
        // say pebble 1 starts in leftmost position
        // shell vector looks like this: [1, 0, 0]
        for (int j=0; j<3; j++) {
            if (i == j) {
                shell[j] = 1;
            } else {
                shell[j] = 0;
            }
        }

        // simulate!
        int score = 0;
        for (int j=0; j<n; j++) {
            // if you want to implement swap on your own:
            // swap(a, b) ->
            // temp = a
            // a = b
            // b = temp
            swap(shell[a[j]], shell[b[j]]);
            if (shell[g[j]] == 1) {
                score++;    // correct guess made!
            }
        }

        maximum = max(maximum, score);  // take maximum of all three scores
    }

    // step 3: produce output!
    cout << maximum << endl;

    return 0;
}
