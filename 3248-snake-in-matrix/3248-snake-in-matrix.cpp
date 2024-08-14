class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int sc = commands.size(), i = 0, j = 0;
        unordered_map<string, pair<int, int>> pos;
        pos["LEFT"]  = {0, -1};
        pos["RIGHT"] = {0, 1};
        pos["UP"]    = {-1, 0};
        pos["DOWN"]  = {1, 0};

        for (int k = 0; k < sc; k++) {
            i += pos[commands[k]].first;
            j += pos[commands[k]].second;
        }
        return (i * n) + j;
    }
};