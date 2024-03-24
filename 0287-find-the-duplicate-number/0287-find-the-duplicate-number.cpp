class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n =nums.size();
        bool vis[100006];
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++){
            if(vis[nums[i]]) return nums[i];
            vis[nums[i]]=true;
        }
        return -1;
    }
};