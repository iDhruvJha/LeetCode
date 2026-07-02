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
14    struct NodeInfo {
15        bool isBST;
16        int mn, mx;
17        int sum;
18    };
19
20    int ans = 0;
21
22    NodeInfo dfs(TreeNode* root) {
23
24        if (!root)
25            return {true, INT_MAX, INT_MIN, 0};
26
27        NodeInfo left = dfs(root->left);
28        NodeInfo right = dfs(root->right);
29
30        if (left.isBST && right.isBST &&
31            left.mx < root->val &&
32            root->val < right.mn) {
33
34            int currSum = left.sum + right.sum + root->val;
35
36            ans = max(ans, currSum);
37
38            return {
39                true,
40                min(left.mn, root->val),
41                max(right.mx, root->val),
42                currSum
43            };
44        }
45
46        return {false, 0 , 0 , 0 };
47    }
48
49    int maxSumBST(TreeNode* root) {
50        dfs(root);
51        return ans;
52    }
53};