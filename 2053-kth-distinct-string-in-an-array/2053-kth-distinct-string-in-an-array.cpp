class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n =arr.size(),c=1;
        unordered_map<string,int> ump ; 
        for(int i=0;i<n;i++){
           ump[arr[i]]++;
        }
        for(int i = 0;i<n;i++){
            if(ump[arr[i]]==1){
                if(c==k) return arr[i];
                else c++;
            }
        }
        return "";
    }
};