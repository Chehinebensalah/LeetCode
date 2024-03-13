class Solution {
public:
    int pivotInteger(int n) {
        int dp[n+1];
        dp[0]=0; 
        for(int i=1;i<n+1;i++){
            dp[i]=dp[i-1]+i;
        }
        for(int i=1;i<n+1;i++){
            int lp = dp[i]-dp[0];
            int rp = dp[n] -dp[i-1];
            if(rp == lp ) return i;
        }
        return -1;
    }
    // 1 2 3 4  5  6  7  8 
    // 1 3 6 10 15 21 28 36
    // we make a prefix sum and we compare the right part which start from 0 to i 
    // and left part from i-1 to n  
    //if we find equal result we return the i index 
    // if not we return -1 ;          
};