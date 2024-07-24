class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>> m;
        for (auto num : nums) {
            string toint = to_string(num);
            for (int i = 0; i < toint.size(); i++) {
                toint[i] = '0' + mapping[toint[i] - '0'];
            }
            m[stoi(toint)].push_back(num);
        }
        vector<int> res;
        for (auto a : m) {
            for (int i = 0; i < a.second.size(); i++) {
                res.push_back(a.second[i]);
            }
        }
        return res;
    }
};