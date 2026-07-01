1class Solution {
2public:
3    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
4
5    int maximumSafenessFactor(vector<vector<int>>& grid) {
6        int n = grid.size();
7
8        // Step 1: Multi-source BFS to compute distance from nearest thief
9        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
10        queue<pair<int,int>> q;
11
12        for(int i = 0; i < n; i++) {
13            for(int j = 0; j < n; j++) {
14                if(grid[i][j] == 1) {
15                    dist[i][j] = 0;
16                    q.push({i, j});
17                }
18            }
19        }
20
21        while(!q.empty()) {
22            auto [x, y] = q.front();
23            q.pop();
24
25            for(auto &d : dirs) {
26                int nx = x + d[0];
27                int ny = y + d[1];
28
29                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
30                   dist[nx][ny] == INT_MAX) {
31                    dist[nx][ny] = dist[x][y] + 1;
32                    q.push({nx, ny});
33                }
34            }
35        }
36
37        // Step 2: Modified Dijkstra (Max Heap)
38        priority_queue<vector<int>> pq;
39        vector<vector<int>> vis(n, vector<int>(n, 0));
40
41        pq.push({dist[0][0], 0, 0});
42
43        while(!pq.empty()) {
44            auto cur = pq.top();
45            pq.pop();
46
47            int safe = cur[0];
48            int x = cur[1];
49            int y = cur[2];
50
51            if(vis[x][y]) continue;
52            vis[x][y] = 1;
53
54            if(x == n - 1 && y == n - 1)
55                return safe;
56
57            for(auto &d : dirs) {
58                int nx = x + d[0];
59                int ny = y + d[1];
60
61                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
62                   !vis[nx][ny]) {
63
64                    pq.push({min(safe, dist[nx][ny]), nx, ny});
65                }
66            }
67        }
68
69        return 0;
70    }
71};