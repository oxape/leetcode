#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        vector<int> results({-1, -1});
        while(low <= high) {
            int mid = low+(high-low)/2;
            int value = nums[mid];
            if (value < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        if (low > nums.size()-1) {
            return results;
        }
        if (nums[low] != target) {
            return results;
        }
        results[0] = low;
        low = 0;
        high = nums.size()-1;
        while(low <= high) {
            int mid = low+(high-low)/2;
            int value = nums[mid];
            if (value > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        results[1] = high;
        return results;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {5,7,7,8,8,10};
    vector<int> results = solution.searchRange(nums, 11);
    printf("[%d, %d]", results[0], results[1]);
    return 0;
}