
#ifndef CPPBASICS_STRING_H
#define CPPBASICS_STRING_H

using namespace std;

#include <unordered_map>
#include <stack>
#include <unordered_map>
#include <set>

/**
 * 344. Reverse String
 * Two Pointers
 * @param s the string that needs to be reversed.
 */
void reverseString(std::vector<char> &s) {
    // Return if no swap possbile
    if (s.size() < 2) { return; }

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

/**
 * 387. First Unique Character in a String
 * Hash Table, String, Queue
 * @param s the string to test.
 * @return the index of the non repeating char or otherwise -1.
 */
int firstUniqChar(std::string s) {
    std::unordered_map<char, int> frequencyMap;

    // Store character occurrence
    for (char &c: s) {
        frequencyMap[std::tolower(c)] += 1;
    }

    // Find the correct index
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (frequencyMap[c] == 1) {
            return i;
        }
    }

    return -1;
}

int myAtoi(std::string s) {
    int sum = 0;
    bool isNegative = false;
    int i = 0;

    // Skip list white spaces
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

/**
 * 383. Ransom Note
 * Hash Table, String, Counting
 * @param ransomNote the note thats inside magazine in lower case letters.
 * @param magazine the string containing ransomnote in lower case letters.
 * @return true if ransomnote can be constructed otherwise false
 */
bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> frequencyMap;

    // Store all available letters in a frequency map first
    for (char &c: magazine) {
        frequencyMap[c]++;
    }

    // Remove entries and check size
    for (char &c: ransomNote) {
        // Check if characters are left or entry even exists
        if (frequencyMap[c] <= 0 || frequencyMap.find(c) == frequencyMap.end()) {
            return false;
        }

        frequencyMap[c]--;
    }

    return true;
}

/**
 * 20. Valid Parentheses
 * @param s
 * @return
 */
bool isValid(std::string s) {
    std::stack<char> brackets;

    for (char &c: s) {
        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (brackets.size() == 0) {
                return false;
            }

            if ((brackets.top() == '(' && c == ')') || (brackets.top() == '{' && c == '}') ||
                (brackets.top() == '[' && c == ']')) {
                brackets.pop();
            } else {
                return false;
            }
        }
    }

    return brackets.size() == 0;
}

/**
 * 3. Longest Substring Without Repeating Characters
 * Sliding window technique
 * @param s
 * @return
 */
int lengthOfLongestSubstring(std::string s) {
    // Use set because only existence in set is relevant
    std::set<char> charSet;

    int left = 0;
    int right = 0;
    int max = 0;

    for (char c: s) {
        // We found a duplicate
        while (charSet.count(c)) {
            // Remove all following chars until duplicate is found
            charSet.erase(c);
            // Reduce sliding window
            left++;
        }
        // Insert new char
        charSet.emplace(c);
        // Compare new max with old one
        max = std::max(max, right - left + 1);
        // Iteration step
        right++;
    }

    return max;
}

/**
 * 567. Permutation in String
 * @param s1
 * @param s2
 * @return
 */
bool checkInclusion(std::string s1, std::string s2) {
    // Permutation = consequtive row of char that only occur once
    // Break if letter not in map (either because of duplicates or wrong entirely)
    // If wrong reset map because row is broken
    std::unordered_map<char,int> frequencyMap;
    std::unordered_map<char,int> originalMap;

    // Populate map
    for (char& c : s1) {
        originalMap[c]++;
    }

    frequencyMap = originalMap;

    for (char& c : s2) {
        // Wrong letter or all used
        if (frequencyMap.count(c) == 0) {
            frequencyMap = originalMap;
        } else {
            if (frequencyMap[c] > 1) {
                frequencyMap[c]--;
            } else {
                frequencyMap.erase(c);
            }

            if (frequencyMap.size() == 0) {return true;}
        }
    }

    return false;
}

#endif //CPPBASICS_STRING_H
