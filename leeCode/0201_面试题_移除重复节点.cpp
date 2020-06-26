#include <vector>
#include <map>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        table.resize(20001, false);
        table[head->val] = true;

        ListNode* first = head;
        ListNode* second = head->next;
        while (second != nullptr) {
            if (table[second->val]) {
                first->next = second->next;
                second = first->next;
            } else {
                table[second->val] = true;
                first = second;
                second = second->next;
            }
        }
        return head;
    }
private:
    vector<bool> table;
};

int main()
{
    return 0;
}
