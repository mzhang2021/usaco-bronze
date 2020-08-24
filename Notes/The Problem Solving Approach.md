# The Problem Solving Approach

## Step 1: Read and understand the problem.

- This might sound stupid and obvious, but you can't solve a problem if you don't know what it's asking
- Make sure you are not misinterpreting the problem
  - There are plenty of times where I have misinterpreted a problem and tried to solve something harder than what the problem was asking
- When reading about story elements in a problem, you should start translating them in your head into more standard things you recognize (e.g. "numbers in an array" instead of "cows in a line")
- Let's walk through an example with the homework problem "[socdist1](http://www.usaco.org/index.php?page=viewproblem2&cpid=1035)":
  - **Paragraph 1:** Nothing important, just a joke about "COWVID-19" in reference to COVID-19
  - **Paragraph 2:** We have $N$ array positions, either $0$ or $1$ (not occupied by a cow, or occupied by a cow). There is a quantity $D$ denoting the minimal difference in positions of any two $1$s in the array
    - For example: if we have the sequence `00100101`, then among all pairs of $1$s in the array, the 2nd and 3rd $1$s are the closest. They are at indices $5$ and $7$ (using zero based indexing) in the array, so $D = 2$
  - **Paragraph 3:** We want to add two extra $1$s in the array to replace existing $0$s. We cannot adjust the position of any existing $1$s in the array. We want to place the two extra $1$s in such a way that the $D$ value of the resulting array is maximized
  - **Paragraph 4:** This is a critical paragraph because it describes the input format
    - We read in one integer, $N$, on the first line of the file
    - We read in a string of $0$s and $1$s on the second line of the file, and we are guaranteed that this string is of length $N$
      - Notice that our string is the array of $0$s and $1$s we described earlier, just in string format
      - Using `[]` still works for getting the value at some position in the string
      - Just be warned, `s[index]` will be of the `char` data type, not `int`
    - We are also guaranteed that there are at least 2 $0$s in the string, which ensures that we will always have an answer
  - **Paragraph 5:** This is also a critical paragraph because it describes the output format
    - We print the largest possible $D$ value achieved after inserting the two new $1$s optimally
  - **Sample Input/Output:** This provides one example of a valid test case for this problem, so that you can test your program before you submit it
  - **Paragraph 6:** This explains the sample test case and how the answer of $2$ is obtained
  - **Scoring:** This was a new addition to USACO problems in 2019-2020 and wasn't on old problems
    - It tells you the input constraints on the test cases so that if you can only think of a suboptimal solution, you will know how much partial credit you can earn

## Step 2: Make observations.

- Chances are, you won't instantaneously know how to solve a problem after reading it
- Start developing ideas, and make observations that can help break down the problem
- **The sample test case is super helpful!** Sometimes walking through the sample test case yourself and seeing how the answer is obtained can give you ideas on solving the problem
- **Diagrams can be super helpful!** For this problem in particular, diagrams aren't really necessary, but on a problem like "[balancing](http://www.usaco.org/index.php?page=viewproblem2&cpid=617)", making a drawing can make subtle things obvious
- Try solving smaller versions of the problem first
  - For example, let's first try adding just one cow
  - `10000001`
  - In the above string, it seems optimal to place the cow somewhere in the middle of the "gap" formed by the two $1$s on the ends:
  - `10001001` or `10010001`
  - This makes sense: if you shift it too far to the left or right from the center, you will get disproportionally closer to one end compared to the other, and since $D$ is the minimal difference between any pair of $1$s, your overall $D$ value will decrease
  - We could have multiple gaps: `10000101001`
  - In that case, maybe we should try placing the $1$ in the biggest gap?
    - Yes, that is optimal! This is because adding a $1$ to any smaller gap will only yield smaller distances from the $1$ we just added to the two endpoints of its gap, and yield a lower $D$ value overall
  - What about gaps on the end? How do we treat those?
  - `00000001`
    - Maybe in the center again?
    - Turns out you want to place on the far end: `10000001`
    - Try to see why!
  - Are there any other cases?
    - Keep scribbling different random configurations on your paper until you have convinced yourself that these are the only cases.

- **Great, but what about two cows?**
  - We can break this into two cases: place both cows in the same gap, or place both cows in separate gaps
  - Same gap: it makes sense to break the gap into "thirds":
  - `1000001` -> `1010101`
  - Different gap: pick the two largest gaps out of all of our gaps
  - `1000001000001001001` -> `1001001001001001001`
  - What about gaps on the end?
  - Answer: `00000001` -> `10010001` or `10001001`

- Are we done?

## Step 3: Figure out the implementation details.

