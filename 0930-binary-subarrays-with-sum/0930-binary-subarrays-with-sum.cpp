class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,n=nums.size();
        unordered_map<int,int> m ; 
        m[nums[0]]++;
        ans+=(nums[0]==goal ? 1 :0);
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
            ans+=(nums[i]==goal ? 1 :0);
            ans+=m[nums[i]-goal];
            m[nums[i]]++;
        }
        if(goal ==0 && m.size()==1 && m[0]!=0) return n*(n+1)/2;
        return ans;
    }
};