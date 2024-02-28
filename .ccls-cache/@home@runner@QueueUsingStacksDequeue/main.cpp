#include <stack>
#include <climits>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    int front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    void enqueue(int value) {
        stack1.push(value);
    }

    void dequeue() {
    if (stack2.empty()) {
        // Transfer all elements from stack1 to stack2
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    // If stack2 is not empty, pop the top element to simulate dequeue
    if (!stack2.empty()) {
        stack2.pop();
    }
}