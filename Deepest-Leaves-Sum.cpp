1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    int deepestLeavesSum(TreeNode* root) {
16        if (!root)
17            return 0;
18        queue<TreeNode*> q;
19        q.push(root);
20        int ans = 0;
21        while (!q.empty()) {
22            int sz = q.size(); // current level size
23            int sum = 0;
24
25            for (int i = 0; i < sz; i++) {
26                auto node = q.front();
27                q.pop();
28
29                sum += node->val;
30
31                if (node->left)
32                    q.push(node->left);
33                if (node->right)
34                    q.push(node->right);
35            }
36
37            ans = sum; // last processed level ka sum
38        }
39        return ans;
40    }
41};