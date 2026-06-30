1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* left;
7    Node* right;
8    Node* next;
9
10    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
11
12    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
13
14    Node(int _val, Node* _left, Node* _right, Node* _next)
15        : val(_val), left(_left), right(_right), next(_next) {}
16};
17*/
18
19class Solution {
20public:
21    Node* connect(Node* root) {
22
23        if(root == NULL)
24            return NULL;
25
26        Node* level = root;
27
28        while(level->left){
29
30            Node* curr = level;
31
32            while(curr){
33
34                curr->left->next = curr->right;
35
36                if(curr->next)
37                    curr->right->next = curr->next->left;
38
39                curr = curr->next;
40            }
41
42            level = level->left;
43        }
44
45        return root;
46    }
47};