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
14    int ans = 0 ;
15    int curr = 0 ;
16    TreeNode* prev = NULL ;
17    vector<int> he ;
18    void f(TreeNode* root){
19        if(!root) return ;
20        f(root -> left) ;
21        if(prev && root -> val == prev -> val){
22            curr++ ;
23        }
24        else{
25            curr = 1 ;
26        }
27
28        if( curr == ans ){
29            he.push_back(root -> val) ; 
30        }
31        else if( curr > ans ){
32            he.clear() ;
33            he.push_back( root -> val) ;
34            ans = curr ;
35        }
36        prev = root ;
37        f(root -> right) ;
38    }
39    vector<int> findMode(TreeNode* root) {
40        f(root) ;
41        return he ;
42    }
43};