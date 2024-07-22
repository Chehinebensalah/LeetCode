class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> ph;
        int n = names.size();
        for (int i = 0; i < n; i++) {
            ph.push_back({heights[i], names[i]});
        }
        sort(ph.begin(), ph.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 return a.first > b.first; // ">" for descending order
             });
        vector<string> res;
        for (int i = 0; i < n; i++) {
            res.push_back(ph[i].second);
            cout << ph[i].first << " ";
        }
        return res;
    }
};