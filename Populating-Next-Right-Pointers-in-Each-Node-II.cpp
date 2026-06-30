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
22        if(!root) return NULL ;
23        Node* curr = root ;
24        while(curr){
25            Node* prev = NULL ;
26            Node* head = NULL ;
27            while(curr){
28                if(curr -> left){
29                    if(prev){
30                        prev->next = curr -> left ;
31                    }
32                    else{
33                        head = curr -> left ;
34                    }
35                    prev = curr -> left ;
36                }
37                if(curr -> right){
38                    if(prev){
39                        prev->next = curr -> right ;
40                    }
41                    else{
42                        head = curr -> right ;
43                    }
44                    prev = curr -> right ;
45                }
46                curr = curr -> next ;
47            }
48            curr = head ;
49        }
50        return root ;
51    }
52};