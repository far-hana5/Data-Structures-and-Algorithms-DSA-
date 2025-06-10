class Solution {
public:
    const int MOD = 1e9 + 7;

    long long maxNonAdjacentSum(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        long long prev2 = 0;
        long long prev1 = max(0, nums[0]);

        for (int i = 1; i < n; ++i) {
            long long take = prev2 + nums[i];
            long long notTake = prev1;
            long long curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        long long total = 0;

        for (const auto& q : queries) {
            int pos = q[0];
            int val = q[1];

            nums[pos] = val;  // update nums at position pos with val
            long long maxSum = maxNonAdjacentSum(nums);
            total = (total + maxSum) % MOD;
        }

        return total;
    }
};
int main() {
    Solution sol;

    vector<int> nums1 = {3, 5, 9};
    vector<vector<int>> queries1 = {{1, -2}, {0, -3}};
    cout << sol.maximumSumSubsequence(nums1, queries1) << endl; // Output: 21

    vector<int> nums2 = {0, -1};
    vector<vector<int>> queries2 = {{0, -5}};
    cout << sol.maximumSumSubsequence(nums2, queries2) << endl; // Output: 0

    return 0;
}
