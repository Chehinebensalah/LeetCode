struct ComparePairs {
    bool operator()(const std::pair<int, long long>& a,  // Use long long for distances
                   const std::pair<int, long long>& b) const {
        return a.second > b.second;  // Sort in increasing order of distances
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        int n = p.size();
        vector<pair<int ,long int>> v; 
        for(int i=0;i<n;i++){
            v.push_back(make_pair(i,p[i][0]*p[i][0]+p[i][1]*p[i][1]));
        }
        sort(v.begin(),v.end(),ComparePairs());
        vector<vector<int>> ans ;
        int i =0; 
        while(i<k){
            ans.push_back(p[v[n-1-i].first]);
            i++;
        }  
        return ans;
    }
};