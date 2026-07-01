1class Solution {
2public:
3    vector<vector<int>> adj;
4    vector<int> subtree;
5    vector<int> ans;
6    int n;
7
8    void dfs1(int node, int parent, int depth) {
9
10        ans[0] += depth;
11        subtree[node] = 1;
12
13        for (int child : adj[node]) {
14
15            if (child == parent)
16                continue;
17
18            dfs1(child, node, depth + 1);
19
20            subtree[node] += subtree[child];
21        }
22    }
23
24    void dfs2(int node, int parent) {
25
26        for (int child : adj[node]) {
27
28            if (child == parent)
29                continue;
30
31            ans[child] =
32                ans[node]
33                - subtree[child]
34                + (n - subtree[child]);
35
36            dfs2(child, node);
37        }
38    }
39
40    vector<int> sumOfDistancesInTree(int N,
41                                     vector<vector<int>>& edges) {
42
43        n = N;
44
45        adj.resize(n);
46        subtree.assign(n, 0);
47        ans.assign(n, 0);
48
49        for (auto &e : edges) {
50
51            adj[e[0]].push_back(e[1]);
52            adj[e[1]].push_back(e[0]);
53        }
54
55        dfs1(0, -1, 0);
56
57        dfs2(0, -1);
58
59        return ans;
60    }
61};