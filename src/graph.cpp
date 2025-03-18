#include "graph.h"

void Graph::addUser(const string& user) {
    if (adjList.find(user) == adjList.end()) {
        adjList[user] = {};
    }
}

void Graph::addFriendship(const string& user1, const string& user2, int weight) {
    adjList[user1].push_back({user2, weight});
    adjList[user2].push_back({user1, weight});  // Undirected graph
}

vector<string> Graph::bfs(const string& start) {
    vector<string> result;
    unordered_set<string> visited;
    queue<string> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        result.push_back(curr);

        for (auto& neighbor : adjList[curr]) {
            if (visited.find(neighbor.first) == visited.end()) {
                visited.insert(neighbor.first);
                q.push(neighbor.first);
            }
        }
    }
    return result;
}

vector<string> Graph::dfs(const string& start) {
    vector<string> result;
    unordered_set<string> visited;
    stack<string> st;

    st.push(start);

    while (!st.empty()) {
        string curr = st.top();
        st.pop();

        if (visited.find(curr) == visited.end()) {
            visited.insert(curr);
            result.push_back(curr);

            for (auto& neighbor : adjList[curr]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    st.push(neighbor.first);
                }
            }
        }
    }
    return result;
}

vector<string> Graph::findMutualFriends(const string& user1, const string& user2) {
    unordered_set<string> set1, set2;
    vector<string> mutual;

    for (auto& friend1 : adjList[user1]) {
        set1.insert(friend1.first);
    }

    for (auto& friend2 : adjList[user2]) {
        set2.insert(friend2.first);
    }

    for (const auto& f : set1) {
        if (set2.find(f) != set2.end()) {
            mutual.push_back(f);
        }
    }

    return mutual;
}

vector<string> Graph::suggestFriends(const string& user) {
    unordered_set<string> suggestions;
    
    for (auto& friendPair : adjList[user]) {
        string friendOfUser = friendPair.first;
        
        for (auto& friendOfFriend : adjList[friendOfUser]) {
            if (friendOfFriend.first != user && adjList[user].end() == 
                find_if(adjList[user].begin(), adjList[user].end(), 
                [&](const auto& f) { return f.first == friendOfFriend.first; })) {
                suggestions.insert(friendOfFriend.first);
            }
        }
    }

    return vector<string>(suggestions.begin(), suggestions.end());
}

void Graph::dijkstra(const string& src) {
    unordered_map<string, int> dist;
    for (auto& node : adjList) {
        dist[node.first] = numeric_limits<int>::max();
    }
    dist[src] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, curr] = pq.top();
        pq.pop();

        for (auto& [neighbor, weight] : adjList[curr]) {
            int newDist = dist[curr] + weight;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }

    cout << "Shortest paths from " << src << ":\n";
    for (auto& [user, distance] : dist) {
        cout << user << ": " << distance << "\n";
    }
}

void Graph::displayNetwork() {
    for (auto& [user, friends] : adjList) {
        cout << user << " -> ";
        for (auto& [friendName, weight] : friends) {
            cout << "(" << friendName << ", " << weight << ") ";
        }
        cout << endl;
    }
}

void Graph::exportToFile(const string& filename) {
    ofstream outFile(filename);
    
    for (auto& [user, friends] : adjList) {
        for (auto& [friendName, weight] : friends) {
            outFile << user << " " << friendName << " " << weight << endl;
        }
    }

    outFile.close();
}
