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
14    int sum = 0 ;
15    void helper(TreeNode* root){
16        if(root -> left){
17            if(root -> left -> left) sum += root -> left -> left -> val ;
18            if(root -> left -> right) sum += root -> left -> right -> val ;
19        }
20        if(root -> right){
21            if(root -> right -> left) sum += root -> right -> left -> val ;
22            if(root -> right -> right) sum += root -> right -> right -> val ;
23        }
24    }
25    void f(TreeNode* root){
26        if(!root) return ;
27        if( root -> val % 2 == 0 ){
28            helper(root) ;
29        }
30        f(root -> left ) ;
31        f(root -> right) ;
32    }
33    int sumEvenGrandparent(TreeNode* root) {
34        if(!root) return 0 ;
35        f(root) ;
36        return sum ;
37    }
38};