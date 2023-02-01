#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    string palindrome(string x, int l, int r) {
        while(l >= 0 && r < x.size()) {
            if (x.at(l) != x.at(r)) {
                break;
            }
            l--;
            r++;
        }
        return x.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        string max_string = "";
        int max=0;
        if (s.size() < 1) {
            return s;
        }
        for (int i=0; i<s.size(); i++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);
            if (s1.size() > s2.size()) {
                if (s1.size() > max) {
                    max = s1.size();
                    max_string = s1;
                }
            } else {
                if (s2.size() > max) {
                    max = s2.size();
                    max_string = s2;
                }
            }
        }
        return max_string;
    }
};


int main() {
    Solution solution;

    string s = "a";
    string result = solution.longestPalindrome(s);
    printf("%s\n", result.c_str());
    return 0;
}