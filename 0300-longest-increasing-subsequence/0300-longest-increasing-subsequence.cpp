class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), dp[n],res=-1;

        for(int i=0;i<n;i++) dp[i]=1;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    res = max(res,dp[i]);
                }
            }
        }
        if(res==-1){
            return 1;
        }
        return res;
        
    }
};