#include <string>
#include <vector>
#include <array>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        if (nums.size() < 4) {
            return results;
        }
        quick_sort(nums, 0, nums.size());
        for (int i=0; i<nums.size()-3;) {

            auto result = threeSum(vector<int>(nums.begin()+i+1, nums.end()), target-nums[i]);
            if (result.size() > 0) {
                for (int k=0; k<result.size(); k++) {
                    results.push_back({nums[i], result[k][0], result[k][1], result[k][2]});
                }
            }
            i++;
            while (nums[i] == nums[i-1] && i<nums.size()-3) {
                i++;
            }
        }
        return results;
    }

    vector<vector<int>> threeSum(const vector<int> &nums, int target) {
        vector<vector<int>> results;
        if (nums.size() < 3) {
            return results;
        }
        for (int i=0; i<nums.size()-2;) {
            
            int left = i+1;
            int right = nums.size()-1;
            while (left < right) {
                if (nums[i] + nums[left] < target - nums[right]) {
                    left++;
                } else if (nums[i] + nums[left] > target - nums[right]) {
                    right--;
                } else {
                    results.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (nums[left] == nums[left-1] && left < right) {
                        left++;
                    }
                    right--;
                    while (nums[right] == nums[right+1] && left < right) {
                        right--;
                    }
                }
            }
            i++;
            while (nums[i] == nums[i-1] && i<nums.size()-2) {
                i++;
            }
        }
        return results;
    }

    void swap(vector<int> &nums, int indexa, int indexb) {
        int tmp = nums[indexb];
        nums[indexb] = nums[indexa];
        nums[indexa] = tmp;
    }

    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[start];
        int k = start;
        for (int i=start+1; i<end; i++) {
            if (nums[i] < pivot) {
                k++;
                swap(nums, k, i);
            }
        }
        swap(nums, k, start);
        return k;
    }

    void quick_sort(vector<int> &nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int pivot_index = partition(nums, start, end);
        quick_sort(nums, start, pivot_index);
        quick_sort(nums, pivot_index+1, end);
    }
};

int main() {
    Solution solution;

    vector<int> nums = {
        // 1,0,-1,0,-2,2
        // 2,2,2,2,2,
        // 1,-2,-5,-4,-3,3,3,5
        1,0,-1,0,-2,2
    };
    
    // solution.quick_sort(nums, 0, nums.size());
    vector<vector<int>> results = solution.fourSum(nums, 0);
    for (int i=0; i<results.size(); i++) {
        printf("[%d %d %d %d]\n", results[i][0], results[i][1], results[i][2], results[i][3]);
    }
    exit(0);
    return 0;
}
