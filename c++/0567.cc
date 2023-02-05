class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int base = 97;
        int s1_letter_map[26];
        int s2_letter_map[26];
        int left = 0;
        int right = 0;
        int valid = 0;
        int need = 0;
        memset(s1_letter_map, 0, sizeof(s1_letter_map));
        memset(s2_letter_map, 0, sizeof(s2_letter_map));
        for (int i=0; i<s2.size(); i++) {
            int index = s2.at(i);
            s2_letter_map[index-base] += 1;
        }
        for (int i=0; i<sizeof(s2_letter_map)/sizeof(s2_letter_map[0]); i++) {
            if (s2_letter_map[i] != 0) {
                need++;
            }
        }
        while(right < s2.size()) {
            char c = s1.at(right);
            int index = c-base;
            right++;
            if (s2_letter_map[index] != 0) {
                s1_letter_map[index]++;
                if (s1_letter_map[index] == s2_letter_map[index]) {
                    valid++;
                }
            }
            while(valid == need) {
                if (right-left == s2.size()) {
                    return true;
                }
                index = s1.at(left);
                if (s2_letter_map[index] != 0) {
                    if (s1_letter_map[index] == s2_letter_map[index]) {
                        valid--;
                    }
                    s1_letter_map[index]--;
                }
                left++;
            }
        }
        return false;
    }
};
