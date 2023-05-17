#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cstdio>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> map1;
        std::unordered_map<int, int> map2;
        std::unordered_map<int, int> map12;
        std::unordered_map<int, int> map3;
        std::unordered_map<int, int> map4;
        std::unordered_map<int, int> map34;
        int count;
        count = 0;
        
        std::unordered_map<int, int> *map;
        vector<int> *nums;
        map = &map1;
        nums = &nums1;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map2;
        nums = &nums2;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map12;
        for (auto const &it1 : map1) {
            for (auto const &it2 : map2) {
                const int sum = it1.first+it2.first;
                if ((*map).find(sum) != (*map).end()) {
                    (*map)[sum] += it1.second*it2.second;
                } else {
                    (*map)[sum] = it1.second*it2.second;
                }
            }
        }

        map = &map3;
        nums = &nums3;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map4;
        nums = &nums4;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map34;
        for (auto const &it1 : map3) {
            for (auto const &it2 : map4) {
                const int sum = it1.first+it2.first;
                if ((*map).find(sum) != (*map).end()) {
                    (*map)[sum] += it1.second*it2.second;
                } else {
                    (*map)[sum] = it1.second*it2.second;
                }
            }
        }

        map = &map34;
        for (auto const &it1 : map12) {
            std::unordered_map<int, int>::const_iterator it = (*map).find(0-it1.first);
            if (it != (*map).end()) {
                count += it1.second*(*it).second;
            }
        }
        
        return count;
    }

    int fourSumCount2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::map<int, int> map1;
        std::map<int, int> map2;
        std::map<int, int> map12;
        std::map<int, int> map3;
        std::map<int, int> map4;
        std::map<int, int> map34;
        int count;
        count = 0;
        
        std::map<int, int> *map;
        vector<int> *nums;
        map = &map1;
        nums = &nums1;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map2;
        nums = &nums2;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map12;
        for (auto const &it1 : map1) {
            for (auto const &it2 : map2) {
                const int sum = it1.first+it2.first;
                if ((*map).find(sum) != (*map).end()) {
                    (*map)[sum] += it1.second*it2.second;
                } else {
                    (*map)[sum] = it1.second*it2.second;
                }
            }
        }

        map = &map3;
        nums = &nums3;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map4;
        nums = &nums4;
        for (auto &value : (*nums)) {
            if ((*map).find(value) != (*map).end()) {
                (*map)[value]++;
            } else {
                (*map)[value] = 1;
            }
        }
        map = &map34;
        for (auto const &it1 : map3) {
            for (auto const &it2 : map4) {
                const int sum = it1.first+it2.first;
                if ((*map).find(sum) != (*map).end()) {
                    (*map)[sum] += it1.second*it2.second;
                } else {
                    (*map)[sum] = it1.second*it2.second;
                }
            }
        }

        map = &map34;
        for (auto const &it1 : map12) {
            std::map<int, int>::const_iterator it = (*map).find(0-it1.first);
            if (it != (*map).end()) {
                count += it1.second*(*it).second;
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {-1, -1};
    vector<int> nums2 = {-1, 1};
    vector<int> nums3 = {-1, 1};
    vector<int> nums4 = {1, -1};
    int result = solution.fourSumCount(nums1, nums2, nums3, nums4);
    printf("%d\n", result);
    return 0;
}