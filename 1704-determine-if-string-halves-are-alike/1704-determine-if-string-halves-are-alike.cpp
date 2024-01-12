class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<int> s1 ,s2;
        vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<s.size()/2;i++){
            vector<char>::iterator it1 = find(v.begin(),v.end(), s[i]);
            vector<char>::iterator it2 = find(v.begin(),v.end(), s[s.size()-1-i]);
            if(it1!=v.end()) s1.push_back(s[i]);
            if(it2!=v.end()) s2.push_back(s[s.size()-1-i]);
        }
        return s1.size()==s2.size();
    }
};