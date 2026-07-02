1class Solution {
2public:
3    bool dfs(int idx, vector<int>& arr, vector<int>& vis) {
4
5        if (idx < 0 || idx >= arr.size())
6            return false;
7
8        if (vis[idx])
9            return false;
10
11        if (arr[idx] == 0)
12            return true;
13
14        vis[idx] = 1;
15
16        return dfs(idx + arr[idx], arr, vis) ||
17               dfs(idx - arr[idx], arr, vis);
18    }
19
20    bool canReach(vector<int>& arr, int start) {
21
22        vector<int> vis(arr.size(), 0);
23
24        return dfs(start, arr, vis);
25    }
26};