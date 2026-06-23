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
13    ListNode* reverseEvenLengthGroups(ListNode* head) {
14        ListNode dummy(0);
15        dummy.next = head;
16
17        ListNode* prev = &dummy;
18        ListNode* temp = head;
19
20        int count = 1;
21
22        while (temp) {
23            ListNode* groupStart = temp;
24
25            int len = 0;
26            while (temp && len < count) {
27                temp = temp->next;
28                len++;
29            }
30
31            if (len % 2 == 0) {
32                ListNode* curr = groupStart;
33                ListNode* nxt = temp;
34                ListNode* p = temp;
35
36                for (int i = 0; i < len; i++) {
37                    ListNode* forward = curr->next;
38                    curr->next = p;
39                    p = curr;
40                    curr = forward;
41                }
42
43                prev->next = p;
44                prev = groupStart;
45            } else {
46                prev = groupStart;
47                for (int i = 1; i < len; i++) {
48                    prev = prev->next;
49                }
50            }
51
52            count++;
53        }
54
55        return dummy.next;
56    }
57};