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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* auxi = new ListNode;
        auxi->next = head;
        qSort(auxi, nullptr);
        return auxi->next;
    }

private:
    void qSort(ListNode* start, ListNode* end) {
        if (start == nullptr | start->next == nullptr || start->next == end) {
            return;
        }

        // 分割
        ListNode* insertNode = start;
        ListNode* curNode = insertNode->next;
        while (curNode != end && curNode->next != nullptr) {
            if (curNode->next->val < insertNode->next->val) {
                ListNode* temp = curNode->next;
                curNode->next = temp->next;
                temp->next = insertNode->next;
                insertNode->next = temp;
            } else {
                curNode = curNode->next;
            }
        }

        // 递归
        if (insertNode == start) {
            qSort(insertNode->next, end);
        } else {
            qSort(start, insertNode);
            qSort(insertNode, end);
        }
    }
};
