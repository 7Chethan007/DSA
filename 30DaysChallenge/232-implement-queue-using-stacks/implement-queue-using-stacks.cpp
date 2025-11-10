class MyQueue {
private:
    stack<int> inStack;   // for push
    stack<int> outStack;  // for pop/peek

    // Helper to transfer elements when needed
    void shiftStacks() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    // Push element x to the back of queue
    void push(int x) {
        inStack.push(x);
    }
    
    // Removes the element from in front of queue and returns it
    int pop() {
        shiftStacks();
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    // Get the front element
    int peek() {
        shiftStacks();
        return outStack.top();
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */