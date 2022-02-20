from typing import *

class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        length = len(nums)
        for i in range(length):
            nums.append(nums[i])
        return nums

if __name__ == '__main__':
    nums = [1, 2, 1]
    print(Solution().getConcatenation(nums))
