1class Solution {
2public:
3    bool dfs(int node , vector<vector<int>>& graph , int  col , vector<int>& vis){
4        vis[node] = col ;
5        for(auto it : graph[node]){
6            if(vis[it] == -1){
7                if(!dfs(it,graph,!col,vis)) return false ;
8            }
9            else if( vis[it] == col){
10                return false ;
11            }
12        }
13        return true ;
14    }
15    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
16        vector<vector<int>> graph(n + 1);
17
18        for (auto& it : dislikes) {
19            graph[it[0]].push_back(it[1]);
20            graph[it[1]].push_back(it[0]);   // undirected edge
21        }
22
23        vector<int> vis(n + 1, -1);
24
25        for (int i = 1; i <= n; i++) {
26            if (vis[i] == -1) {
27                if (!dfs(i, graph, 0, vis))
28                    return false;
29            }
30        }
31
32        return true;
33    }
34};