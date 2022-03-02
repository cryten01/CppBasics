
#ifndef CPPBASICS_GRAPH_H
#define CPPBASICS_GRAPH_H

using namespace std;

#include <queue>
#include <unordered_map>

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/**
 * 133. Clone Graph (medium)
 * Iterative BFS
 * @param node
 * @return
 */
Node *cloneGraph(Node *node) {
    // If node is null, then simply return null
    if (node == nullptr) { return nullptr; }

    unordered_map < Node * , Node * > nodeMap;

    // Make a copy of first node
    Node *first = new Node(node->val, {});
    nodeMap[node] = first;

    // For bfs, we create queue
    queue < Node * > queue;
    // Push into queue
    queue.push(node);

    while (queue.empty() == false) // until q. empty == false
    {
        Node *current = queue.front();
        queue.pop();

        // Now travel in adjacent
        for (auto adj: current->neighbors) {
            // If not present in map
            if (nodeMap.find(adj) == nodeMap.end()) {
                // Then create copy
                nodeMap.emplace(adj, new Node(adj->val, {}));
                // Push nto the queue
                queue.push(adj);
            }

            // In current node push adjacent node
            nodeMap[current]->neighbors.push_back(nodeMap[adj]);
        }
    }

    return nodeMap[node];
}


/**
 * Helper method for 207. Course Schedule
 * @param node
 * @param nodeSet
 * @param preMap
 * @return
 */
bool dfsCanFinish(int &node, set<int> &nodeSet, unordered_map<int, vector<int>> &preMap) {
    // Base case: cycle
    if (nodeSet.count(node) != 0) { return false; }
    // Base case: no prerequisites
    if (preMap[node].empty()) { return true; }

    // Inserting into nodeSet (marking as visited)
    nodeSet.insert(node);

    // Recursive step for each pre-requisites
    for (int &preCourse: preMap[node]) {
        bool canFinish = dfsCanFinish(preCourse, nodeSet, preMap);

        if (!canFinish) { return false; }
    }

    nodeSet.erase(node);
    preMap[node] = {};

    return true;
}

/**
 * 207. Course Schedule
 * Topological sort
 * @param numCourses
 * @param prerequisites
 * @return
 */
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // Only 1 course but at least another course needed for prerequisite
    if (numCourses <= 1 && prerequisites.size() > 0) { return false; }

    // Empty lists for each course
    unordered_map<int, vector<int>> preMap;

    for (vector<int> &pre: prerequisites) {
        preMap[pre[0]].push_back(pre[1]);
    }

    // Set for detecting cycles
    set<int> coursePath;

    // Perform DFS for each course
    for (int course = 0; course < numCourses; course++) {
        bool canFinish = dfsCanFinish(course, coursePath, preMap);

        if (!canFinish) { return false; }
    }

    return true;
}

#endif //CPPBASICS_GRAPH_H
