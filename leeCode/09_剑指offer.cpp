#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (stack2.empty())
        {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int temp = stack2.top();
            stack2.pop();
            return temp;
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    return 0;
}
