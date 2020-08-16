class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        ListNode* slower = head;
        ListNode* fast = head->next;
        while (fast->next != nullptr) {
            fast = fast->next;
            slower = slower->next;
        }
        slower->next = nullptr;
        fast->next = head->next;
        head->next = fast;
        reorderList(fast->next);
    }
};
