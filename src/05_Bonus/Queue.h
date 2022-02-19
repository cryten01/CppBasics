
#ifndef CPPBASICS_QUEUE_H
#define CPPBASICS_QUEUE_H

#include <stack>

class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        int temp = peek();
        output.pop();
        return temp;
    }

    int peek() {
        if (output.empty()) {
            while (input.size()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }

private:
    std::stack<int> input;
    std::stack<int> output;
};

#endif //CPPBASICS_QUEUE_H
