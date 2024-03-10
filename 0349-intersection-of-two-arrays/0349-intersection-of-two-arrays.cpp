class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        int freq[1003]; 
        memset(freq,0,sizeof(freq)); 
        for(int i=0;i<n1.size();i++) freq[n1[i]]=1;
        vector<int> ans;
        for(int i=0;i<n2.size();i++){
            if(freq[n2[i]]==1){
                freq[n2[i]]=2;
                ans.push_back(n2[i]);
            }
        }
        return ans;
    }
};