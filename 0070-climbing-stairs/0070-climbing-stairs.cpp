class Solution {
public:
    
    int climbStairs(int n) {
        int dp[47];
        if(n<=3){
            return n;
        }
        for(int i=0;i<=3;i++){
            dp[i]=i;
        }
        for(int i=4;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
// 1 1
// 2 2 
// 3 3
// 4 5
// 5 8
// 6 13
// 7 21