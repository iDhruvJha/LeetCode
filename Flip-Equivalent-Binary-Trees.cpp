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
14    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
15
16        if (root1 == NULL && root2 == NULL)
17            return true;
18
19        if (root1 == NULL || root2 == NULL)
20            return false;
21
22        if (root1->val != root2->val)
23            return false;
24
25        bool noFlip =
26            flipEquiv(root1->left, root2->left) &&
27            flipEquiv(root1->right, root2->right);
28
29        bool flip =
30            flipEquiv(root1->left, root2->right) &&
31            flipEquiv(root1->right, root2->left);
32
33        return noFlip || flip;
34    }
35};