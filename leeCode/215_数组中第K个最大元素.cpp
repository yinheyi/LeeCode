#include <iostream>
#include <vector>

using namespace std;

class MyHeap {
public:
    void push(int element);
    void pop();
    int top();
    size_t size();
private:
    size_t leftChild(size_t parentIndex);
    size_t rightChild(size_t parentIndex);
    size_t parent(size_t childIndex);
    bool isValidIndex(size_t index);
    void HeapifyTopDown(size_t index);
    void HeapifyBottomUp(size_t index);

    std::vector<int> container;
};

void MyHeap::push(int element) {
    container.push_back(element);
    HeapifyBottomUp(container.size() - 1);
}

void MyHeap::pop() {
    if (container.empty()) {
        return;
    }
    swap(container.front(), container.back());
    container.pop_back();
    if (!container.empty()) {
        HeapifyTopDown(0);
    }
}

int MyHeap::top() {
    if (container.empty()) {
        return 0x80000000;
    }
    return container.front();
}

size_t MyHeap::size() {
    return container.size();
}

size_t MyHeap::leftChild(size_t parentIndex) {
    return (parentIndex << 1) + 1;
}

size_t MyHeap::rightChild(size_t parentIndex) {
    return (parentIndex << 1) + 2;
}

size_t MyHeap::parent(size_t childIndex) {
    return (childIndex - 1) >> 1;
}

bool MyHeap::isValidIndex(size_t index) {
    if (container.empty()) {
        return false;
    }
    return index < container.size();
}

void MyHeap::HeapifyTopDown(size_t index) {
    while (true) {
        size_t leftIndex = leftChild(index);
        size_t rightIndex = rightChild(index);
        size_t newIndex = index;
        if (isValidIndex(leftIndex) && container[leftIndex] > container[newIndex]) {
            newIndex = leftIndex;
        }
        if (isValidIndex(rightIndex) && container[rightIndex] > container[newIndex]) {
            newIndex = rightIndex;
        }

        if (newIndex == index) {
            break;
        } else {
            swap(container[index], container[newIndex]);
            index = newIndex;
        }
    }
}

void MyHeap::HeapifyBottomUp(size_t index) {
    while (index != 0) {
        size_t parentIndex = parent(index);
        if (container[parentIndex] >= container[index]) {
            break;
        }
        swap(container[parentIndex], container[index]);
        index = parentIndex;
    }
}


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        MyHeap heap;
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << heap.top() << endl;
            if (heap.size() < k) {
                heap.push(nums[i]);
                continue;
            }
            if (heap.top() <= nums[i]) {
                continue;
            }
            heap.pop();
            heap.push(nums[i]);
        }
        return heap.top();
    }
};

int main() {
    Solution solver;
    vector<int> array1{3, 2, 1, 5, 6, 4 };
    cout << solver.findKthLargest(array1, 1);
    cout << solver.findKthLargest(array1, 2);
    cout << solver.findKthLargest(array1, 3);
    cout << solver.findKthLargest(array1, 4);
    cout << solver.findKthLargest(array1, 5);
    return 0;
}
