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
15    int sum = 0;
16    pair<int, int> f(TreeNode* root) {
17        if (!root)
18            return {INT_MAX, INT_MIN};
19
20        auto left = f(root->left);
21        auto right = f(root->right);
22
23        int mn = min({root->val, left.first, right.first});
24        int mx = max({root->val, left.second, right.second});
25
26        sum = max(sum, max(abs(root->val - mn), abs(root->val - mx)));
27
28        return {mn, mx};
29    }
30    int maxAncestorDiff(TreeNode* root) {
31        f(root);
32        return sum;
33    }
34};