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
15    void f(TreeNode* root , string s ){
16        if(!root){
17            return ;
18        }
19        s += to_string(root->val) ;
20
21        if (!root->left && !root->right) {
22            sum += stoi(s);
23            s.pop_back();
24            return;
25        }
26
27        f(root -> left,s) ;
28        f(root -> right,s) ;
29        s.pop_back() ;
30    }
31    int sumNumbers(TreeNode* root) {
32        string s = "" ;
33        f(root,s) ;
34        return sum ;
35    }
36};