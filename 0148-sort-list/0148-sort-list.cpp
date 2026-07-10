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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        vector<int> list;
        while(temp!=nullptr) {
            list.push_back(temp->val);
            temp = temp->next;
        }
        sort(list.begin(), list.end());
        temp = head;
        int i = 0;
        while(temp!=nullptr)
        {
            temp->val = list[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};