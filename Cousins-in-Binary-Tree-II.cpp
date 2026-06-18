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
15    TreeNode* replaceValueInTree(TreeNode* root) {
16        root->val = 0;
17        queue<TreeNode*> q;
18        q.push(root);
19        while (!q.empty()) {
20            int n = q.size(), sum = 0;
21            vector<TreeNode*> buf;
22            while (n--) {
23                TreeNode* node = q.front();
24                q.pop();
25                buf.push_back(node);
26                if (node->left) {
27                    q.push(node->left);
28                    sum += node->left->val;
29                }
30                if (node->right) {
31                    q.push(node->right);
32                    sum += node->right->val;
33                }
34            }
35            for (auto node : buf) {
36                int t = sum;
37                if (node->left)
38                    t -= node->left->val;
39                if (node->right)
40                    t -= node->right->val;
41                if (node->left)
42                    node->left->val = t;
43                if (node->right)
44                    node->right->val = t;
45            }
46        }
47        return root;
48    }
49};