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
14    bool f(TreeNode* root , long long leftt , long long rightt){
15        if(!root) return true ;
16        if( root -> val <= leftt || root -> val >= rightt ) return false ;
17        return f(root -> left , leftt , root -> val ) && f(root -> right , root -> val , rightt ) ;
18    }
19    bool isValidBST(TreeNode* root) {
20        return f(root,LONG_MIN,LONG_MAX) ;
21    }
22};