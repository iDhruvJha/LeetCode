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
14    TreeNode* reverseOddLevels(TreeNode* root) {
15        if(!root) return NULL ;
16
17        queue<TreeNode*> q ;
18        q.push(root) ;
19        bool ch = false ;
20        while(!q.empty()){
21            int sz = q.size() ;
22            stack<TreeNode*> st ;
23            vector<int> temp(sz) ;
24            for( int i = 0 ; i < sz ; i++ ){
25                auto node = q.front() ;
26                q.pop() ;
27                st.push(node) ;
28                temp[i] = node -> val ;
29                if(node->left) q.push(node->left) ;
30                if(node->right) q.push(node->right) ;
31            }
32            int i = 0 ;
33            if(ch){
34                while(!st.empty()){
35                    auto it = st.top() ; st.pop() ;
36                    it -> val = temp[i++] ;
37                }
38            }
39            ch =!ch ;
40        }
41        return root ;
42    }
43};