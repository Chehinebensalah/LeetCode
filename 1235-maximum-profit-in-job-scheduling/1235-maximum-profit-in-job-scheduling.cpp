class Solution {
public:
    int pickbest(vector<int>& dp,int pos, vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        if(pos==startTime.size()){
            return 0;
        }
        if(dp[pos]!=-1){
            return dp[pos];
        }
        int pickind = lower_bound(startTime.begin(), startTime.end(), endTime[pos]) - startTime.begin();
        int pick = profit[pos] + pickbest(dp,pickind,startTime,endTime,profit);
        int notpick = pickbest(dp,pos+1,startTime,endTime,profit);
        return dp[pos] = max(pick,notpick);
    } 
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        set<pair<int, pair<int, int>>> st;
        
        for(int i=0; i<startTime.size(); i++){
            st.insert({startTime[i], {endTime[i], profit[i]}});
        }
        int i = 0;
        for(auto it: st){
            pair<int, pair<int, int>> p = it;
            startTime[i] = p.first;
            endTime[i] = p.second.first;
            profit[i] = p.second.second;

            i = i + 1;
        }
        vector<int> dp(n+1,-1);
        return pickbest(dp,0,startTime,endTime,profit);
    }
};