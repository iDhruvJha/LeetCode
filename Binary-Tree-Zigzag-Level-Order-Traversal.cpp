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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        vector<vector<int>> ans ;
16        if(!root) return ans ;
17        queue<TreeNode*> q ;
18        q.push(root) ;
19        bool ch = false ;
20        while(!q.empty()){
21            vector<int> t ;
22            int sz = q.size() ;
23            while(sz--){
24                TreeNode* node = q.front() ;
25                q.pop() ;
26                t.push_back(node->val) ;
27                if(node -> left) q.push(node->left) ;
28                if(node -> right) q.push(node -> right ) ;
29            }
30            if(ch){
31                reverse(t.begin(),t.end()) ;
32                ans.push_back(t) ;
33            }
34            else{
35                ans.push_back(t) ;
36            }
37            ch = !ch ;
38        }
39        return ans ;
40    }
41};