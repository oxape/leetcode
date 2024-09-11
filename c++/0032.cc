#include <vector>
#include <string>

using namespace std;
using std::vector;
using std::string;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        for (int i=0; i<s.size(); i++) {
            if (s.at(i) == '(') {
                dp[i] = 0;
            } else {
                if (s.at(i) == ')') {
                    if (i-1 < 0) {
                        continue;
                    }
                    if (s.at(i-1) == '(') {
                        dp[i] = 2;
                        if (i-2 >= 0) {
                            dp[i] += dp[i-2];
                        }
                    } else if (s.at(i-1) == ')') {
                        int left = i-dp[i-1]-1;
                        if (left >= 0 && s.at(left) == '(') {
                            dp[i] = 2+dp[i-1];
                            if (left-1>=0) {
                                dp[i] += dp[left-1];
                            }
                        }
                    }
                }
            }
        }
        int max = 0;
        for (int i=0; i<dp.size(); i++) {
            if (max < dp[i]) {
                max = dp[i];
            }
        }
        return max;
    }
};

int main() {
    Solution solution;

    string s = "()";
    auto result = solution.longestValidParentheses(s);
    printf("%d", result);
    return 0;
}