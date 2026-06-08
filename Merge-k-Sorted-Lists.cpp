1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    struct compare {
14        bool operator()(ListNode* a, ListNode* b) {
15            return a->val > b->val; // make min-heap
16        }
17    };
18    ListNode* mergeKLists(vector<ListNode*>& lists) {
19
20        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
21        for (auto node : lists) {
22            if (node)
23                pq.push(node);
24        }
25        ListNode* dummy = new ListNode(0);
26        ListNode* temp = dummy;
27
28        while (!pq.empty()) {
29            auto node = pq.top();
30            pq.pop();
31
32            temp->next = node;
33            temp = temp->next;
34
35            if (node->next)
36                pq.push(node->next);
37        }
38
39        return dummy->next;
40    }
41};