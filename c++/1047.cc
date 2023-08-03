#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        for (int i=0; i<s.size(); i++) {
            if(st.size() > 0 && st.back() == s.at(i)) {
                st.pop_back();
            } else {
                st.push_back(s.at(i));
            }
        }
        return string(st.begin(), st.end());
    }
};

int main() {
    Solution solution;
    string s = "abbaca";
    string result = solution.removeDuplicates(s);
    printf("result = %s\n", result.c_str());
    return 0;
}
