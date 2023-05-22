#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string result;
        int start;
        int i;
        for (start = 0; start+2*k <= s.size(); start += 2*k) {
            for (i=0; i<k; i++) {
                result.insert(result.cend(), s.at(start+k-1-i));
            }
            if (start+k < s.size()) {
                result.insert(result.size(), s, start+k, k);
            }
        }
        if (start < s.size()) {
            if (start+k < s.size()) {
                for (i=0; i<k; i++) {
                    result.insert(result.cend(), s.at(start+k-1-i));
                }
            } else {
                for (i=0; start+i<s.size(); i++) {
                    result.insert(result.cend(), s.at(s.size()-1-i));
                }
            }
            
            if (start+k < s.size()) {
                result.insert(result.size(), s, start+k, k);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    // string s = "abcdefg";
    string s = "k";
    string result = solution.reverseStr(s, 2);
    printf("%s\n", result.c_str());
    return 0;
}