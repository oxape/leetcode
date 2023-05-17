#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int m;
        vector<vector<int>> results;
        // for (int i=0; i<nums.size(); i++) {
        //     for (int j=i+1; j<nums.size(); j++) {
        //         for (int k=j+1; k<nums.size(); k++) {
        //             if (nums[i]+nums[j]+nums[k] == 0) {
        //                 vector<int> result = {nums[i], nums[j], nums[k]};
        //                 sort(result);
        //                 for (m=0; m<results.size(); m++) {
        //                     if (results[m] == result) {
        //                         break;
        //                     }
        //                 }
        //                 if (m == results.size()) {
        //                     results.push_back(result);
        //                 }
        //             }
        //         }
        //     }
        // }
        return results;
    }

    void swap(vector<int> &nums, int indexa, int indexb) {
        int tmp = nums[indexb];
        nums[indexb] = nums[indexa];
        nums[indexa] = tmp;
    }

    int partition(vector<int> nums, int start, int end) {
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

    void quick_sort(vector<int> nums, int start, int end) {
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

    vector<int> nums = {-1,0,1,2,-1,-4};
    solution.quick_sort(nums, 0, nums.size());
    for (int i=0; i<nums.size(); i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}
