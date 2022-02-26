
#ifndef CPPBASICS_DESIGN_H
#define CPPBASICS_DESIGN_H

#include <stack>

class MinStack {
private :
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {
    }

    void push(int val) {
        mainStack.push(val);
        minStack.push(minStack.empty() ? val : std::min(minStack.top(), val));
    }

    void pop() {
        mainStack.pop();
        minStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};


/**
 * Shuffle an Array
 * See Fisher Yates Algorithm
 */
class Solution {
public:
    Solution(std::vector<int> &nums) : m_nums(nums) {
    }

    std::vector<int> reset() {
        return m_nums;
    }

    std::vector<int> shuffle() {
        std::vector<int> copy = m_nums;

        for (int i = copy.size(); i > 0; i--) {
            int random = std::rand() % i;
            // -1 because indices, random already -1
            std::swap(copy[i - 1], copy[random]);
        }

        return copy;
    }

private:
    std::vector<int> m_nums;
};

#endif //CPPBASICS_DESIGN_H
