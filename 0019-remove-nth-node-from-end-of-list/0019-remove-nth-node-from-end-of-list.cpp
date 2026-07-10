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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        int count = 0;
        while(temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        n = count-n;
        count=0;
        temp = head;
        ListNode* toDelete;
        if(n==0)
        {
            toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        while(count!=n-1)
        {
            temp = temp->next;
            count++;
        }
        toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;

    }
};