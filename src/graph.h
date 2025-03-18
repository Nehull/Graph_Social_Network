#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjList;  // Friend connections with weights
public:
    void addUser(const string& user);
    void addFriendship(const string& user1, const string& user2, int weight);
    vector<string> bfs(const string& start);
    vector<string> dfs(const string& start);
    vector<string> findMutualFriends(const string& user1, const string& user2);
    vector<string> suggestFriends(const string& user);
    void dijkstra(const string& src);
    void displayNetwork();
    void exportToFile(const string& filename);
};

#endif
