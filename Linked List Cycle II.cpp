/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 []
 [3,2,0,-4]
 [1,2]
 [1] cycle: 
 [1] no cycle;
 [1,2] no cycle;

 ? slow pos == return pos?
pos:idx/-1/

 
 */
 /*
 NOT PASS: [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40], pos =2
 BUG: [LOGIC]
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or head->next or head->next->next) return null;
        int pos = -1, slow_idx = 0;
        ListNode*fast = head->next->next;
        ListNode*slow = head;
        while(fast)
        {
            if(fast == slow) return slow;
            fast = fast->next->next; //[BUG] fast->next = null?
            slow = slow->next;
        }
        return null;
        
    }
};

// /*
// AC ,TIME: one hour
// */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(!head or !head->next or !head->next->next) return nullptr;
//         int pos = -1, slow_idx = 0;
//         ListNode*fast = head->next->next;
//         // ListNode*slow = head;//[BUG]
//         ListNode*slow = head->next;//[FIX]

//         while(fast)
//         {
//             // cout << fast->val << ", "<< slow->val << "\n";
//             if(fast == slow) //[FIX]
//             {
//                 // cout << "fast==slow\n";
//                 ListNode* ans = head;
//                 while(ans != slow)
//                 {
//                     // cout << ans->val << ", "<< slow->val << "\n";
//                     slow = slow->next;
//                     ans = ans->next;
//                 }
//                 return ans;
//             }
//             if(!fast->next) return nullptr;
//             fast = fast->next->next; //[BUG] fast->next = null?
//             slow = slow->next;
//         }
//         return nullptr;
        
//     }
// };

/*
AC

*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next or !head->next->next) return nullptr;
        int pos = -1, slow_idx = 0;
        ListNode*fast = head->next->next;
        // ListNode*slow = head;//[BUG]
        ListNode*slow = head->next;//[FIX]

        while(fast)
        {
            // cout << fast->val << ", "<< slow->val << "\n";
            if(fast == slow) //[FIX]
            {
                // cout << "fast==slow\n";
                ListNode* ans = head;
                while(ans != slow)
                {
                    // cout << ans->val << ", "<< slow->val << "\n";
                    slow = slow->next;
                    ans = ans->next;
                }
                return ans;
            }
            if(!fast->next) return nullptr;
            fast = fast->next->next; //[BUG] fast->next = null?
            slow = slow->next;
        }
        return nullptr;
        
    }
};