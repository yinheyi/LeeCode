/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slower  = head;

        while (true) {
            if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr) {
                return false;
            }
            fast = fast->next->next;
            slower = slower->next;

            if (fast == slower) {
                return true;
            }
        }
    }
};
