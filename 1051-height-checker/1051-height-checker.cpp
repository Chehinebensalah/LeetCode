class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ch = heights; 
        int n = heights.size(), c = 0;
        sort(heights.begin(),heights.end()); 
        for(int i=0;i<n;i++) 
            c+=( ch[i]!=heights[i] ? 1 : 0);
        return c; 
    }
};