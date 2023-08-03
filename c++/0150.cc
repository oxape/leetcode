#include <string>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for(int i=0; i<tokens.size(); i++) {
            //不做异常检查
            const string &token = tokens[i];
            if (isdigit(token.at(0)) || token.size() > 1) {
                st.push_back(std::stoi(token));
            } else {
                int b = st.at(st.size()-1);
                int a = st.at(st.size()-2);
                int c = 0;
                if (token == "+") {
                    c = a+b;
                } else if (token == "-") {
                    c = a-b;
                } else if (token == "*") {
                    c = a*b;
                } else if (token == "/") {
                    c = a/b;
                }
                st.pop_back();
                st.pop_back();
                st.push_back(c);
            }
        }
        return st.back();
    }
};

int main() {
    initializer_list<string> tokens;
    // tokens = {"2","1","+","3","*"};
    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    vector<string> vec(tokens);
    Solution solution;
    int result = solution.evalRPN(vec);
    printf("result = %d\n", result);
    return 0;
}
