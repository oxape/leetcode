#include <vector>

using namespace std;
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> state = {};
        int start = 0;
        vector<vector<int>> res = {};
        std::sort(candidates.begin(), candidates.end());
        backtrack(state, target, candidates, start, res);
        return res;
    }

    void backtrack(
        vector<int> &state, 
        int target, 
        vector<int> &choices, 
        int start, 
        vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(std::vector<int>{state});
            return;
        }
        for (int i = start; i < choices.size(); ++i) {
            if (target - choices[i] < 0) {
                break;
            }
            state.push_back(choices[i]);
            backtrack(state, target-choices[i], choices, i, res);
            state.pop_back();
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums = {2,3,6,7};
    auto result = solution.combinationSum(nums, 7);
    printf("%d", result.size());
    return 0;
}
