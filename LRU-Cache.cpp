1class LRUCache {
2public:
3    class Node{
4        public: 
5            int key;
6            int val;
7            Node* prev;
8            Node* next;
9
10            Node(int key, int val){
11                this->key = key;
12                this->val = val;
13            }
14    };
15
16    Node* head = new Node(-1, -1);
17    Node* tail = new Node(-1, -1);
18
19    int cap;
20    unordered_map<int, Node*> m;
21
22    LRUCache(int capacity) {
23        cap = capacity;
24        head -> next = tail;
25        tail -> prev = head;
26    }
27
28    void addNode(Node* newnode){
29        Node* temp = head -> next;
30
31        newnode -> next = temp;
32        newnode -> prev = head;
33
34        head -> next = newnode;
35        temp -> prev = newnode;
36    }
37
38    void deleteNode(Node* delnode){
39        Node* prevv = delnode -> prev;
40        Node* nextt = delnode -> next;
41
42        prevv -> next = nextt;
43        nextt -> prev = prevv;
44    }
45    
46    int get(int key) {
47        if(m.find(key) != m.end()){
48            Node* resNode = m[key];
49            int ans = resNode -> val;
50
51            m.erase(key);
52            deleteNode(resNode);
53            addNode(resNode);
54
55            m[key] = head -> next;
56            return ans;
57        }
58        return -1;
59    }
60    
61    void put(int key, int value) {
62        if(m.find(key) != m.end()){
63            Node* curr = m[key];
64            m.erase(key);
65            deleteNode(curr);
66        }
67
68        if(m.size() == cap){
69            m.erase(tail -> prev -> key);
70            deleteNode(tail -> prev);
71        }
72
73        addNode(new Node(key, value));
74        m[key] = head -> next;
75    }
76};