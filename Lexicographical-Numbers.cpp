1class Solution {
2public:
3    vector<int> ans;
4
5    void dfs(int curr, int n) {
6
7        if (curr > n)
8            return;
9
10        ans.push_back(curr);
11
12        for (int i = 0; i <= 9; i++) {
13
14            int next = curr * 10 + i;
15
16            if (next > n)
17                return;
18
19            dfs(next, n);
20        }
21    }
22
23    vector<int> lexicalOrder(int n) {
24
25        for (int i = 1; i <= 9; i++)
26            dfs(i, n);
27
28        return ans;
29    }
30};