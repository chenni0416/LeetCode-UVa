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
/*
[1,2,3,4,5]
[2,1,4,3,5]
dummy->

[1,2,3,4]
[2,1,4,3]
if head->next->next->next:  
    dummy = head
    head = head->next->next

    dummy-> head->next -> head -> head->next->next

[1,2,3]
[2,1,3]
[1,2]
[2,1]
curr = head
if(curr)
    if head->next->next:
        dummy-> head->next -> head -> head->next->next (3)
        curr = head->next->next 
        prev = head (1)
    else:
        dummy-> head->next -> head -> head->next->next (null)
        

if !head or !head->next: return head
[1]
[1]
[]
[]
*/

// # =====================================================================
// # FAILED TEST CASE LOG:
// # Input:    nums = [3, 2, 4], target = 6
// # Expected: [1, 2]
// # Output:   [0, 0]
// # Why:      Allowed the same element to be used twice (i == j).
// # Fix:      Check `if complement_index != current_index` before returning.
// # =====================================================================

// WRONG:
// FIX: 
// BUG [LOGIC] [EdgeCase] [OffByOne] [TLE] [MLE/Space]

// TRAP:
// FAILED CASE: Input: , Expected:, Got:,
// REASON:
// FIX:

/*
TEST CASE:

*/
/*
42:45
*/


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        // ListNode* curr = head;
        // ListNode* next_node;
        while(prev->next && prev->next->next)
        {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;

            // next_node = curr->next->next;
            // prev->next = curr->next;
            // prev->next->next = curr; //BUG[LOGIC] prev->next->next = curr->next->next = curr = 1
            // prev->next->next->next = next_node;// BUG[LOGIC] curr->next->next = 1 not 3
            // curr = next_node;
            // prev = prev->next->next;

        //     next_node = (curr->next) ? curr->next->next: nullptr;
        //     prev->next = curr->next; //dummy->2
        //     // cout << dummy->next->val;
        //     prev->next->next = curr; //dummy->2->1
        //     // cout << dummy->next->next->val;
        //     // curr = next_node;
        //     prev->next->next->next = next_node; //dummy->2->1->3
        // //    cout << dummy->next->next->next->val;

        //     curr = next_node; //curr = 3
        //     // cout << curr->val;
        //     prev = prev->next->next;//1

        }
        return dummy->next;

    }
};