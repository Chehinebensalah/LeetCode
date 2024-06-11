class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        int n1=a1.size(),n2=a2.size(),ci=0;
        map<int,int> c2;
        vector<int> res;
        for(int i=0;i<n2;i++){
            c2[a2[i]]=0;
        }
        for(int i=0;i<n1;i++){
            if(c2.find(a1[i])!=c2.end()){
                c2[a1[i]]++;
            }else{
                res.push_back(a1[i]);
                ci++;
            }
        }
        for(int i=0;i<n2;i++){
            int cc = c2[a2[i]];
            while(cc){
                res.insert(res.begin(),a2[i]);
                cc--;
            }
        }
        reverse(res.begin(),res.begin()+res.size()-ci);
        sort(res.begin()+res.size()-ci,res.end());
        return res;
    }
};