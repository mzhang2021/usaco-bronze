# HW

**Problem 1**: What is the time complexity of the following program? (multiple choice, options on the Google form)

```c++
int X, Y, Z;
cin >> X >> Y >> Z;

int cnt = 0;
for (int i=0; i<X; i++) {
    for (int j=0; j<Y/2; j++) {
        cnt++;
    }
}

cout << cnt << endl;
```

**Problem 2**: If $N = 1000$, which of the following time complexities would be acceptable in order for your program to run under 1 second? (multiple choice, options on the Google form)

**Problem 3**: What is the time complexity of the following function? Why? (free response)

```c++
void magic(vector<int> &a) {
    int n = a.size();
    if (n <= 1)
        return;
    
    vector<int> leftList, rightList;
    for (int i=0; i<n/2; i++) {
        leftList.push_back(a[i]);
    }
    for (int i=n/2; i<n; i++) {
        rightList.push_back(a[i]);
    }
    
    magic(leftList);
    magic(rightList);
    vector<int> b;
    int i = 0, j = 0;
    while (i < leftList.size() && j < rightList.size()) {
        if (leftList[i] < rightList[j]) {
            b.push_back(leftList[i]);
            i++;
        } else {
            b.push_back(rightList[j]);
            j++;
        }
    }
    while (i < leftList.size()) {
        b.push_back(leftList[i]);
        i++;
    }
    while (j < rightList.size()) {
        b.push_back(rightList[j]);
        j++;
    }
    a = b;
}
```

**Note**: the `&` operator means passing by reference, so the function parameter gets modified (revisit lesson 3 if you need a refresher)

Problem 3 is definitely the hardest one, so don't worry if you can't figure it out. We will go over it next class. However, I do expect everyone to get problem 1 and 2.

