class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        map<char, int> vowel;
        vowel['a'] = 1;
        vowel['e'] = 1;
        vowel['i'] = 1;
        vowel['o'] = 1;
        vowel['u'] = 1;

        int n = words.size();
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int s = words[i].size();
            bool check_first_letter = vowel.find(words[i][0]) != vowel.end();
            bool check_last_letter = vowel.find(words[i][s - 1]) != vowel.end();
            cnt[i + 1] = (check_first_letter && check_last_letter ? 1 : 0);
        }

        for (int i = 1; i < n + 1; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans;
        for (auto q : queries) {
            int left = q[0], right = q[1];
            ans.push_back(cnt[right + 1] - cnt[left]);
        }
        return ans;
    }
};
