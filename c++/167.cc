#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result({-1, -1});
        int left = 0;
        int right = numbers.size()-1;
        while(left < right) {
            int sum = numbers[left]+numbers[right];
            if (sum == target) {
                result[0] = left+1;
                result[1] = right+1;
                return result;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};


int main() {
    Solution solution;

    vector<int> nums = {2,7,11,15};
    // vector<int> nums = {2,3,4};
    // vector<int> nums = {-1,0};
    vector<int> results = solution.twoSum(nums, 11);
    printf("[%d, %d]", results[0], results[1]);
    return 0;
}