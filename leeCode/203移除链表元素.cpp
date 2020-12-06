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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode tempNode;
        tempNode.next = head;
        ListNode* cursor = &tempNode;
        while (cursor->next != nullptr) {
            if (cursor->next->val == val) {
                ListNode* toDelete = cursor->next;
                cursor->next = toDelete->next;
                delete toDelete;
            } else {
                cursor = cursor->next;
            }
        }
        return tempNode.next;
    }
};
