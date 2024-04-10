class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m[0].size(); 
        vector<vector<int>> m1(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m1[i][j] = m[j][i];
            }
            reverse(m1[i].begin(),m1[i].end());
        }
        m=m1;
    }
};