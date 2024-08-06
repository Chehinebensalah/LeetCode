class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char, int> um;
        unordered_map<char, int> ums;
        for (int i = 0; i < n; i++) {
            um[word[i]]++;
        }
        int res = 0;
        vector<int> vp;
        for (auto& e : um) {
            vp.push_back(e.second);
        }
        sort(vp.begin(), vp.end(), greater<int>());
        n = vp.size();
        for (int i = 0; i < n; i++) {
            if (i < 8) {
                res += vp[i];
            } else if (i < 16) {
                res += 2 * vp[i];
            } else if (i < 24) {
                res += 3 * vp[i];
            } else {
                res += 4 * vp[i];
            }
        }
        return res;
    }
};