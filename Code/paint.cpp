#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (min(b, d) <= max(a, c)) {   // case 1
        cout << b - a + d - c << endl;
    } else {    // case 2 and 3
        cout << max(b, d) - min(a, c) << endl;
    }

    return 0;
}
