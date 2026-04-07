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
15    void preorder(TreeNode* root, vector<int>& pre) {
16        if (!root)
17            return;
18        pre.push_back(root->val);
19        preorder(root->left, pre);
20        preorder(root->right, pre);
21    }
22    void flatten(TreeNode* root) {
23        if (!root)
24            return;
25        vector<int> pre;
26        preorder(root, pre);
27        TreeNode* temp = root;
28        temp->val = pre[0];
29        temp->left = NULL;
30        for (int i = 1; i < pre.size(); i++) {
31            temp->right = new TreeNode(pre[i]);
32            temp = temp->right;
33            temp->left = NULL;
34        }
35    }
36};