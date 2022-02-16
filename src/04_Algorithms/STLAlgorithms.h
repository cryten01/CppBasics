
#ifndef CPPBASICS_STLALGORITHMS_H
#define CPPBASICS_STLALGORITHMS_H

#include <vector>

void ShowSort() {
    // n * log(n)
    // uniform initialization
    std::vector<int> values{3, 5, 4, 1, 2};
    std::vector<int> correct{1, 2, 3, 4, 5};
    std::vector<int> correctLambda{2, 3, 4, 5, 1};

    // automatically ascend order
    std::sort(values.begin(), values.end());
    assert(values == correct);
    // std::greater -> descending order
    std::sort(values.begin(), values.end(), std::greater<int>());
    // using a lambda
    std::sort(values.begin(), values.end(), [](int a, int b) {
        // if first item move to back of the array
        if (a == 1) {
            return false;
        }
        // move a to front of the list
        if (b == 1) {
            return true;
        }

        return a < b;
    });
    assert(values == correctLambda);
};

#endif //CPPBASICS_STLALGORITHMS_H
