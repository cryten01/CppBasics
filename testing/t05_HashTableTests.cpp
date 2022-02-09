#include <gtest/gtest.h>
#include "../src/03_DataStructures/DataStructures.h"

class HashTableTests : public ::testing::Test {
protected:
    void SetUp() override {
        emptyHashTable = new HashTable<int>(20);
        filledHashTable = new HashTable<int>(20);
        int value = 99;
        filledHashTable->Insert(112, value);
        value = 112;
        filledHashTable->Insert(134, value);
    }

    void TearDown() override {
        delete emptyHashTable;
        emptyHashTable = nullptr;

        delete filledHashTable;
        filledHashTable = nullptr;
    }

    HashTable<int> *emptyHashTable;
    HashTable<int> *filledHashTable;
};

TEST_F(HashTableTests, EmptyTableSize) {
    EXPECT_EQ(emptyHashTable->GetSize(), 23);
}

TEST_F(HashTableTests, Insert) {
    EXPECT_EQ(filledHashTable->GetTotalItems(), 2);
}

TEST_F(HashTableTests, Find) {
    int val = 99;
    EXPECT_TRUE(filledHashTable->Find(112, &val));
}

TEST_F(HashTableTests, Delete) {
    filledHashTable->Delete(112);
    int val = 99;
    EXPECT_FALSE(filledHashTable->Find(112, &val));
}

TEST_F(HashTableTests, StringHashing) {
    std::string key1 = "cats";
    std::string key2 = "cats";
    int stringHash1 = emptyHashTable->HashFunction(key1);
    int stringHash2 = emptyHashTable->HashFunction(key2);
    EXPECT_EQ(stringHash1, stringHash2);
}

// TODO: Test collision handling
