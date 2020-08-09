#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    // handle input
    int n, m;
    cin >> n >> m;

    vector<int> roadLen, roadSpeed;
    for (int i=0; i<n; i++) {
        int l, s;
        cin >> l >> s;
        roadLen.push_back(l);
        roadSpeed.push_back(s);
    }

    vector<int> bessieLen, bessieSpeed;
    for (int i=0; i<m; i++) {
        int l, s;
        cin >> l >> s;
        bessieLen.push_back(l);
        bessieSpeed.push_back(s);
    }

    /*
    idea: create a vector of size 100 representing the 100 mile road
    label each segment (1 mile long) with the road speed limit and Bessie's speed
    on each segment, if Bessie's speed exceeds the road speed limit, update the answer with the difference
    */
    vector<int> road(100);
    int pos = 0;
    for (int i=0; i<n; i++) {
        // current segments covered: "pos" to "pos + len - 1"
        // notice that I'm using zero-based indexing, so index 0 represents the 1st mile, and index 99 represents the 100th mile
        // also, notice that there are "len" 1 mile segments between "pos" and "pos + len - 1" inclusive
        for (int j=0; j<roadLen[i]; j++) {
            road[pos] = roadSpeed[i];
            pos++;
        }
        // notice that by the end of this for loop, pos will be equal to "old pos + len", which means we've covered "pos" to "pos + len - 1"
    }

    int answer = 0;
    pos = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<bessieLen[i]; j++) {
            if (bessieSpeed[i] > road[pos]) {   // Bessie exceeds the speed limit at this 1 mile road segment!
                answer = max(answer, bessieSpeed[i] - road[pos]);
            }
            pos++;
        }
    }

    // print output
    cout << answer << endl;

    // this is of course not the only way of doing this problem!
    // if you have an alternative solution, feel free to share in the forums

    return 0;
}