- How will we turn this idea into code?
- Sometimes, it's easy to express an idea on paper and do it as humans, but hard to tell computers to simulate the process
- First, how do we find the gaps?
- Idea: A gap consists of a $1$, followed by a bunch of $0$s, and then a closing $1$
- For each $1$, let's look to the left and right and find the next closest $1$, and the difference between them will give us our gap size
- How can we do this efficiently?
  - Let's use a `for` loop to iterate over our array
  - We save the latest position where a $1$ occurred in some variable named `latestIndex`
  - Now each time we encounter a new $1$, we can match it with our previous occurrence of $1$ stored in `latestIndex`, and that forms a gap
  - We can store all of our gaps inside a vector
  - Here's the code:

```c++
int n;	// length of input string
string s;	// string containing the 0's and 1's
vector<int> gaps;	// a vector that will contain all of our gap sizes
int latestIndex = -1;	// variable described above
for (int i=0; i<n; i++) {
    if (s[i] == '1') {	// use single quotes to denote a character in C++
		if (latestIndex != -1) {
            // we have a gap with i - latestIndex - 1 0s in between
            gaps.push_back(i - latestIndex - 1);
        }
        latestIndex = i;	// update our latestIndex
    }
}
// the above logic is O(N)
```

- **Note: The above code does not account for gaps on the ends (00001 or 10000) properly**
  - How can you deal with that?
  - Maybe use another variable/vector specifically for gaps on the ends of the array?
  - Would appending an extra dummy $1$ on the endpoints work?
- **Note: I highly recommend planning your code out before typing it**
  - If you try to type first and think as you go, you'll end up deleting and retyping a lot, and your code might end up messy

## Step 4: Once you've worked out all the details, go!

- Write the code!
- When you're ready, and you have confirmed it works on the sample test case, submit it and see how many real test cases you get correct!
- In USACO, there is no penalty for submitting an incorrect solution, and you can submit multiple times

## Step 5: What if it doesn't work?

- We have to **debug**
- "In computer programming and software development, **debugging** is the process of finding and resolving bugs (defects or problems that prevent correct operation) within computer programs, software, or systems."
- Errors in code are called bugs because that's what they are: annoying little hindrances that are hard to detect and get rid of
- **Add `cout` statements throughout your program to see values your variables are taking**
- Example:

```c++
int n;
string s;
vector<int> gaps;
int latestIndex = -1;
for (int i=0; i<n; i++) {
    if (s[i] == '1') {
		if (latestIndex != -1) {
            gaps.push_back(i - latestIndex - 1);
        }
        latestIndex = i;
    }
    cout << i << ", " << latestIndex << endl;	// this statement will print the values of latestIndex at each i value, so we can confirm if we are actually finding each and every 1 in the array
}
```

- Test your code in blocks at a time! Don't try to see if the whole thing works at once
  - Basically, comment out everything in your code, then uncomment each section at a time (taking input, computing the gap sizes, etc.)
  - In doing this, you can quickly narrow down which section of your code is problematic
- **Reexamine your logic**
  - Sometimes your code is 100% perfect at executing your idea, but your idea was wrong to begin with!
  - In that case, try to find a **counter test case**, or a test case where your idea fails
  - For example, in the problem "balancing", this [test](https://pastebin.com/raw/uGCUYrKD) case was a counter test case to the strategy of always placing the line at the median
  - Once you know why your idea is wrong, try to see if you can amend the idea
  - Sometimes, you may have to go back to step 2 and start again from scratch, this time taking a different approach
- Keeping your code clean from the start can go a long way in debugging
  - Indent and space your code properly
    - `x = 15;` instead of `x=15;`
  - Use descriptive variable names
    - `latestIndex` instead of `li`
    - **Exception:** variable names like `n` are generally acceptable because they are defined in the problem statement, so if you forget what they mean you can always check
  - Add comments!

## Step 6: Celebrate once you get all correct!

- Congratulations, you've solved the problem!

## Step 7: What if I failed?

- Sometimes, if you can't solve a problem, you can try to get partial credit
- For example, in this problem, $N$ can be as large as $10^5$, but in the scoring section, it says everything up to test case 11 satisfies $N \leq 5000$, which means an $\mathcal{O}(N^2)$ algorithm would work
  - 11/15 test cases is $\sim 73 \%$!
  - If you can solve the other two problems, you will still likely have enough points to promote to the next division!
- If worst comes to worst, you can skip the problem altogether and come back to it later. The contest is 4 hours long, so maybe you'll think of something later!
- **Pro tip:** The first test case is always guaranteed to be the sample test case, so if you just submit a program printing the sample output, you are guaranteed 1 test case, or minimal partial credit.