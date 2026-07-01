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
14    TreeNode* removeLeafNodes(TreeNode* root, int target) {
15
16        if(root == NULL)
17            return NULL;
18
19        root->left = removeLeafNodes(root->left, target);
20        root->right = removeLeafNodes(root->right, target);
21
22        if(root->left == NULL &&
23           root->right == NULL &&
24           root->val == target)
25            return NULL;
26
27        return root;
28    }
29};