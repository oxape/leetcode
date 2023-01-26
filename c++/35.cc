#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high) {
            int mid = (low+high)/2;
            int value = nums[mid];
            if (value < target) {
                low = mid+1;
            } else if (value > target) {
                high = mid-1;
            } else {
                return mid;
            }
        }
        //这里可以返回high+1
        return low;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {5,7,8,10};
    int result = solution.searchInsert(nums, 11);
    printf("%d", result);
    return 0;
}