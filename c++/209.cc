#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0;
        int start = 0;
        int sub_length;
        for (int end=0; end<nums.size(); end++) {
            sum += nums[end];
            while(sum >= target) {
                sub_length = (end-start+1);
                result = result > sub_length ? sub_length : result;
                sum -= nums[start];
                start++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {2,3,1,2,4,3};
    int result = solution.minSubArrayLen(7, nums);
    printf("%d\n", result);
    return 0;
}
