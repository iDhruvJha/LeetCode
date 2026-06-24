1class Solution {
2public:
3    int dp[51][6];
4
5    int f(int len, int n, int ind){
6        if(len == n) return 1;
7        if(ind == 5) return 0;
8
9        if(dp[len][ind] != -1)
10            return dp[len][ind];
11
12        return dp[len][ind] =
13            f(len + 1, n, ind) +
14            f(len, n, ind + 1);
15    }
16
17    int countVowelStrings(int n) {
18        memset(dp, -1, sizeof(dp));
19        return f(0, n, 0);
20    }
21};