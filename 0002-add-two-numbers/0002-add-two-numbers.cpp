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
class Solution {
public:
    /*ListNode* reverse(ListNode* l)
    {
        ListNode* curr = l;
        while(curr!=nullptr)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* p1 = reverse(l1);
        // ListNode* p2 = reverse(l2);
        int carry = 0;
        ListNode* tail = new ListNode();
        ListNode* head = tail;
        while (l1 || l2 || carry) {
            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;

            int sum = x + y + carry;

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return head->next;
    }
};