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
14    int ans = -1 ;
15    int curr = -1 ;
16    void f(TreeNode* root , int level ){
17        if(!root) return ;
18        f(root -> left , level + 1 ) ;
19        f(root -> right , level + 1 ) ;
20        if( level > curr ){
21            ans = root -> val ;
22            curr = level ;
23        }
24    }
25    int findBottomLeftValue(TreeNode* root) {
26        f(root,0) ;
27        return ans ;
28    }
29};