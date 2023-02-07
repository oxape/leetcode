#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int base = 97;
        int s2_letter_map[26];
        int s1_letter_map[26];
        int left = 0;
        int right = 0;
        int valid = 0;
        int need = 0;
        memset(s2_letter_map, 0, sizeof(s2_letter_map));
        memset(s1_letter_map, 0, sizeof(s1_letter_map));
        for (int i=0; i<s1.size(); i++) {
            int index = s1.at(i);
            s1_letter_map[index-base] += 1;
        }
        for (int i=0; i<sizeof(s1_letter_map)/sizeof(s1_letter_map[0]); i++) {
            if (s1_letter_map[i] != 0) {
                need++;
            }
        }
        while(right < s2.size()) {
            char c = s2.at(right);
            int index = c-base;
            right++;
            if (s1_letter_map[index] != 0) {
                s2_letter_map[index]++;
                if (s2_letter_map[index] == s1_letter_map[index]) {
                    valid++;
                }
            }
            while(valid == need) {
                if (right-left == s1.size()) {
                    return true;
                }
                index = s2.at(left);
                index -= base;
                if (s1_letter_map[index] != 0) {
                    if (s2_letter_map[index] == s1_letter_map[index]) {
                        valid--;
                    }
                    s2_letter_map[index]--;
                }
                left++;
            }
        }
        return false;
    }
};


int main() {
    Solution solution;

    bool result = solution.checkInclusion("ab", "eidbaooo");
    printf("%s\n", result?"true":"false");
    return 0;
}
