#include <queue>
#include <string>
#include <vector>

using namespace std;

class MyStack {
public:
    std::queue<int> queue[2];
    int count{0};

    MyStack() {

    }
    
    void push(int x) {
        queue[count].push(x);
    }
    
    int pop() {
        int top;
        int revert;
        top = this->top();

        if (count == 0) {
            revert = 1;
        } else {
            revert = 0;
        }
        while (queue[count].size() > 1) {
            queue[revert].push(queue[count].front());
            queue[count].pop();
        }
        queue[count].pop();
        count = revert;
        return top;
    }
    
    int top() {
        return queue[count].back();
    }
    
    bool empty() {
        return queue[0].empty() && queue[1].empty();
    }
};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    stack.pop();
    int top = stack.top();
    printf("top = %d\n", top);
    return 0;
}
