#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        const int base = 97;
        int s_letter_map[26];
        int p_letter_map[26];
        int left = 0;
        int right = 0;
        int need = 0;
        int valid = 0;
        int index;
        memset(s_letter_map, 0, sizeof(s_letter_map));
        memset(p_letter_map, 0, sizeof(p_letter_map));
        for (int i=0; i<p.size(); i++) {
            index = p.at(i)-base;
            p_letter_map[index] += 1;
        }
        for (int i=0; i<sizeof(p_letter_map)/sizeof(p_letter_map[0]); i++) {
            if (p_letter_map[i] != 0) {
                need++;
            }
        }
        while(right < s.size()) {
            int index = s.at(right)-base;
            right++;
            if (p_letter_map[index] != 0) {
                s_letter_map[index]++;
                if (s_letter_map[index] == p_letter_map[index]) {
                    valid++;
                }
            }
            while(need == valid) {
                if (right-left==p.size()) {
                    result.push_back(left);
                }
                int index = s.at(left)-base;
                if (p_letter_map[index] != 0) {
                    if (p_letter_map[index] == s_letter_map[index]) {
                        valid--;
                    }
                    s_letter_map[index]--;
                }
                left++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> result = solution.findAnagrams("cbaebabacd", "abc");
    printf("[ ");
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("]\n");
    return 0;
}
