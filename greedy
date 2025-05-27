/*
409. Longest Palindrome
Solved
Easy
Topics
premium lock icon
Companies
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/


#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }

    int length = 0;
    bool oddFound = false;

    for (auto& pair : count) {
        if (pair.second % 2 == 0) {
            length += pair.second;
        } else {
            length += pair.second - 1;
            oddFound = true;
        }
    }

    return oddFound ? length + 1 : length;
}

int main() {
    string s1 = "abccccdd";
    cout << "Output: " << longestPalindrome(s1) << endl; // Output: 7

    string s2 = "a";
    cout << "Output: " << longestPalindrome(s2) << endl; // Output: 1

    return 0;
}
