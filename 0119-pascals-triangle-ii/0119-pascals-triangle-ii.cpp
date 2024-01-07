class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> res(n+3,vector<int>());
        res[0] = {1};
        res[1] = {1, 1};
        
        for(int i=2;i<=n;i++){
            if(i!=1 || i!=0){
                res[i].resize(i+1,1);
                for(int j = 1 ; j<i;j++){
                    res[i][j]=res[i-1][j-1]+res[i-1][j];
                }
            }
        }
        return res[n];
    }
};