1class Solution {
2public:
3    int countBattleships(vector<vector<char>>& board) {
4
5        int m = board.size();
6        int n = board[0].size();
7
8        int ans = 0;
9
10        for(int i = 0; i < m; i++) {
11            for(int j = 0; j < n; j++) {
12
13                if(board[i][j] == '.') continue;
14
15                // Top cell is X
16                if(i > 0 && board[i-1][j] == 'X')
17                    continue;
18
19                // Left cell is X
20                if(j > 0 && board[i][j-1] == 'X')
21                    continue;
22
23                ans++;
24            }
25        }
26
27        return ans;
28    }
29};