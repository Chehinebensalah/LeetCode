class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size(), nb5 = 0, nb10 = 0;
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                nb5++;
            } else if (bills[i] == 10) {
                if (nb5 > 0) {
                    nb10++;
                    nb5--;
                } else {
                    return false;
                }
            } else {
                if (nb10 > 0 && nb5 > 0) {
                    nb10--;
                    nb5--;
                } else if (nb5 > 2) {
                    nb5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};