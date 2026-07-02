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
14    unordered_map<string,int> mp;
15    vector<TreeNode*> ans;
16
17    string dfs(TreeNode* root){
18
19        if(!root)
20            return "#";
21
22        string left = dfs(root->left);
23        string right = dfs(root->right);
24
25        string curr = to_string(root->val) + "," + left + "," + right;
26
27        mp[curr]++;
28
29        if(mp[curr] == 2)
30            ans.push_back(root);
31
32        return curr;
33    }
34
35    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
36
37        dfs(root);
38
39        return ans;
40    }
41};