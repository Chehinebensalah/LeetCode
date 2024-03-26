class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() , ans=1;
        sort(nums.begin(),nums.end());
        vector<int> h ;
        unordered_map<int,bool> vis;
        
        
        for(int i=0;i<n;i++){
            if(nums[i]>=1 && !(vis.find(nums[i])!=vis.end())){
                vis[nums[i]]=true;
                h.push_back(nums[i]);
            }
        }
        for(int i=0;i<h.size();i++){
            if(h[i]==ans){
                ans++;
            }else{
                return ans;
            }
        }
        return ans;
    }
};