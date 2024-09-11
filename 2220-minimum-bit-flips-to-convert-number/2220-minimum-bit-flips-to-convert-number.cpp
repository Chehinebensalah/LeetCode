class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> bin1(start), bin2(goal);
        string s1 = bin1.to_string(), s2 = bin2.to_string();
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += (s1[i] != s2[i] ? 1 : 0);
        }
        return ans;
    }
};