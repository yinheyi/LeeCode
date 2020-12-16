#include <vector>
#include <stack>

using namespace std;

enum State{
    SEARCHING, SEARCHED,
    NOTSEARCH,
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++degree[prerequisites[i][0]];
        }

        vector<int> state(numCourses, NOTSEARCH);
        stack<int> stk;
        for (size_t i = 0; i < state.size(); ++i) {
            if (degree[i] != 0) {
                continue;
            }

            if (!DFS(graph, state, stk, i)) {
                return vector<int>();
            }
        }

        if (stk.size() != numCourses) {
            return vector<int>();
        }

        vector<int> result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }

private:
    bool DFS(const vector<vector<int>>& graph, vector<int>& state, stack<int>& stk, int curCourse) {
        if (state[curCourse] == SEARCHING) {
            return false;
        }
        
        if (state[curCourse] == SEARCHED) {
            return true;
        }

        state[curCourse] = SEARCHING;
        for (size_t i = 0; i < graph[curCourse].size(); ++i) {
            if (!DFS(graph, state, stk, graph[curCourse][i])) {
                return false;
            }
        }
        stk.push(curCourse);
        state[curCourse] = SEARCHED;
        return true;
    }
}; 
