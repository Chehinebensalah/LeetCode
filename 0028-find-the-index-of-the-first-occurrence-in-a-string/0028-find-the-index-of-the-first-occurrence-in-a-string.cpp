class Solution {
public:
    int strStr(string haystack, string needle) {
        int nh = haystack.size(), nl = needle.size(); 
        if(haystack==needle) return 0;
        for(int i=0;i<nh-nl;i++){
            if(haystack.substr(i,nl)==needle){
                return i;
            }
        }
        return -1; 
    }
};