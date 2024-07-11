class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        int m = searchWord.size();
        sort(products.begin(),products.end());
        vector<vector<string>> ans; 
        for(int i=1;i<=m;i++){
            vector<string> h ;
            string s = searchWord.substr(0,i);
            for(int j=0;j<n;j++){
                if(s == products[j].substr(0,i) && h.size()<3){
                    h.push_back(products[j]);
                }
            }
            ans.push_back(h);
        }
        return ans;
    }
};