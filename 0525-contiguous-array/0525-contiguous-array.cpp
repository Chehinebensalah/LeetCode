class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), c=0,idx=-1;
        unordered_map<int,int> m; 
        for(int i = 0 ; i<n;i++){
            c+=(nums[i]==1 ? 1 :-1);
            if(!m.count(c)){
                m[c]= i ;
            }
            if (c==0){
                idx = max(idx, i+1);
            }else if(m.count(c)){
                idx = max(idx, i-m[c]);
            }
        }
        return idx;
    }
};

// 0  1  0  0  1  1
// -1 0  -1 -2 -1 0


/*
0   0  0  1  1 1 0
-1 -2 -3 -2 -1 0 

*/