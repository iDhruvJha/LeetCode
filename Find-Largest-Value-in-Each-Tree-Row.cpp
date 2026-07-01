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
14    vector<int> largestValues(TreeNode* root) {
15
16        if (!root)
17            return {};
18
19        vector<int> ans;
20        queue<TreeNode*> q;
21        q.push(root);
22
23        while (!q.empty()) {
24
25            int sz = q.size();
26            int mx = INT_MIN;
27
28            while (sz--) {
29
30                TreeNode* node = q.front();
31                q.pop();
32
33                mx = max(mx, node->val);
34
35                if (node->left)
36                    q.push(node->left);
37
38                if (node->right)
39                    q.push(node->right);
40            }
41
42            ans.push_back(mx);
43        }
44
45        return ans;
46    }
47};