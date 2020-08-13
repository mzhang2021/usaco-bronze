#include <iostream>
#include <map>
using namespace std;

int main() {
    // indices (keys) can be any data type
    map<string, int> mp;
    mp["Bob"] = 15;
    mp["Sam"] = 19;
    mp["Peter"] += 2;
    cout << mp["Bob"] << endl;	// 15
    cout << mp["Sally"] << endl;	// 0, the default value if a key is not present
    mp["Bob"] += 24;
    cout << mp["Bob"] << endl;	// 39

//    map<string, int> mp;
//    mp["Bessie"]
//    mp["Elsie"]
//    mp["Mildred"]

    cout << mp.size() << endl;
    cout << mp["Tony"] << endl; // <- what's that gonna print?
    cout << mp.size() << endl;  // got bigger

    // check if a map contains a key without making our map bigger?
    if (mp["Tony"] != 0) {
        // two problems:
        // 1. we make the map bigger if Tony is not included
        // 2. what if Tony actually is in the map, just with a value of 0?
    }

    // better way:
    if (mp.count("Steven")) {
        cout << "YES" << endl;
    }
    cout << mp.size() << endl;

    mp.erase("Tony");
    cout << mp.size() << endl;

    // you can get wild!
//    map<int, vector<int>> mp;
//    mp[24].push_back(19);
//    mp[23].push_back(22);
//    mp[24].push_back(15);
//    for (int x : mp[24])
//        cout << x << " ";
//    cout << endl;
//
//    map<vector<int>, int> mp;

    // doesn't map make vectors and arrays obsolete?
    // map<int, int> mp;   // isn't that equivalent to arrays?
    // map operations have a higher time complexity
    // without going into too much detail, map operations have O(log n) time complexity for all operations
    // takeaway:
    // 1. arrays/vectors are still superior (O(1) access)
    // 2. the bigger the map, the slower it is, so use .count instead of [] for checking existence
    // http://www.cplusplus.com/reference/map/map/

    for (pair<string, int> p : mp) {
        cout << p.first << ", " << p.second << endl;
    }


    pair<int, int> a(23, 12);
    cout << a.first << endl;
    cout << a.second << endl;

    return 0;
}
