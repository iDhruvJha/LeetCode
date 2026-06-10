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
14    unordered_map<TreeNode*, int> dp;
15    int f(TreeNode* root){
16        if(!root) return 0 ;
17        if(dp.count(root)) return dp[root] ;
18
19        int take = root -> val ;
20        int nottake = f(root -> left) + f(root -> right) ;
21
22        if(root->left){
23            take += f(root -> left -> left) + f(root -> left -> right) ;
24        }
25        if(root -> right){
26            take += f(root -> right -> left) + f(root -> right -> right) ;
27        }
28        return dp[root] = max(nottake,take) ;
29    }
30    int rob(TreeNode* root) {
31        return f(root) ;
32    }
33};