#include <gtest/gtest.h>
#include "../src/03_DataStructures/DataStructures.h"

class HashTableTests : public ::testing::Test {
protected:
    void SetUp() override {
        int value;

        emptyHashTable = new HashTable<int>(20);
        filledHashTable = new HashTable<int>(20);
        value = 99;
        filledHashTable->Insert(112, value);
        value = 112;
        filledHashTable->Insert(134, value);

        emptyLLHashTable = new LLHashTable<int>(20);
        filledLLHashTable = new LLHashTable<int>(20);
        value = 99;
        filledLLHashTable->Insert(112, value);
        value = 112;
        filledLLHashTable->Insert(134, value);
    }

    void TearDown() override {
        delete emptyHashTable;
        emptyHashTable = nullptr;

        delete filledHashTable;
        filledHashTable = nullptr;

        delete emptyLLHashTable;
        emptyLLHashTable = nullptr;

        delete filledLLHashTable;
        filledLLHashTable = nullptr;
    }

    HashTable<int> *emptyHashTable;
    HashTable<int> *filledHashTable;
    LLHashTable<int> *emptyLLHashTable;
    LLHashTable<int> *filledLLHashTable;
};

TEST_F(HashTableTests, EmptyTableSize) {
    EXPECT_EQ(emptyHashTable->GetSize(), 23);
    EXPECT_EQ(emptyLLHashTable->GetSize(), 23);
}

TEST_F(HashTableTests, Insert) {
    EXPECT_EQ(filledHashTable->GetTotalItems(), 2);
    // TODO: also test filledLLHashTable
}

TEST_F(HashTableTests, Find) {
    int val = 99;
    EXPECT_TRUE(filledHashTable->Find(112, &val));
    EXPECT_TRUE(filledLLHashTable->Find(112, &val));
}

TEST_F(HashTableTests, Delete) {
    int val = 99;
    filledHashTable->Delete(112);
    filledLLHashTable->Delete(112);
    EXPECT_FALSE(filledLLHashTable->Find(112, &val));
    EXPECT_FALSE(filledHashTable->Find(112, &val));
}

TEST_F(HashTableTests, StringHashing) {
    std::string key1 = "cats";
    std::string key2 = "cats";
    int stringHash1 = emptyHashTable->HashFunction(key1);
    int stringHash2 = emptyHashTable->HashFunction(key2);
    EXPECT_EQ(stringHash1, stringHash2);

    // No StringHashing test for LLHashTable needed because of identical function
}

// TODO: Test collision handling
