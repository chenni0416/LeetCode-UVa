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
Time:
Case:
0+0
11+1
1+11
111+1
243+564
99+9
9+99
999+9
Logic:
l1 >= l2
1. l1 && l2: add+carry, l1->val = add%10, carry = add/10
2. l1 && !l2: l1->val+carry, 
*/
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

//FIRST
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0, l1);
        ListNode* curr = dummy->next;
        int carry = 0, value =0;
        // while(l1 or l2)
        // {
        //     value = (l1 && l2) ? (l1->val + l2->val + carry) :( (l1) ? (l1->val + carry) : (l2->val + carry));
        //     carry = value/10;
        //     curr->val = value%10;
        //     l1 = (l1) ? l1->next : l1;
        //     l2 = (l2) ? l2->next : l2;
        //     curr = curr->next;
        // }
        cout << curr->val << "->"; //[BUG]
        while(l1 and l2)
        {
            value = l1->val + l2->val + carry;
            carry = value/10;
            curr->val = value%10;
            curr = (curr->next) ? curr->next : curr; //[BUG]
            cout << curr->val<< "->";
            l1 = l1->next;
            l2 = l2->next;

        }

        // if(l1)
        // {
            while(l1)
            {            
                value = l1->val + carry;
                carry = value/10;
                curr->val = value%10;
                curr = (curr->next) ? curr->next : curr; //[BUG]
                l1 = l1->next;
            }
            while(l2)
            {       
                value = l2->val + carry;
                carry = value/10;
                l2->val = value%10;
                curr->next = l2;     
                curr = curr->next;
                l2 = l2->next;

            }
            if(carry) curr->next = new ListNode(1);
        // }
        
        // else if (l2)
        // {
        //     while(l1)
        //     {            
        //         value = l1->val + carry;
        //         carry = value/10;
        //         curr->val = value%10;
        //         curr = curr->next;
        //     }
        // }


        return dummy->next;
    }
};

//SECOND: Faster 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0, l1);
        ListNode* curr = dummy;
        int carry = 0, value =0;
        while(l1 and l2)
        {
            curr = curr->next;
            value = l1->val + l2->val + carry;
            carry = value/10;
            curr->val = value%10;
            l1 = l1->next;
            l2 = l2->next;
        }

        // if(l1)
        // {
            while(l1)
            {        
                curr = curr->next;
                value = l1->val + carry;
                carry = value/10;
                curr->val = value%10;
                l1 = l1->next;
            }
            while(l2)
            {       
                value = l2->val + carry;
                carry = value/10;
                l2->val = value%10;
                curr->next = l2;     
                curr = curr->next;
                l2 = l2->next;

            }
            if(carry) curr->next = new ListNode(1);
        // }
        
        // else if (l2)
        // {
        //     while(l1)
        //     {            
        //         value = l1->val + carry;
        //         carry = value/10;
        //         curr->val = value%10;
        //         curr = curr->next;
        //     }
        // }


        return dummy->next;
    }
};