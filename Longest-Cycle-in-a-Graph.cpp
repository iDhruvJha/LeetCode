1class Solution {
2public:
3    int longestCycle(vector<int>& edges) {
4        int n = edges.size();
5        vector<int> vis(n, 0);
6        int ans = -1;
7
8        for (int i = 0; i < n; i++) {
9            if (vis[i]) continue;
10
11            unordered_map<int, int> pos;
12            int node = i;
13            int step = 0;
14
15            while (node != -1 && !vis[node]) {
16                vis[node] = 1;
17                pos[node] = step++;
18                node = edges[node];
19            }
20
21            if (node != -1 && pos.count(node)) {
22                ans = max(ans, step - pos[node]);
23            }
24        }
25
26        return ans;
27    }
28};