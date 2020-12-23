#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums(7);
    for (int i=0; i<7; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    int a = nums[0];
    int b = nums[1];
    int a_plus_b_plus_c = nums[6];
    int c = a_plus_b_plus_c - a - b;
    cout << a << " " << b << " " << c << endl;

    return 0;
}
