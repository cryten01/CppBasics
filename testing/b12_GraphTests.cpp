#include <gtest/gtest.h>
#include "../src/05_Bonus/Graph.h"

using namespace std;

TEST(GraphTests, CloneGraph) {
    vector<vector<int>> adjList = {{2, 4},
                                   {1, 3},
                                   {2, 4},
                                   {1, 3}};

    // TODO
    Node n1{1};
    Node n2{2};
    Node n3{3};
    Node n4{4};
    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n4);
    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n2);
    n3.neighbors.push_back(&n4);
    n4.neighbors.push_back(&n1);
    n4.neighbors.push_back(&n3);

    Node *copy = cloneGraph(&n1);
}

TEST(GraphTests, CourseSchedule) {
    vector<vector<int>> adjList = {{1, 0}};
    EXPECT_TRUE(canFinish(2, adjList));
}