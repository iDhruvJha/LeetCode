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
14    TreeNode* trimBST(TreeNode* root, int low, int high) {
15
16        if (!root)
17            return NULL;
18
19        if (root->val < low)
20            return trimBST(root->right, low, high);
21
22        if (root->val > high)
23            return trimBST(root->left, low, high);
24
25        root->left = trimBST(root->left, low, high);
26        root->right = trimBST(root->right, low, high);
27
28        return root;
29    }
30};