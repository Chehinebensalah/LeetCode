class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),c=0,tmpc,ans=0;
        
        if(n<3) return 0;
        
        vector<int> v;
        tmpc=nums[0]-nums[1];
        
        for(int i=0;i<n-1;i++){
            if(nums[i]-nums[i+1]==tmpc){
                c++;
            }else{
                if(c>1){
                    v.push_back(c);
                }
                c=1;
                tmpc=nums[i]-nums[i+1];
            }
        }
        if(c>1) v.push_back(c);
        
        if(v.empty()){
            return 0;
        }
        
        int m = *max_element(v.begin(),v.end()), dp[3+m];
        
        dp[0]=dp[1]=0;
        
        for(int i=2;i<=m;i++){
            dp[i]=i-1+dp[i-1];
        }
        
        for(int i=0;i<v.size();i++){
            ans+=dp[v[i]];
        }
        return ans;
    }
};