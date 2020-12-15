#include <vector>
#include <stack>

using namespace std;

enum State{
    SEARCHING, SEARCHED,
    NOTSEARCH,
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> state(numCourses, NOTSEARCH);
        stack<int> stk;
        for (size_t i = 0; i < state.size(); ++i) {
            if (!DFS(graph, state, stk, i)) {
                return false;
            }
        }
        return true;
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
