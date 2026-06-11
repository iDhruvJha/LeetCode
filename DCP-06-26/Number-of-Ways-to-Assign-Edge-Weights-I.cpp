1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4
5    long long power(long long a, long long b) {
6        long long ans = 1;
7
8        while (b>0) {
9            if (b&1) {
10                ans = (ans*a) % MOD;
11            }
12
13            a = (a*a) % MOD;
14            b >>= 1;
15        }
16
17        return ans;
18    }
19    
20    int assignEdgeWeights(vector<vector<int>>& edges) {
21        int n = edges.size() + 1 ;
22        vector<vector<int>> adj(n+1) ;
23        for(auto e : edges){
24            adj[e[0]].push_back(e[1]) ;
25            adj[e[1]].push_back(e[0]) ;
26        }
27        queue<pair<int,int>> q ;
28        vector<bool> vis(n + 1, false);
29        q.push({1,0});
30        vis[1] = true ;
31
32        int ans = 0 ;
33        while(!q.empty()){
34            auto [node,depth] = q.front() ;
35            q.pop() ;
36            ans = max(ans,depth) ;
37            for(auto it : adj[node]){
38                if(!vis[it]){
39                    vis[it] = true ;
40                    q.push({it,depth+1}) ;
41                }
42            }
43        }
44        return (int)power(2,ans-1) ;
45    }
46};