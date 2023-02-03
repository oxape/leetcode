#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (0 != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        while(slowIndex < nums.size()) {
            nums[slowIndex++] = 0;
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums = {0,1,0,3,12};
    // vector<int> results = ;
    solution.moveZeroes(nums);
    // printf("[%d, %d]", results[0], results[1]);
    return 0;
}