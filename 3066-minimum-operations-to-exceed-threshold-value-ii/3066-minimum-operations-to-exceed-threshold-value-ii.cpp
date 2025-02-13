class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; i++)
            pq.push(nums[i]);

        while (pq.top() < k) {
            long long int x = pq.top();
            pq.pop();
            long long int y = pq.top();
            pq.pop();
            cout << x << " " << y << endl;
            pq.push((min(x, y) * 2) + max(x, y));
            ans++;
        }

        return ans;
    }
};