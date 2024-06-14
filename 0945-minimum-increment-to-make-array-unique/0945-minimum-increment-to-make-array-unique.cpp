class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                int to_add = nums[i]-nums[i+1]+1;
                ans+=to_add;
                nums[i+1]+=to_add;
            }
        }
        return ans;
    }
};