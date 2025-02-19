class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");
        string s = q.front();
        vector<string> v = {"a", "b", "c"};
        if (n == 1 && k <= 3)
            return v[k - 1];
        else
            v.clear();
        while (!q.empty()) {
            q.pop();
            if (s.size() > n)
                break;
            for (auto a : {'a', 'b', 'c'}) {
                if (s[s.size() - 1] != a) {
                    q.push(s + a);
                    if ((s + a).size() == n) {
                        v.push_back(s + a);
                    }
                }
            }
            s = q.front();
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
        return (v.size() < k ? "" : v[k - 1]);
    }
};
