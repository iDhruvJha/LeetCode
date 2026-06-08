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
14    bool f(TreeNode* p , TreeNode* q){
15        if(!p || !q) return p == q ;
16        return (p -> val == q -> val) && f(p->left,q->right) && f(p -> right , q -> left) ;
17    }
18    bool isSymmetric(TreeNode* root) {
19        if(!root) return true ;
20        return f(root -> left,root -> right) ;
21    }
22};