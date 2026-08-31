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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;
        int firstCritical = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;

            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = pos;
                }

                // We already found a previous critical point
                if (prevCritical != -1) {
                    minDistance = min(minDistance,
                                      pos - prevCritical);
                }

                prevCritical = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        // Fewer than 2 critical points
        if (firstCritical == -1 || firstCritical == prevCritical) {
            return {-1, -1};
        }

        int maxDistance = prevCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};