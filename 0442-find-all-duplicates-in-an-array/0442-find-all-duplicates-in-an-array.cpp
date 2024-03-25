class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int vis[100009], n=nums.size();
        vector<int> res; 
        memset(vis,0,sizeof(vis)); 
        for(int i = 0;i<n;i++){
            if(vis[nums[i]]==0){
                vis[nums[i]]++;
            }else if(vis[nums[i]]==1){
                res.push_back(nums[i]);
                vis[nums[i]]++;
                
            }else{
                continue;
            }
        }
        return res;
    }
};