class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size(), ans = 0,mx=-1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i+1]++;
                ans++;
            }else if(nums[i]>nums[i+1]){
                cout<<"abs"<<abs(nums[i+1]-nums[i]+1);
                ans+=abs(nums[i+1]-nums[i])+1;
                nums[i+1]+=abs(nums[i+1]-nums[i])+1;
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};