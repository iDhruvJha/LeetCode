1class Solution {
2public:
3    void dfs(int r , int c , int color , vector<vector<int>>& image , vector<vector<int>>& vis , int ini ){
4        int n = image.size() ;
5        int m = image[0].size() ;
6        vis[r][c] = 1 ;
7        image[r][c] = color ;
8        int dr[4] = {-1,1,0,0} ;
9        int dc[4] = {0,0,-1,1} ;
10        for( int i = 0 ; i < 4 ; i++ ){
11            int nr = r + dr[i] ;
12            int nc = c + dc[i] ;
13            if( nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == ini && !vis[nr][nc]){
14                dfs(nr,nc,color,image,vis,ini) ;
15            }
16        }
17    }
18    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
19        int n = image.size() ;
20        int m = image[0].size() ;
21        vector<vector<int>> vis(n,vector<int>(m,0)) ;
22        dfs(sr,sc,color,image,vis,image[sr][sc]) ;
23        return image ;
24    }
25};