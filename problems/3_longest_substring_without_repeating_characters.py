
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        current_string = []
        current_set = set()
        candidate_string = []
        for c in s:
            if c in current_set:
                if len(current_string) > len(candidate_string):
                    candidate_string = current_string
                current_set = set([c])
                tmp = current_string
                current_string = [c]
                tmp.reverse()
                for x in tmp:
                    if x in current_set:
                        break
                    else:
                        current_string.append(x)
                        current_set.add(x)
                current_string.reverse()
            else:
                current_string.append(c)
                current_set.add(c)
        if len(current_string) > len(candidate_string):
            candidate_string = current_string
        return ''.join(candidate_string)

    def lengthOfLongestSubstring2(self, s):
        """
        :type s: str
        :rtype: int
        """
        current_dict = dict()
        nums = 0
        start = 0
        max_length = 0
        for index, c in enumerate(s):
            if c in current_dict:
                if nums > max_length:
                    max_length = nums
                current_character_index = (current_dict[c] + 1)
                nums = min(index - current_character_index + 1, nums + 1)
                current_dict[c] = index
            else:
                nums += 1
                current_dict[c] = index
        if nums > max_length:
            max_length = nums
        return max_length


if __name__ == '__main__':
    s = "abcabcbb"
    print(Solution().lengthOfLongestSubstring(s))
    s = "bbbbb"
    print(Solution().lengthOfLongestSubstring(s))
    s = "pwwkew"
    print(Solution().lengthOfLongestSubstring(s))
    s = "dvdf"
    print(Solution().lengthOfLongestSubstring(s))
    s = "abba"
    print(Solution().lengthOfLongestSubstring(s))
    s = "abcabcbb"
    print(Solution().lengthOfLongestSubstring2(s))
    s = "bbbbb"
    print(Solution().lengthOfLongestSubstring2(s))
    s = "pwwkew"
    print(Solution().lengthOfLongestSubstring2(s))
    s = "dvdf"
    print(Solution().lengthOfLongestSubstring2(s))
    s = "abba"
    print(Solution().lengthOfLongestSubstring2(s))
