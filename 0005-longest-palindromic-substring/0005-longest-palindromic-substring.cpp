class Solution {
public:
    bool ispalindrome(const string& s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int mxlen = 1, n = s.size(), start = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (ispalindrome(s, i, j) && (j - i + 1) > mxlen) {
                    mxlen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, mxlen);
    }
};