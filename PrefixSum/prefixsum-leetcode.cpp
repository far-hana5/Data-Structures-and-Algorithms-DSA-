class NumArray {
private:
    vector<int>prefixsum;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefixsum.resize(n+1,0);

        for(int i=0;i<n;i++){
            prefixsum[i+1]=prefixsum[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixsum[right+1]-prefixsum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */