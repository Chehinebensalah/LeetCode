class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> helper ; 
        for(int i=1 ;i<=n;i++){
            helper.push_back(to_string(i)); 
        }
        sort(helper.begin(),helper.end());
        vector<int> ans ; 
        for(int i=0;i<helper.size();i++){
            ans.push_back(stoi(helper[i]));
        }
        return ans; 
    }
};