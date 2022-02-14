#include <gtest/gtest.h>
#include "../src/05_Bonus/String.h"

TEST(StringTests, ReverseString) {
    std::vector<char> name = {'h', 'e', 'l', 'l', 'o'};
    reverseString(name);
    EXPECT_EQ(name, (std::vector<char>{'o', 'l', 'l', 'e', 'h'}));
}

TEST(StringTests, FindUniqueChar) {
    std::string word = "Loveleetcode";
    EXPECT_EQ(firstUniqChar(word), 2);
}

TEST(StringTests, MyAtoi) {
    std::string toCheck = "    -42";
    EXPECT_EQ(myAtoi(toCheck), -42);
    toCheck = "4193 with words";
    EXPECT_EQ(myAtoi(toCheck), 4193);
    toCheck = "words with 4932";
    EXPECT_EQ(myAtoi(toCheck), 0);
    toCheck = "-91283472332";
    EXPECT_EQ(myAtoi(toCheck), -2147483648);
    toCheck = "+1";
    EXPECT_EQ(myAtoi(toCheck), 1);
}

TEST(StringTests, StrStr) {
    std::string haystack = "hello";
    std::string needle = "ll";
    // Empty string
    // No occurrence
    EXPECT_EQ(strStr(haystack, needle), 2);
    haystack = "aaaaaa";
    needle = "bba";
    EXPECT_EQ(strStr(haystack, needle), -1);
    haystack = "";
    needle = "";
    EXPECT_EQ(strStr(haystack, needle), 0);
    // Connected i of wrong true
    haystack = "mississippi";
    needle = "issip";
    EXPECT_EQ(strStr(haystack, needle), 4);
}

TEST(StringTests, ReverseWords) {
    std::string words = "God Ding";
    words = reverseWords(words);
    EXPECT_EQ(words, "doG gniD");
}