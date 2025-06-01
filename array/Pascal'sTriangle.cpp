#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int n) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < n; col++) {
            ans = ans * (n - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            vector<int> temp = generateRow(i);
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    int numRows;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> numRows;

    Solution sol;
    vector<vector<int>> triangle = sol.generate(numRows);

    cout << "Pascal's Triangle:\n";
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
