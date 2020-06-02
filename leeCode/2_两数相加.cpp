class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode** cursor = &result;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry == 1) {
            const int l1Value = l1 == nullptr ? 0 : l1->val;
            const int l2Value = l2 == nullptr ? 0 : l2->val;
            *cursor = new ListNode((l1Value + l2Value + carry) % 10);
            cursor = &(*cursor)->next;
            carry = (l1Value + l2Value + carry) / 10;

            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }
        return result;
    }
};

int main()
{
    return 0;
}
