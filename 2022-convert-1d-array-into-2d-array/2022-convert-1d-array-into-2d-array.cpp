class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
        int no = original.size();

        if (no != m * n)
            return {};
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> sub_ans;
            for (int j = 0; j <m ; j++) {
                sub_ans.push_back(original[m*i+j]);
            }
            ans.push_back(sub_ans);
        }
        return ans;
    }
};

/*

1 2 3 4 5 6 7 8 9 10 11 12
0 1 2 3 4 5 6 7 8 

1 2 3 0
4 5 6 3
7 8 9 6
10 11 12  9

*/