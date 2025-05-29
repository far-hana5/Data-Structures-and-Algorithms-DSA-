  int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=INT_MIN;
        if(nums.size()==1&& nums[0]==0)return 0;

       for(int i=0;i<nums.size();i++){
        
        if(nums[i]==0){cnt=0;
        
        
        }
        if(nums[i]==1){
         cnt++;
         ans=max(ans,cnt);
        }
       } 
       ans=max(ans,cnt);
       return ans;
    }