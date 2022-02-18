from typing import *

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = [0]*len(nums)
        for i, e in enumerate(nums):
            ans[i] = nums[nums[i]]
        return ans

if __name__ == '__main__':
    nums = [5,0,1,2,3,4]
    print(Solution().buildArray(nums))