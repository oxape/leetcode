#include <stack>
#include <vector>
#include <string>

using namespace std;

class MyQueue {
public:
    std::stack<int> stack[2];
    int count {0};
    bool lastIsPush{true};

    MyQueue() {
        
    }
    
    void push(int x) {
        if (!lastIsPush) {
            while(!stack[1].empty()) {
                stack[0].push(stack[1].top());
                stack[1].pop();
            }
        }
        lastIsPush = true;
        stack[0].push(x);
    }
    
    int pop() {
        int top;
        if (lastIsPush) {
            while(!stack[0].empty()) {
                stack[1].push(stack[0].top());
                stack[0].pop();
            }
        }
        lastIsPush = false;
        top = stack[1].top();
        stack[1].pop();
        return top;
    }
    
    int peek() {
        if (lastIsPush) {
            while(!stack[0].empty()) {
                stack[1].push(stack[0].top());
                stack[0].pop();
            }
        }
        lastIsPush = false;
        return stack[1].top();
    }
    
    bool empty() {
        return stack[0].empty() && stack[1].empty();
    }
};

int main() {
    MyQueue queue;

    vector<string> op = {"MyQueue","push","push","push","push","pop","push","pop","pop","pop","pop"};
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.pop();
    queue.push(5);
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    return 0;
}

