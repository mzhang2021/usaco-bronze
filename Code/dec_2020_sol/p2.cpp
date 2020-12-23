#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++)
        cin >> p[i];

    // left endpoint of photo
    int answer = 0;
    for (int l=0; l<n; l++) {
        int sum = 0;
        vector<bool> seen(1001);
        // right endpoint of photo
        for (int r=l; r<n; r++) {
            // considering the photo from [l, r]
            sum += p[r];
            seen[p[r]] = true;
            int sz = r - l + 1;
            if (sum % sz == 0) {
                int average = sum / sz;
                if (seen[average])
                    answer++;
            }
        }
    }
    cout << answer << endl;

    return 0;
}
