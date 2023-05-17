#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int last;
        if (nums.size() < 3) {
            return results;
        }
        quick_sort(nums, 0, nums.size());
        for (int i=0; i<nums.size()-2;) {
            if (nums[i] > 0) {
                break;
            }
            int left = i+1;
            int right = nums.size()-1;
            int sum = 0-nums[i];
            while (left < right) {
                if (nums[left] > sum) {
                    break;
                }
                if (nums[left] + nums[right] < sum) {
                    left++;
                } else if (nums[left] + nums[right] > sum) {
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
        // -1,0,1,2,-1,-4
        -2, 0, 1, 1, 2
    };
    
    // solution.quick_sort(nums, 0, nums.size());
    vector<vector<int>> results = solution.threeSum(nums);
    for (int i=0; i<results.size(); i++) {
        printf("[%d %d %d]\n", results[i][0], results[i][1], results[i][2]);
    }
    exit(0);
    return 0;
}
