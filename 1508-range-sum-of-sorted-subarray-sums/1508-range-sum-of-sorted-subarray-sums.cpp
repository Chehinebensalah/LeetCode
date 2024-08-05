class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarray_sum;
        for (int i = 0; i < n; i++) {
            long long cum_sum = 0;
            for (int j = i; j < n; j++) {
                cum_sum += nums[j];
                subarray_sum.push_back(cum_sum);
            }
        }
        sort(subarray_sum.begin(), subarray_sum.end());
        int res = 0;
        for (int i = left - 1; i < right; i++) {
            res += subarray_sum[i];
        }
        return res;
        //  1 2 3 4
        // 1 // 2 // 3 // 4
        // 1 2 // 1 2 3 // 1 2 3 4
        // 2
    }
};