1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4        int n = numCourses;
5        vector<int> indegree(n,0) ;
6        vector<vector<int>> adj(n);
7        for (auto it : prerequisites) {
8            adj[it[1]].push_back(it[0]);
9            indegree[it[0]]++;
10        }
11        queue<int>q  ;
12        for (int i = 0; i < n; i++) {
13            if (indegree[i] == 0) {
14                q.push(i);
15            }
16        }
17        vector<int> topo;
18        while (!q.empty()) {
19            int node = q.front();
20            q.pop();
21            topo.push_back(node);
22            for (auto it : adj[node]) {
23                indegree[it]--;
24                if (indegree[it] == 0) {
25                    q.push(it);
26                }
27            }
28        }
29        return n == topo.size();
30    }
31};
32
33// class Solution {
34// public:
35//     void dfs( int node , vector<int>& vis , vector<vector<int>>& adj ,
36//     stack<int>& st){
37//         vis[node] = 1 ;
38//         for(auto it : adj[node]){
39//             if(!vis[it]){
40//                 dfs(it,vis,adj,st) ;
41//             }
42//         }
43//         st.push(node) ;
44//     }
45//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
46//         int n = numCourses  ;
47//         vector<vector<int>> adj(n) ;
48//         vector<int> vis(n,0) ;
49//         for(auto it : prerequisites ){
50//             adj[it[0]].push_back(it[1]) ;
51//         }
52//         stack<int> st ;
53//         for( int i = 0 ; i < n ; i++ ){
54//             if(!vis[i]){
55//                 dfs(i,vis,adj,st) ;
56//             }
57//         }
58//         return n == st.size() ;
59//     }
60// };