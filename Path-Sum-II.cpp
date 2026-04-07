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
14    vector<vector<int>> ans ;
15    void f( TreeNode* root, int targetSum , vector<int>& curr){
16        if(!root) return ;
17        curr.push_back(root->val) ;
18        if( !root -> left && !root ->right && root -> val == targetSum ){
19            ans.push_back(curr) ;
20        }
21        else{
22            f(root->left,targetSum - root -> val , curr ) ;
23            f(root->right,targetSum - root -> val , curr ) ;
24        }
25        curr.pop_back() ;
26    }
27    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
28        vector<int>curr ;
29        f(root,targetSum,curr) ;
30        return ans ;
31    }
32};