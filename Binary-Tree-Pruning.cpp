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
14    bool f(TreeNode* root){
15        if(!root) return false ;
16        if(!f(root -> left)){
17            root -> left = NULL ;
18        }
19        if(!f(root -> right)){
20            root -> right = NULL ;
21        }
22        return f(root ->right) || f(root -> left) || root -> val ;
23
24    }
25    TreeNode* pruneTree(TreeNode* root) {
26        f(root) ;
27        if( !root -> val && !root -> left && !root -> right ) return NULL ;
28        return root ;
29    }
30};