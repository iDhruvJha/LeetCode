1class NumMatrix {
2public:
3    vector<vector<int>> prefix ;
4
5    NumMatrix(vector<vector<int>>& matrix) {
6        int n = matrix.size() ;
7        int m = matrix[0].size() ;
8        prefix.resize(n, vector<int>(m));
9        prefix[0][0] = matrix[0][0] ;
10        for( int i = 1 ; i < n ; i++ ){
11            prefix[i][0] = prefix[i-1][0] + matrix[i][0] ;
12        }
13        for( int j = 1 ; j < m ; j++ ){
14            prefix[0][j] = prefix[0][j-1] + matrix[0][j] ;
15        }
16        for( int i = 1 ; i < n ; i++ ){
17            for( int j = 1 ; j < m ; j++ ){
18                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j] ;
19            }
20        }
21    }
22    
23    int sumRegion(int row1, int col1, int row2, int col2) {
24        int ans = prefix[row2][col2] ;
25        if( row1 - 1 >= 0 ) ans -= prefix[row1 - 1][col2] ;
26        if( col1 - 1 >= 0 ) ans -= prefix[row2][col1 - 1] ;
27        if( row1 - 1 >= 0 && col1 - 1 >= 0 ) ans += prefix[row1 - 1][col1 - 1] ;
28        return ans ;
29    }
30};
31
32/**
33 * Your NumMatrix object will be instantiated and called as such:
34 * NumMatrix* obj = new NumMatrix(matrix);
35 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
36 */