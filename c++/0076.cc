#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int s_letter_array[58];
        int t_letter_array[58];
        int left = 0;
        int right = 0;
        int start = -1;
        int length = INT_MAX;
        int valid = 0;
        int need = 0;

        memset(s_letter_array, 0, sizeof(s_letter_array));
        memset(t_letter_array, 0, sizeof(t_letter_array));
        for (int i=0; i<t.size(); i++) {
            t_letter_array[t.at(i)-65]++;
        }
        for (int i=0; i<sizeof(t_letter_array)/sizeof(t_letter_array[0]); i++) {
            if (t_letter_array[i] != 0) {
                need++;
            }
        }
        while(right<s.size()) {
            char c = s.at(right);
            int index = c-65;
            if (t_letter_array[index] != 0) {
                s_letter_array[index]++;
                if (s_letter_array[index] == t_letter_array[index]) {
                    valid++;
                }
            }
            right++;
            while (valid == need) {
                int l = right-left;
                if (l < length) {
                    length = l;
                    start = left;
                }
                index = s.at(left)-65;
                if (t_letter_array[index] != 0) {
                    if (s_letter_array[index] == t_letter_array[index]) {
                        valid--;
                    }
                    s_letter_array[index] -= 1;
                }
                left++;
            }
        }
        if (start < 0) {
            return "";
        }
        return s.substr(start, length);
    }
};


int main() {
    Solution solution;

    string result = solution.minWindow("aa", "aa");
    printf("%s\n", result.c_str());
    return 0;
}