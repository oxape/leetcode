'''
Author: your name
Date: 2022-02-18 09:55:07
LastEditTime: 2022-02-22 19:11:24
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: /leetcode/problems/python/1920_build-array-from-permutation.py
'''
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