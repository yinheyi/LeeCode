class Solution {
public:
    string simplifyPath(string path) {
        vector<string> splite;
        splitString(path, splite);
        vector<string> outputs;
        for (size_t i = 0; i < splite.size(); ++i) {
            if (splite[i] == ".") {
                continue;
            }
            if (splite[i] == "..") {
                if (!outputs.empty()) {
                    outputs.pop_back();
                }
                continue;
            }
            outputs.push_back(splite[i]);
        }

        if (outputs.empty()) {
            return "/";
        }
        string result;
        for (size_t i = 0; i < outputs.size(); ++i) {
            result += "/";
            result += outputs[i];
        }
        return result;
    }

    void splitString(const string& path, vector<string>& output)
    {
        string curStr;
        for (size_t i = 0; i < path.size(); ++i) {
            if (path[i] != '/') {
                curStr.push_back(path[i]);
                continue;
            }

            if (curStr.size() > 0) {
                output.push_back(curStr);
                curStr = "";
            }
        }
        if (curStr.size() > 0) {
            output.push_back(curStr);
        }
    }
};
