1class Solution {
2public:
3    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
4
5        if (n == 1)
6            return {0};
7
8        vector<vector<int>> adj(n);
9        vector<int> degree(n, 0);
10
11        for (auto &e : edges) {
12            int u = e[0];
13            int v = e[1];
14
15            adj[u].push_back(v);
16            adj[v].push_back(u);
17
18            degree[u]++;
19            degree[v]++;
20        }
21
22        queue<int> q;
23
24        for (int i = 0; i < n; i++) {
25            if (degree[i] == 1)
26                q.push(i);
27        }
28
29        int remainingNodes = n;
30
31        while (remainingNodes > 2) {
32
33            int sz = q.size();
34            remainingNodes -= sz;
35
36            while (sz--) {
37
38                int node = q.front();
39                q.pop();
40
41                for (int nei : adj[node]) {
42
43                    degree[nei]--;
44
45                    if (degree[nei] == 1)
46                        q.push(nei);
47                }
48            }
49        }
50
51        vector<int> ans;
52
53        while (!q.empty()) {
54            ans.push_back(q.front());
55            q.pop();
56        }
57
58        return ans;
59    }
60};