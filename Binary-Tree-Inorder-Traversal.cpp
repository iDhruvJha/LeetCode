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
14    void f(TreeNode* root,vector<int>& inorder){
15        if(!root) return ;
16        f(root -> left,inorder) ;
17        inorder.push_back(root -> val) ;
18        f(root -> right , inorder) ;
19    }
20    vector<int> inorderTraversal(TreeNode* root) {
21        vector<int> inorder ;
22        f(root,inorder) ;
23        return inorder ;
24    }
25};