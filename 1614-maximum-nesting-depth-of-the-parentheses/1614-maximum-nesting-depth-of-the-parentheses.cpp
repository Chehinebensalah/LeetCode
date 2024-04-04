class Solution {
public:
    int maxDepth(string s) {
        int ans =-1,sum=0,n=s.size(); 
        for(int i=0;i<n;i++){
            if(s[i]=='(') sum++;
            if(s[i]==')') sum--;
            ans=max(ans,sum);
        }
        return max(ans,0);
    }
};