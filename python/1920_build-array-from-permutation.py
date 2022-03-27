from typing import *

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = [0]*len(nums)
        for i, e in enumerate(nums):
            ans[i] = nums[nums[i]]
        return ans
    
    def buildArrayV1(self, nums: List[int]) -> List[int]:
        for i, e in enumerate(nums):
            tmp = nums[i]
            nums[i] = nums[nums[i]]
            nums[nums[i]] = tmp
        return nums

if __name__ == '__main__':
    nums = [5,0,1,2,3,4]
    print(Solution().buildArray(nums))