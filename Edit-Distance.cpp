1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4        int n = word1.size();
5        int m = word2.size();
6        vector<int> prev(m + 1);
7        vector<int> curr(m + 1);
8
9        for (int i = 0; i <= m; i++) {
10            prev[i] = i;
11        }
12        for (int i = 1; i <= n; i++) {
13            curr[0] = i;
14            for (int j = 1; j <= m; j++) {
15                if (word1[i-1] == word2[j-1]) {
16                    curr[j] = prev[j - 1];
17                } else {
18                    curr[j] =
19                        1 + min({prev[j], curr[j - 1], prev[j - 1]});
20                }
21            }
22            prev = curr ;
23        }
24        return prev[m];
25    }
26};