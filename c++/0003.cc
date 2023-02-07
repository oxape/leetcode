#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int letter_map[128];
        int left=0;
        int right=0;
        int length = 0;
        int valid_length = 0;
        memset(letter_map, 0, sizeof(letter_map));
        while(right < s.size()) {
            int index = s.at(right);
            letter_map[index]++;
            if (letter_map[index] == 1) {
                valid_length++;
            }
            right++;
            while(letter_map[index] > 1) {
                int index = s.at(left);
                letter_map[index]--;
                left++;
            }
            length = max(length, right-left);
        }
        return length;
    }

    int lengthOfLongestSubstring2(string s) {
        int letter_map[128];
        int n = s.size();
        int max_length = 0;
        int num = 0;
        memset(letter_map, 0, sizeof(letter_map));
        for (int i=0; i<n; i++) {
            int index = s.at(i);
            if (letter_map[index] == 0) {
                num++;
            } else {
                if (max_length < num) {
                    max_length = num;
                }
                /*
                letter_map[index]-1还原index
                ((letter_map[index]-1)+1)为重复字符后一个字符位置
                情况1
                ab-------b
                情况2
                ab-------b---a
                碰到第二个b时num会被设置为第一个b(不包括第一个b)到第二个b之间的长度
                配到第二个a时第一个a(不包括第一个a)到第二个之间长度设为L, 有重复的b，所以不能让num等于L
                这里可以看到num在遇到非重复字符时应该一直递增，只有碰到重复字符才会变小
                */
                num = min(num+1, i-((letter_map[index]-1)+1)+1);
            }
            letter_map[index] = i+1;
        }
        if (max_length < num) {
            max_length = num;
        }
        return max_length;
    }
};

int main() {
    Solution solution;

    int result = solution.lengthOfLongestSubstring2("abba");
    printf("%d ", result);
    return 0;
}
