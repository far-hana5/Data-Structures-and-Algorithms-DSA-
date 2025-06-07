#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Step 1: Find the intersection point of the two runners.
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Step 2: Find the entrance to the cycle.
    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<int> nums1 = {1, 3, 4, 2, 2};
    vector<int> nums2 = {3, 1, 3, 4, 2};
    vector<int> nums3 = {3, 3, 3, 3, 3};

    cout << "Output 1: " << findDuplicate(nums1) << endl;  // Output: 2
    cout << "Output 2: " << findDuplicate(nums2) << endl;  // Output: 3
    cout << "Output 3: " << findDuplicate(nums3) << endl;  // Output: 3

    return 0;
}
