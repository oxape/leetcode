#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <random>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

class Solution {
public:
    int partion(deque<int> &index_deque, vector<int> &nums, int start, int end) {
        int pivot = start;
        int pivot_val = nums[pivot];
        int k=start;
        std::swap(nums[pivot], nums[end-1]);
        std::swap(index_deque[pivot], index_deque[end-1]);
        for (int i=start; i<end-1; i++) {
            if (nums[i] > pivot_val) {
                std::swap(nums[k], nums[i]);
                std::swap(index_deque[k], index_deque[i]);
                k++;
            }
        }
        std::swap(nums[k], nums[end-1]);
        std::swap(index_deque[k], index_deque[end-1]);
        return k;
    }

    void quick_sort(deque<int> &index_deque, vector<int> &nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int pivot = partion(index_deque, nums, start, end);
        quick_sort(index_deque, nums, start, pivot);
        quick_sort(index_deque, nums, pivot+1, end);
    }

    int binary_search(int value, vector<int> &nums, int start, int end) {
        int low = start;
        int high = end;
        int mid;
        while (low < high) {
            mid = (low+high)/2;
            if (value == nums[mid]) {
                return mid;
            } else if (value < nums[mid]) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return -1;
    }

    int sorted_vec_bleft(int value, vector<int> &nums, int start, int end) {
        int low = start;
        int high = end;
        int mid;
        while (low != high) {
            mid = (low+high)/2;
            if (value < nums[mid]) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> sorted_vec;
        deque<int> tmp_deque;
        deque<int> index_deque;
        int index;
        sorted_vec.reserve(k);
        // index_vec.reserve(k);
        sorted_vec.assign(nums.cbegin(), nums.cbegin()+k-1);
        for (int i=0; i<k-1; i++) {
            tmp_deque.push_back(i);
        }
        quick_sort(tmp_deque, sorted_vec, 0, sorted_vec.size());
        index_deque.assign(k-1, 0);
        for (int i=0; i<k-1; i++) {
            index_deque[tmp_deque[i]] = i;
        }
        for (int i=k-1; i<nums.size(); i++) {
            int index = sorted_vec_bleft(nums[i], sorted_vec, 0, sorted_vec.size());
            for (int n=0; n<index_deque.size(); n++) {
                if (index_deque[n] >= index) {
                    index_deque[n]++;
                }
            }
            index_deque.push_back(index);
            sorted_vec.insert(sorted_vec.cbegin()+index, nums[i]);
            result.push_back(sorted_vec.front());
            index = index_deque[0];
            sorted_vec.erase(sorted_vec.cbegin()+index);
            for (int n=0; n<index_deque.size(); n++) {
                if (index_deque[n] >= index) {
                    index_deque[n]--;
                }
            }
            index_deque.pop_front();
        }
        return result;
    }
};

class Solution2 {
public:
    class MyQueue {
        public:
            deque<int> q;
            void pop(int value) {
                if (!q.empty() && value == q.front()) {
                    q.pop_front();
                }
            }

            void push(int value) {
                while(!q.empty() && value > q.back()) {
                    q.pop_back();
                }
                q.push_back(value);
            }

            int front() {
                return q.front();
            }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue queue;
        for (int i=0; i<k; i++) {
            queue.push(nums[i]);
        }
        result.push_back(queue.front());
        for (int i=k; i<nums.size(); i++) {
            queue.pop(nums[i-k]);
            queue.push(nums[i]);
            result.push_back(queue.front());
        }
        return result;
    }
};

int main() {
    // initializer_list<int> array = {1, 3, -1, -3, 5, 3, 6, 7};
    initializer_list<int> array = {1, -9, 8, -6, 6, 4, 0, 5};
    vector<int> vec(array);
    Solution solution;
    deque<int> index_deque;
    // for (int i=0; i<vec.size(); i++) {
    //     index_deque.push_back(i);
    // }
    // solution.quick_sort(index_deque, vec, 0, vec.size());
    // int index = solution.sorted_vec_bleft(3, vec, 0, vec.size());
    // printf("\nindex = %d\n", index);
    // for (int i=0; i<vec.size(); i++) {
    //     std::cout << " " << vec[i];
    // }
    vector<int> result = solution.maxSlidingWindow(vec, 4);
    printf("\nresult = ");
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
