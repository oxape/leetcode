class Solution(object):

    def findAnswer(self, nums1, nums2):
        return 0.0
    
    def findMedianSortedArrays(self, nums1, nums2):

        return self.findAnswer(nums1, nums2)


if __name__ == '__main__':
    # a = [10, 14, 16]
    # b = [25, 30, 40, 50]

    a = [9, 10, 45, 60]
    b = [30, 40, 55, 70, 80, 90, 100]

    a = [9, 10, 45, 60]
    b = [30, 40, 55, 70]

    a = [9, 45, 58, 60]
    b = [30, 40, 55, 70]

    a = [5, 8, 9, 10, 11, 12, 13, 20, 31]
    b = [30, 40, 55, 70]

    a = [5, 8, 9, 10, 11, 12, 13, 20, 31]
    b = [30, 40, 55]

    # a = [9, 10, 45]
    # b = [40, 55, 70]
    # a = [30, 60]
    # b = [30, 40]

    l = []
    l.extend(a)
    l.extend(b)
    l.sort()

    print(l)

    mid_low = (len(l)*2-1)//4
    mid_up = (len(l)*2+1)//4
    print(f'a[mid_low] = {a[(len(a)*2-1)//4]} a[mid_up] = {a[(len(a)*2+1)//4]}')
    print(f'b[mid_low] = {b[(len(b)*2-1)//4]} b[mid_up] = {b[(len(b)*2+1)//4]}')
    print(f'l[mid_low] = {l[mid_low]} l[mid_up] = {l[mid_up]}')
    median_sum = l[mid_low]+l[mid_up]
    print(median_sum/2)
    # print(l[(len(l)-1)/2])

    s = Solution()
    median = s.findMedianSortedArrays(a, b)
    print(median)