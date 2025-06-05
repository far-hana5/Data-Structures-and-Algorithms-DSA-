/*
C. Gellyfish and Flaming Peony
time limit per test2 seconds
memory limit per test512 megabytes
Gellyfish hates math problems, but she has to finish her math homework:

Gellyfish is given an array of n
 positive integers a1,a2,…,an
.

She needs to do the following two-step operation until all elements of a
 are equal:

Select two indexes i
, j
 satisfying 1≤i,j≤n
 and i≠j
.
Replace ai
 with gcd(ai,aj)
.
Now, Gellyfish asks you for the minimum number of operations to achieve her goal.

It can be proven that Gellyfish can always achieve her goal.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤5000
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤5000
) — the length of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤5000
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.

Output
For each test case, output a single integer — the minimum number of operations to achieve her goal.

Example
InputCopy
3
3
12 20 30
6
1 9 1 9 8 1
3
6 14 15
OutputCopy
4
3
3
Note
In the first test case, the following is a way that minimizes the number of operations:

Choose i=3
 and j=2
 and replace a3
 with gcd(a3,a2)=gcd(30,20)=10
, then a
 becomes [12,20,10]
.
Choose i=1
 and j=3
 and replace a1
 with gcd(a1,a3)=gcd(12,10)=2
, then a
 becomes [2,20,10]
.
Choose i=2
 and j=1
 and replace a2
 with gcd(a2,a1)=gcd(20,2)=2
, then a
 becomes [2,2,10]
.
Choose i=3
 and j=1
 and replace a3
 with gcd(a3,a1)=gcd(10,2)=2
, then a
 becomes [2,2,2]
.



*/


#include <bits/stdc++.h>
using namespace std;

// Function to find the distinct prime factors of a number
vector<int> findPrimeFactors(int n) {
    vector<int> tempFactors(9, 0);
    int index = 0;

    if (n % 2 == 0) {
        tempFactors[index++] = 2;
        while (n % 2 == 0) n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            tempFactors[index++] = i;
            while (n % i == 0) n /= i;
        }
    }

    if (n > 2) tempFactors[index++] = n;

    vector<int> primeFactors(index);
    for (int i = 0; i < index; i++) {
        primeFactors[i] = tempFactors[i];
    }

    return primeFactors;
}

// Update dp array with the shortest subsequence logic
void findShortestSubsequence(vector<int>& dp, const vector<int>& a, int startIdx, const vector<int>& primeFactors) {
    int n = a.size();

    for (int j = startIdx; j < n; j++) {
        int bitmask = 0;

        for (int p = 0; p < static_cast<int>(primeFactors.size()); ++p) {
            if (a[j] % primeFactors[p] == 0) {
                bitmask ^= (1 << p);
            }
        }

        int dpSize = dp.size();
        for (int i = 0; i < dpSize; ++i) {
            if (dp[i] == n + 1) continue;
            dp[bitmask & i] = min(dp[bitmask & i], dp[i] + 1);
        }
    }
}

// Function to return the minimum length of a valid subsequence
int getMinimumLengthSubsequence(vector<int>& a) {
    int n = a.size();
    int minLength = n + 1;

    for (int i = 0; i < n - 1; ++i) {
        vector<int> primeFactors = findPrimeFactors(a[i]);
        int factorCount = primeFactors.size();

        vector<int> dp(1 << factorCount, n + 1);
        int allBitsSet = (1 << factorCount) - 1;
        dp[allBitsSet] = 1;

        findShortestSubsequence(dp, a, i + 1, primeFactors);

        minLength = min(minLength, dp[0]);
    }

    return minLength;
}

// Core function to solve each test case
void solve() {
    long long n;
    cin >> n;

    vector<int> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long g = 0;
    for (long long i = 0; i < n; ++i) {
        g = gcd(g, a[i]);
    }

    for (long long i = 0; i < n; ++i) {
        a[i] /= g;
    }

    int shortest = getMinimumLengthSubsequence(a);

    if (count(a.begin(), a.end(), 1) == static_cast<int>(n)) {
        cout << 0 << '\n';
        return;
    }

    long long greaterThanOneCount = 0;
    for (long long i = 0; i < n; ++i) {
        if (a[i] > 1) ++greaterThanOneCount;
    }

    if (shortest != 1) {
        cout << greaterThanOneCount + shortest - 2 << '\n';
    } else {
        cout << greaterThanOneCount << '\n';
    }
}

// Main entry
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
