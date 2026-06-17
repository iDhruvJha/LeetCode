1class Solution {
2public:
3    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
4        vector<set<int>> anc(n);
5        vector<int> indegree(n, 0);
6        vector<vector<int>> adj(n);
7
8        for (auto &it : edges) {
9            adj[it[0]].push_back(it[1]);
10            indegree[it[1]]++;
11        }
12
13        queue<int> q;
14
15        for (int i = 0; i < n; i++) {
16            if (indegree[i] == 0)
17                q.push(i);
18        }
19
20        while (!q.empty()) {
21            int node = q.front();
22            q.pop();
23
24            for (auto it : adj[node]) {
25
26                anc[it].insert(node);
27
28                for (auto el : anc[node]) {
29                    anc[it].insert(el);
30                }
31
32                indegree[it]--;
33
34                if (indegree[it] == 0) {
35                    q.push(it);
36                }
37            }
38        }
39
40        vector<vector<int>> ans(n);
41
42        for (int i = 0; i < n; i++) {
43            ans[i] = vector<int>(anc[i].begin(), anc[i].end());
44        }
45
46        return ans;
47    }
48};