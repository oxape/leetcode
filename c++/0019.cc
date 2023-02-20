#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode();
        ListNode *cur;
        ListNode *slow;
        int distance = 0;
        dummyHead->next = head;
        cur = dummyHead;
        slow = cur; //slow没有指向任何有效的元素
        while(cur->next != nullptr) {
            if (distance < n) {
                distance++;
            } else {
                slow = slow->next;
            }
            cur = cur->next;
        }
        if (distance == n) {
            if (slow->next != nullptr) {
                slow->next = slow->next->next;
            }
            // slow->next = slow->next->next->next;
        }
        cur = dummyHead->next;
        delete dummyHead;
        return cur;
    }
};

int main() {
    ListNode *head = nullptr;
    ListNode *cur;

    vector<int> values = {1, 2, 3, 4, 5};

    cur = head;
    for (auto &value : values) {
        if (cur == nullptr) {
            head = new ListNode(value);
            cur = head;
        } else {
            cur->next = new ListNode(value);
            cur = cur->next;
        }
    }
    Solution s;
    head = s.removeNthFromEnd(head, 2);
    ListNode *dummyHead = new ListNode();
    dummyHead->next = head;
    cur = dummyHead;
    while(cur->next != nullptr) {
        printf("%d ", cur->next->val);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}