class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        unordered_map<long long int, int> m;
        pq.push(1);
        long long int ans;
        while (n > 0) {
            ans = pq.top();
            pq.pop();
            if (m.find(ans * 2) == m.end()) {
                pq.push(ans * 2);
                m[ans * 2] = 1;
            }
            if (m.find(ans * 3) == m.end()) {
                pq.push(ans * 3);
                m[ans * 3] = 1;
            }
            if (m.find(ans * 5) == m.end()) {
                pq.push(ans * 5);
                m[ans * 5] = 1;
            }
            n--;
        }

        return ans;
    }
};