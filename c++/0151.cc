#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int word_start;
        int word_end;
        int i;
        word_start = 0;
        for (i=s.size()-1; i>=0; i--) {
            if (s.at(i) != ' ') {   
                word_start = i;
                for (;i>=0; i--) {
                    if (s.at(i) == ' ') {
                        if (result.size() != 0) {
                            result.insert(result.cend(), ' ');
                        }
                        for (int k=i+1; k<=word_start; k++) {
                            result.insert(result.cend(), s.at(k));
                        }
                        break;
                    }
                }
                if (i < 0) {
                    if (result.size() != 0) {
                        result.insert(result.cend(), ' ');
                    }
                    for (int k=i+1; k<=word_start; k++) {
                        result.insert(result.cend(), s.at(k));
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "  the  sky is blue  ";
    string result = solution.reverseWords(s);
    printf("[%s]\n", result.c_str());
    return 0;
}
