class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(); 
        int mxd=-1;
        int mnl = arrays[0][0];
        int mxl = arrays[0][arrays[0].size()-1];
        for(int i=1;i<n;i++){
            mxd=max(mxd, max(abs(arrays[i][arrays[i].size()-1] - mnl) , abs(mxl - arrays[i][0] )));
            mnl = min(mnl,arrays[i][0]);
            mxl = max(mxl,arrays[i][arrays[i].size()-1]);
           
        }
        
        return mxd; 
    }
};