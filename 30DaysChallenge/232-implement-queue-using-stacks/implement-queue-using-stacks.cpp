#include <stack>
#include <stdexcept>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;   // Stack for enqueue (push)
    stack<int> outStack;  // Stack for dequeue (pop/peek)

    // Transfer elements only when outStack is empty
    void shiftStacks() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() = default; // Default constructor

    // Push element x to the back of queue
    void push(int x) {
        inStack.push(x);
    }
    
    // Removes the element from front of queue and returns it
    int pop() {
        shiftStacks();
        if (outStack.empty()) 
            throw runtime_error("Queue is empty");
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    // Get the front element
    int peek() {
        shiftStacks();
        if (outStack.empty()) 
            throw runtime_error("Queue is empty");
        return outStack.top();
    }
    
    // Returns whether the queue is empty
    bool empty() const {
        return inStack.empty() && outStack.empty();
    }
};
