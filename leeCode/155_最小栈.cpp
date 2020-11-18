#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
       a.push(x); 
       if (b.empty() || x < b.top()) {
           b.push(x);
       } else {
           b.push(b.top());
       }
    }
    
    void pop() {
       a.pop(); 
       b.pop();
    }
    
    int top() {
       return a.top(); 
    }
    
    int getMin() {
        return b.top();
    }
private:
    stack<int> a;
    stack<int> b;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
