class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pn = pref.size() , ans = 0; 
        for(auto word : words ){
            ans += (word.substr(0,pn) == pref ? 1 : 0);
        }

        
        return ans;
    }
};