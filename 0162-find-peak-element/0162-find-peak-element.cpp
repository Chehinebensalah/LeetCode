class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(),ans=-1,mx=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>=mx){
                ans=i;
                mx=nums[i];
            }
        }
        return ans;
    }
};