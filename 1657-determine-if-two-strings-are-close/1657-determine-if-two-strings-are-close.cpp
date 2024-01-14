class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 =word1.size(),n2=word2.size();
        if(n1!=n2){
            return false;
        }
        map<char,int> mw1 ,mw2;
        for(int i=0;i<n1;i++){
            mw1[word1[i]]++;
        }
        for(int i=0;i<n2;i++){
            mw2[word2[i]]++;
        }
        if(mw1.size()!=mw2.size()){
            return false;
        }
        vector<int> v1,v2;
        set<char> s1,s2;
        for(auto a:mw1){
            v1.push_back(a.second);
            s1.insert(a.first);
        }
        for(auto a:mw2){
            v2.push_back(a.second);
            s2.insert(a.first);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return s1==s2;
    }
};