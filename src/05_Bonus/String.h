
#ifndef CPPBASICS_STRING_H
#define CPPBASICS_STRING_H

#include <unordered_map>

/**
 * 344. Reverse String
 * @param s the string that needs to be reversed.
 */
void reverseString(std::vector<char> &s) {
    if (s.size() <= 1) return;

    int i = 0;
    while (i < (s.size() + 1) / 2) {
        std::swap(s[i], s[s.size() - 1 - i]);
        i++;
    }
}

int firstUniqChar(std::string s) {
    std::unordered_map<char, int> letterCountMap;
    // Store character occurrence
    for (char &c: s) {
        letterCountMap[std::tolower(c)] += 1;
    }

    // Find the correct index
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (letterCountMap[c] == 1) {
            return i;
        }
    }

    return -1;
}

int myAtoi(std::string s) {
    int sum = 0;
    bool isNegative = false;
    int i = 0;

    // Skip first white spaces
    while (s[i] == ' ') {
        i++;
    }

    // Mark number as negative if '-'
    if (s[i] == '-') {
        isNegative = true;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Skip white spaces
    for (; i < s.size(); i++) {
        char &c = s[i];

        // Break loop in case of non digit character
        if (!(c >= '0' && c <= '9')) break;

        // Retrieve digit
        int digit = (c - '0');

        // Check overflow and underflow conditions.
        if ((sum > INT_MAX / 10) || (sum == INT_MAX / 10 && digit > INT_MAX % 10)) {
            // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
            return isNegative ? INT_MIN : INT_MAX;
        }

        // Increase sum by factor of 10 because digit shift
        sum = sum * 10 + digit;
    }

    return isNegative ? -sum : sum;
}

int strStr(std::string haystack, std::string needle) {
    if (needle.size() == 0) return 0;
    if (haystack.size() < needle.size()) return -1;

    // Cache variables
    int hs = haystack.size();
    int ns = needle.size();

    for (int i = 0; i <= hs - ns; ++i) {
        int j;
        // Check for needle
        for (j = 0; j < ns; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        // Needle found at index i
        if (j == ns) {
            return i;
        }
    }

    return -1;
}

/**
 * 557. Reverse Words in a String III
 * @param s
 * @return
 */
std::string reverseWords(std::string s) {
    // Edge cases: 0,1,n words
    int start = 0;
    int end = 0;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == ' ' || i == s.size()) {
            end = i - 1;

            // Reverse word
            while (start < end) {
                std::swap(s[start], s[end]);
                start++;
                end--;
            }

            // Set next starting point (assuming only 1 whitespace char)
            start = i + 1;
        }
    }

    return s;
}

#endif //CPPBASICS_STRING_H
