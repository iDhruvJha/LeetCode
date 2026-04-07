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
14    vector<vector<int>> levelOrderBottom(TreeNode* root) {
15        if(!root) return {} ;
16        queue<TreeNode*> q ;
17        vector<vector<int>> ans ;
18        q.push(root) ;
19        while(!q.empty()){
20            int sz = q.size() ;
21            vector<int> temp ;
22            while(sz--){
23                TreeNode* node = q.front() ;
24                q.pop() ;
25                temp.push_back(node->val) ;
26                if(node -> left) q.push(node->left) ;
27                if(node -> right) q.push(node->right) ;
28            }
29            if(temp.size() > 0 ) ans.push_back(temp) ;
30        }
31        reverse(ans.begin(), ans.end()) ;
32        return ans ;
33    }
34};