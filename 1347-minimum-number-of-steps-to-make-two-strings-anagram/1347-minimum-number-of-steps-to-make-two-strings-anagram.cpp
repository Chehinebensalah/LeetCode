class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> ms;
        int cc=0,ans=0;
        for(int i=0;i<s.size();i++){
            ms[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(ms[t[i]]==0){
                ans++;
            }else{
                ms[t[i]]--;
                if(ms[t[i]]<0){
                    ans++;
                }
            }
        }
        
        //if(cc==s.size()) return 0;
        return ans;
    }
};