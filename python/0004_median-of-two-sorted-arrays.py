

class Solution(object):

    def findMedian(self, nums1, nums2):
        print(f'nums1 = {nums1} nums2 = {nums2}')

        nums1_l = len(nums1)
        nums2_l = len(nums2)

        if nums1_l == 0:
            mid_s2_low = (nums2_l*2-1)//4
            mid_s2_up = (nums2_l*2+1)//4
            median = (nums2[mid_s2_low]+nums2[mid_s2_up])/2
            return median

        if nums2_l == 0:
            mid_s1_low = (nums1_l*2-1)//4
            mid_s1_up = (nums1_l*2+1)//4
            median = (nums1[mid_s1_low]+nums1[mid_s1_up])/2
            return median

        if nums1_l == 1 and nums2_l == 1:
            median = (nums1[0]+nums2[0])/2
            return median

        if nums1_l == 1:
            print(f'self.weight1 = {self.weight1} self.weight2 = {self.weight2}')
            return 0

        if nums2_l == 1:
            print(f'self.weight1 = {self.weight1} self.weight2 = {self.weight2}')
            return 0

        # if nums1_l == 1:
        #     if nums1_l > nums2[mid_s2_up]:
        #         mid_s2_low = (nums2_l*2-1)//4
        #         mid_s2_up = (nums2_l*2+1)//4
        #         median = (nums2[mid_s2_low]+nums2[mid_s2_up])/2
        #     if 


        # if nums2_l == 1:
        #     return 0

        mid_s1_low = (nums1_l*2-1)//4
        mid_s1_up = (nums1_l*2+1)//4

        mid_s2_low = (nums2_l*2-1)//4
        mid_s2_up = (nums2_l*2+1)//4

        if nums1[mid_s1_up] >= nums2[mid_s2_up]:
            if nums1[mid_s2_low] >= nums2[mid_s2_up]:
                # if mid_s1_low == 0 and mid_s2_up == nums2_l-1:
                #    return (nums1[mid_s1_low]+nums2[mid_s2_up])/2
                self.weight1 -= nums1_l-(mid_s1_low+1)
                self.weight2 += mid_s2_up+1
                return self.findMedian(nums1[:mid_s1_low+1], nums2[mid_s2_up+1:])
            else:
                self.weight1 += mid_s1_low
                self.weight2 -= nums2_l-(mid_s2_up+1)
                return self.findMedian(nums1[mid_s1_low:], nums2[:mid_s2_up+1])
        else: # nums1[mid_s1_up] < nums2[mid_s2_up]
            if nums1[mid_s1_up] < nums2[mid_s2_low]:
                # if mid_s1_up+1 == nums1_l and mid_s2_low == 0:
                #    return (nums1[mid_s1_up]+nums2[mid_s2_low])/2
                self.weight1 += mid_s1_up+1
                self.weight2 -= nums2_l-(mid_s2_low+1)
                return self.findMedian(nums1[mid_s1_up+1:], nums2[:mid_s2_low+1])
            else:
                self.weight1 -= nums1_l-(mid_s1_up+1)
                self.weight2 += mid_s2_low
                return self.findMedian(nums1[:mid_s1_up+1], nums2[mid_s2_low:])
    
    def findMedianSortedArrays(self, nums1, nums2):
        self.mod2 = (len(nums1)+len(nums2))%2
        self.weight1 = 0
        self.weight2 = 0
        return self.findMedian(nums1, nums2)
        

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



