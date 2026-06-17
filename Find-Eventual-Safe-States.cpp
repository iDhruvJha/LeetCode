1class Solution {
2public:
3    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
4        int n = graph.size();
5        vector<int> indegree(n,0) ;
6        vector<vector<int>> adj(n);
7        for (int i = 0 ; i < n ; i++ ) {
8            for(auto it : graph[i]){
9                adj[it].push_back(i) ;
10                indegree[i]++ ;
11            }
12        }
13        queue<int> q  ;
14        for (int i = 0; i < n; i++) {
15            if (indegree[i] == 0) {
16                q.push(i);
17            }
18        }
19        vector<int> topo;
20        while (!q.empty()) {
21            int node = q.front();
22            q.pop();
23            topo.push_back(node);
24            for (auto it : adj[node]) {
25                indegree[it]--;
26                if (indegree[it] == 0) {
27                    q.push(it);
28                }
29            }
30        }
31        sort(topo.begin(),topo.end()) ;
32        return topo ;
33    }
34};