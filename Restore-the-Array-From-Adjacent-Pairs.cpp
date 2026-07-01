1class Solution {
2public:
3    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
4
5        unordered_map<int, vector<int>> adj;
6
7        for (auto &it : adjacentPairs) {
8            adj[it[0]].push_back(it[1]);
9            adj[it[1]].push_back(it[0]);
10        }
11
12        int start;
13
14        for (auto &it : adj) {
15            if (it.second.size() == 1) {
16                start = it.first;
17                break;
18            }
19        }
20
21        int n = adjacentPairs.size() + 1;
22        vector<int> ans;
23        ans.reserve(n);
24
25        int prev = INT_MAX;
26        int curr = start;
27
28        while (true) {
29            ans.push_back(curr);
30
31            int next = INT_MAX;
32
33            for (int nei : adj[curr]) {
34                if (nei != prev) {
35                    next = nei;
36                    break;
37                }
38            }
39
40            if (next == INT_MAX)
41                break;
42
43            prev = curr;
44            curr = next;
45        }
46
47        return ans;
48    }
49};