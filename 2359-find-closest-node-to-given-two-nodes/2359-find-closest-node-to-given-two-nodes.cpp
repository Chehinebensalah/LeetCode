class Solution {
public:
    void bfs(vector<int>& edges, int node, vector<int>& distance) {
        int n = edges.size();
        bool vis[100001];
        memset(vis, false, sizeof(vis));
        queue<int> q;
        q.push(node);
        vis[node] = true;
        distance[node] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (edges[x] != -1 && !vis[edges[x]]) {
                vis[edges[x]] = true;
                distance[edges[x]] = distance[x] + 1;
                q.push(edges[x]);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2)
            return node2;
        int n = edges.size();
        vector<int> distances_from_node1(n, -1);
        vector<int> distances_from_node2(n, -1);
        bfs(edges, node1, distances_from_node1);
        bfs(edges, node2, distances_from_node2);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (distances_from_node1[i] != -1) {
                m[i] = distances_from_node1[i];
            }
        }
        int cmp = INT_MAX, result_node = -1;
        for (int i = 0; i < n; i++) {
            if (distances_from_node2[i] != -1 && m.find(i) != m.end()) {
                if (cmp >= max(m[i] , distances_from_node2[i])) {
                    result_node = i;
                    cmp = max(m[i] , distances_from_node2[i]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (distances_from_node2[i] != -1 && m.find(i) != m.end()) {
                if (cmp == max(m[i] , distances_from_node2[i])) {
                    if(result_node > i) result_node = i;
                }
            }
        }

        return result_node;
    }
};

/*
0 , 2
1 , 2
2 , 3
3 ,-1

*/