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
14    pair<int,int> f(TreeNode* root , int& count ){
15        if(!root) return {0,0} ;
16        auto leftt = f(root->left,count) ;
17        auto rightt = f(root->right,count) ;
18        int value = leftt.first + rightt.first + root -> val ;
19        int n = leftt.second + rightt.second + 1 ;
20        if( value/n == root -> val) count++ ;
21        return { value , n } ;
22    }
23    int averageOfSubtree(TreeNode* root) {
24        int count = 0 ;
25        f(root,count) ;
26        return count ;
27    }
28};