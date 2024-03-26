class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() , ans=1;
        sort(nums.begin(),nums.end());
        if(nums[n-1]<=0){
            return ans;
        }
        int i=0;
        while(i<n){
            if(nums[i]<=0){
                nums.erase(nums.begin()+i);
            }
            else{
                i++;
            }
        }
        if(nums[0]!=1){
            return ans;
        }
        vector<int> h ;
        unordered_map<int,bool> vis;
        for(int i=0;i<n;i++){
            if(vis.find(nums[i])!=vis.end()){
                continue;
            }else{
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