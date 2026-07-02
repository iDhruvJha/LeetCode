1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int widthOfBinaryTree(TreeNode* root) {
15
16        if (!root)
17            return 0;
18
19        long long ans = 0;
20
21        queue<pair<TreeNode*, long long>> q;
22        q.push({root, 0});
23
24        while (!q.empty()) {
25
26            int n = q.size();
27
28            long long first = q.front().second;
29            long long left, right;
30
31            for (int i = 0; i < n; i++) {
32
33                auto curr = q.front();
34                q.pop();
35
36                TreeNode* node = curr.first;
37                long long idx = curr.second - first;
38
39                if (i == 0)
40                    left = idx;
41
42                if (i == n - 1)
43                    right = idx;
44
45                if (node->left)
46                    q.push({node->left, 2 * idx + 1});
47
48                if (node->right)
49                    q.push({node->right, 2 * idx + 2});
50            }
51
52            ans = max(ans, right - left + 1);
53        }
54
55        return ans;
56    }
57};