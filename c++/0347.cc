#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class Solution0 {
public:
    using T = int;
    class prior_queue {
        private:
            deque<pair<int, T>> elements; //pair.fisrt is key pair.second is value

        protected:
            void min_heapify(int i) {
                int dad = i;
                int son_left = i*2+1;
                int son_right = i*2+2;
                int min = dad;
                if (son_left < elements.size()) {
                    if (elements[son_left].first < elements[min].first) {
                        min = son_left;
                    }
                }
                if (son_right < elements.size()) {
                    if (elements[son_right].first < elements[min].first) {
                        min = son_right;
                    }
                }
                if (min != i) {
                    swap(elements[i], elements[min]);
                    min_heapify(min);
                }
            }

            void build_min_heap() {
                for (int i=elements.size()/2-1; i>=0; i--) {
                    min_heapify(i);
                }
            }

        public:
            prior_queue() = default;

            prior_queue(const unordered_map<int, T> &um) {
                for (const auto &p:um) {
                    elements.push_back(p);
                }
            }

            int parent(int i) {
                return (i-1)/2;
            }

            std::size_t size() {
                return elements.size();
            }
            
            void insert(const pair<int, T> &e) {
                elements.push_back(e);
                int i;
                i = elements.size()-1;
                while (i>0 && elements[parent(i)].first > elements[i].first) {
                    swap(elements[i], elements[parent(i)]);
                    i = parent(i);
                }
            }
            
            const pair<int, T>& top() const {
                return elements[0];
            }

            void extract_min() {
                swap(elements[0], elements[elements.size()-1]);
                elements.pop_back();
                min_heapify(0);
            }

            vector<T> sort() { //练习堆排序用，不属于题解的一部分
                vector<T> result;
                if (elements.size() <= 1) {
                    if (!elements.empty()) {
                        result.push_back(elements.front().second);
                    }
                    return result;
                }
                build_min_heap();
                for(int i=elements.size()-1; i>0; i--) {
                    result.push_back(elements[0].second); //队列头部的值是最小值
                    std::swap(elements[0], elements[i]); //队列头部的值是最小值，交换到队列尾部
                    elements.pop_back(); //弹出队列尾部的值
                    min_heapify(0); //现在队列头部的值可能会违反最小堆，所以需要调用min_heapify
                }
                result.push_back(elements[0].second); //队列头部的值是最小值
                for (int i=0; i<result.size(); i++) {
                    printf("%d ", result[i]);
                }
                printf("\n");
                return result;
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        prior_queue pq;
        vector<int> result;
        int l = nums.size();
        for (int i=0; i<l; i++) {
            count_map[nums[i]]++;
        }
        for (const auto &e : count_map) {
            if (pq.size() < k) {
                pq.insert(std::make_pair(e.second, e.first));
            } else {
                if (pq.top().first <= e.second) {
                    pq.extract_min();
                    pq.insert(std::make_pair(e.second, e.first));
                }
            }
        }
        while (pq.size() > 0) {
            result.push_back(pq.top().second);
            pq.extract_min();
        }
        return result;
    }
};

class Solution1 {
public:
    //pair<int, int> first element second key
    int partion(vector<pair<int, int>> &nums, int start, int end) {
        int pivot = start;
        int k = start;
        std::swap(nums[pivot], nums[end-1]);
        pivot = nums[end-1].second;
        for (int i=start; i<end-1; i++) {
            if (nums[i].second > pivot) {
                std::swap(nums[i], nums[k]);
                k++;
            }
        }
        std::swap(nums[k], nums[end-1]);
        return k;
    }

    void quick_sort_k(vector<pair<int, int>> &nums, int start, int end, int k) { //k >= start
        if (start >= end) {
            return;
        }
        int pivot = partion(nums, start, end);
        if (k <= pivot) {
            quick_sort_k(nums, start, pivot, k);
        } else {
            // quick_sort_k(nums, start, pivot, k); //[start, pivot]都在前k里面，由于输出结果可以是任意顺序所以[start, pivot]不需要排序
            quick_sort_k(nums, pivot+1, end, k);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        vector<pair<int, int>> tmp;
        vector<int> result;
        int l = nums.size();
        for (int i=0; i<l; i++) {
            count_map[nums[i]]++;
        }
        for(const auto &p:count_map) {
            tmp.push_back(p);
        }
        quick_sort_k(tmp, 0, tmp.size(), k);
        for (int i=0; i<k; i++) {
            result.push_back(tmp[i].first);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    const initializer_list<int> list = {10,10,10,50,10,50,30,30,50,30,30,30};
    vector<int> nums = list;
    int k=2;

    // auto pq = Solution0::prior_queue({{5, 30}, {3, 20}, {4, 10}, {1, 40}, {9, 70}, {7, 60}});
    // pq.sort();

    Solution0 Solution0;
    auto result0 = Solution0.topKFrequent(nums, k);
    for (int i=0; i<result0.size(); i++) {
        cout << result0[i] << " ";
    }
    cout << endl;
    
    Solution1 solution1;
    auto result1 = solution1.topKFrequent(nums, k);
    for (int i=0; i<result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;
    return 0;
}
