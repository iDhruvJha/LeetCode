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
14    void dfs(TreeNode* root, int val, int depth, int currDepth) {
15
16        if (!root)
17            return;
18
19        if (currDepth == depth - 1) {
20
21            TreeNode* leftNode = new TreeNode(val);
22            TreeNode* rightNode = new TreeNode(val);
23
24            leftNode->left = root->left;
25            rightNode->right = root->right;
26
27            root->left = leftNode;
28            root->right = rightNode;
29
30            return;
31        }
32
33        dfs(root->left, val, depth, currDepth + 1);
34        dfs(root->right, val, depth, currDepth + 1);
35    }
36
37    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
38
39        if (depth == 1) {
40            TreeNode* newRoot = new TreeNode(val);
41            newRoot->left = root;
42            return newRoot;
43        }
44
45        dfs(root, val, depth, 1);
46
47        return root;
48    }
49};