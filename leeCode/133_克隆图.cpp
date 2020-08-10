#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* newNode = new Node;
        searched[node] = newNode;
        DFS(newNode, node);
        return newNode;
    }

    void DFS(Node* newNode, Node* oldNode)
    {
        newNode->val = oldNode->val;
        for (size_t i = 0, size = oldNode->neighbors.size(); i < size; ++i) {
            Node* curNode = oldNode->neighbors[i];
            if (searched.count(curNode) == 0) {
                Node* copyNode = new Node;
                searched[curNode] = copyNode;
                newNode->neighbors.push_back(copyNode);
                DFS(copyNode, curNode);
            } else {
                newNode->neighbors.push_back(searched[curNode]);
            }
        }
    }
private:
    unordered_map<Node*, Node*> searched;
};
