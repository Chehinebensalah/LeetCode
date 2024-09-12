class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c = 0;
        set<char> s;
        for (auto a : allowed) {
            s.insert(a);
        }
        for (auto w : words) {
            bool ok = true;
            for (auto a : w) {
                if (s.find(a) == s.end()) {
                    ok = false;
                }
            }
            if (ok) {
                c++;
            }
        }
        return c;
    }
};