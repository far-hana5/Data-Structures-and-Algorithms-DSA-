/*
A palindrome is a sequence of one or more characters that reads the same from the left as it does from
the right. For example, Z, TOT and MADAM are palindromes, but ADAM is not.
Your job, should you choose to accept it, is to write a program that reads a sequence of strings and
for each string determines the number of UNIQUE palindromes that are substrings.
Input
The input file consists of a number of strings (one per line), of at most 80 characters each, starting in
column 1.
Output
For each non-empty input line, the output consists of one line containing the message:
The string 'input string' contains nnnn palindromes.
where input string is replaced by the actual input string and nnnn is replaced by the number of
UNIQUE palindromes that are substrings.
Note:
See below the explanation of the sample below
• The 3 unique palindromes in ‘boy’ are ‘b’, ‘o’ and ‘y’.
• The 4 unique palindromes in ‘adam’ are ‘a’, ‘d’, ‘m’, and ‘ada’.
• The 5 unique palindromes in ‘madam’ are ‘m’, ‘a’, ‘d’, ‘ada’, and ‘madam’.
• The 3 unique palindromes in ‘tot’ are ‘t’, ‘o’ and ‘tot’.
Sample input
boy
adam
madam
tot
Sample output
The string 'boy' contains 3 palindromes.
The string 'adam' contains 4 palindromes.
The string 'madam' contains 5 palindromes.
The string 'tot' contains 3 palindromes.
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue; // skip empty lines

        set<string> uniquePalindromes;

        int len = line.length();
        // Generate all substrings
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                string sub = line.substr(i, j - i + 1);
                if (isPalindrome(sub)) {
                    uniquePalindromes.insert(sub);
                }
            }
        }

        cout << "The string '" << line << "' contains " 
             << uniquePalindromes.size() << " palindromes." << endl;
    }

    return 0;
}
