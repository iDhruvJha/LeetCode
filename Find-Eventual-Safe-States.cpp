1class Solution {
2public:
3    bool dfs(int node , vector<vector<int>>& adj ,
4             vector<int>& vis , vector<int>& path ,vector<int>& check){
5
6        vis[node] = 1;
7        path[node] = 1;
8
9        for(auto it : adj[node]){
10            if(!vis[it]){
11                if(dfs(it,adj,vis,path,check)){
12                    check[it] = 1 ;
13                    return true ;
14                }
15            }
16            else if(path[it]){
17                check[it] = 1 ;
18                return true;
19            }
20        }
21
22        path[node] = 0;
23        return false;
24    }
25    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
26        int V = graph.size() ;
27        vector<int> vis(V,0);
28        vector<int> path(V,0);
29        vector<int> check(V,0) ;
30        for(int i = 0 ; i < V ; i++){
31            if(!vis[i]){
32                if(dfs(i,graph,vis,path,check)){
33                    check[i] = 1 ;
34                }
35            }
36        }
37        vector<int> s ;
38        for(int i = 0 ; i < V ; i++ ){
39            if(!check[i]) s.push_back(i) ;
40        }
41        return s;
42    }
43};