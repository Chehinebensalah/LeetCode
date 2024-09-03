class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        string calculated = "";
        bool ok = true;
        for (int i = 0; i < s.size(); i++) {
            calculated = calculated + to_string(s[i] - 'a' + 1);
        }
        k--;
        while (k) {
            ans = 0;
            int n = calculated.size();
            for (int i = 0; i < n; i++) {
                ans += (calculated[i] - '0');
            }
            calculated = to_string(ans);
            k--;
        }
        ans = 0;
        for (int i = 0; i < calculated.size(); i++) {
            ans += (calculated[i] - '0');
        }
        return ans;
    }
};