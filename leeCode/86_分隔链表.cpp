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
    ListNode* partition(ListNode* head, int x) {
        ListNode** insertPos = &head;
        while (*insertPos != nullptr && (*insertPos)->val < x) {
            insertPos = &(*insertPos)->next;
        }

        ListNode** deletePos = insertPos;
        while (*deletePos != nullptr && (*deletePos)->val >= x) {
            deletePos = &(*deletePos)->next;
        }

        while (*deletePos != nullptr) {
            if ((*deletePos)->val >= x) {
                deletePos = &(*deletePos)->next;
                continue;
            }

            ListNode* moveNode = *deletePos;
            *deletePos = moveNode->next;
            moveNode->next = *insertPos;
            *insertPos = moveNode;
            insertPos = &moveNode->next;
        }
        return head;
    }
};
