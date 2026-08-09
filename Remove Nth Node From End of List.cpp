/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //node for return
 //node of next?
 //node for prev?
 //node->next = node->next->next
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = &dummy;
        int sz = 1;
        while(head->next)
        {
            sz++;
            head = head->next;
        }
        n = sz-n+1;
        while(curr->next)
        {
            // cout << curr->val <<"\n";
            if(--n == 0)
            {
                curr->next = curr->next->next;
                return prev->next;
            }
            curr = curr->next;
        }
        return prev->next;
        
    }
};