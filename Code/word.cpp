#include <iostream>
using namespace std;

int main() {
    // take in input
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int counter = 0;    // represents the number of characters on current line

    for (int i=0; i<n; i++) {
        string word;
        cin >> word;

        if (counter + word.size() > k) {    // we have to create a new line!
            cout << endl << word;
            counter = word.size();  // we create a new line with just the new word
        } else {
            if (i > 0) {    // handles the exception of first word; only print space if there is a word prior to it on same line
                cout << " ";
            }
            cout << word;
            counter += word.size();
        }
    }
    cout << endl;

    // endl creates a new line
}
