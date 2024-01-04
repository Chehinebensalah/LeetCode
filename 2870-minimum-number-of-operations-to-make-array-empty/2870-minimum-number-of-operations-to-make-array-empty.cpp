class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> m ; 
        int ans = 0 , n =nums.size(); 
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto i : m){

            if(i.second<2){
                return -1;
            }
            
            if(i.second %3 == 0){
                ans+=i.second/3;

            }
            else {
                ans+=i.second/3 +1;
            }
           
            
        }
        return ans;
    }
};