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
14    unordered_set<int> del;
15    vector<TreeNode*> ans;
16
17    TreeNode* dfs(TreeNode* root) {
18
19        if (!root)
20            return NULL;
21
22        root->left = dfs(root->left);
23        root->right = dfs(root->right);
24
25        if (del.count(root->val)) {
26
27            if (root->left)
28                ans.push_back(root->left);
29
30            if (root->right)
31                ans.push_back(root->right);
32
33            return NULL;
34        }
35
36        return root;
37    }
38
39    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
40
41        for (int x : to_delete)
42            del.insert(x);
43
44        root = dfs(root);
45
46        if (root)
47            ans.push_back(root);
48
49        return ans;
50    }
51};