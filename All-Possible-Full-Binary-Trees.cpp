1class Solution {
2public:
3    unordered_map<int, vector<TreeNode*>> dp;
4
5    vector<TreeNode*> solve(int n) {
6        if (dp.count(n)) return dp[n];
7
8        vector<TreeNode*> res;
9
10        if (n == 1) {
11            res.push_back(new TreeNode(0));
12            return dp[n] = res;
13        }
14
15        if (n % 2 == 0) return res;
16
17        for (int left = 1; left < n; left += 2) {
18            int right = n - 1 - left;
19
20            vector<TreeNode*> leftTrees = solve(left);
21            vector<TreeNode*> rightTrees = solve(right);
22
23            for (auto l : leftTrees) {
24                for (auto r : rightTrees) {
25                    TreeNode* root = new TreeNode(0);
26                    root->left = l;
27                    root->right = r;
28                    res.push_back(root);
29                }
30            }
31        }
32
33        return dp[n] = res;
34    }
35
36    vector<TreeNode*> allPossibleFBT(int n) {
37        return solve(n);
38    }
39};