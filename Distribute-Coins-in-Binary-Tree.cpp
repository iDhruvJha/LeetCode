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
14    int f(TreeNode* root , int& moves){
15        if(!root) return 0 ;
16        int leftt = f(root->left,moves) ; int rightt = f(root -> right , moves) ;
17        moves += abs(leftt) + abs(rightt) ;
18        return root -> val + leftt + rightt - 1 ;
19    }
20    int distributeCoins(TreeNode* root) {
21        int moves = 0 ;
22        f(root,moves) ;
23        return moves ;
24    }
25};