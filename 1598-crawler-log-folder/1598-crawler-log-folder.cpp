class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0 ;
        string parent = "../" , sfolder ="./";
        for(auto log : logs){
            if(log == sfolder){
                continue;
            }
            else if(log == parent){
                ans--;
            }else {
                ans++;
            }
        }
        return ans < 0 ? 0 : ans;
    }
};