#include <bits/stdc++.h>
using namespace std;

// Python or Java - classes

struct Person {
    // attributes
    string name;
    int age;

    // constructor
    Person(string param_name, int age) {
        name = param_name;
        this->age = age;
    }

    void sayName() {
        cout << "My name is " << name << endl;
    }
};

int arr[100000];
//int arr[100000][10][2][2]; multi-dimensional arrays

int main() {
    // int, string, double, long long
    Person human("Max", 17);
    cout << human.name << " is " << human.age << " years old" << endl;
    human.age += 2;
    cout << human.age << endl;

    Person human2("Bob", 50);
    cout << human2.name << " is " << human2.age << endl;
    cout << human.name << " is " << human.age << endl;

    human.sayName();
    human2.sayName();

    // C-style array
    int n;
    cin >> n;

//    vector<int> arr(n);

//    int arr[10] = {};    // this declares an array of size 10
//    for (int i=0; i<10; i++)
//        arr[i] = 0;
    for (int i=0; i<100000; i++)
        cout << arr[i] << " ";
    cout << endl;
//    int sum = 0;
//    for (int i=0; i<=n; i++) {
//        sum += arr[i];
//    }

    return 0;
}
