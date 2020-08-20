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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* yin = new ListNode;
        yin->next = head;
        ListNode* needSort = head;

        while (needSort->next != nullptr) {

            ListNode* insertPos = yin;
            while (insertPos != needSort && insertPos->next->val <= needSort->next->val) {
                insertPos = insertPos->next;
            }

            if (insertPos != needSort) {
                ListNode* moveNode = needSort->next;
                needSort->next = moveNode->next;
                moveNode->next = insertPos->next;
                insertPos->next = moveNode;
            } else {
                needSort = needSort->next;
            }
        }
        return yin->next;
    }
 };
