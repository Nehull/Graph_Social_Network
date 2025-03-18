#include "graph.h"

int main() {
    Graph socialNetwork;

    // Adding users
    socialNetwork.addUser("Alice");
    socialNetwork.addUser("Bob");
    socialNetwork.addUser("Charlie");
    socialNetwork.addUser("David");

    // Adding friendships with weights
    socialNetwork.addFriendship("Alice", "Bob", 1);
    socialNetwork.addFriendship("Alice", "Charlie", 2);
    socialNetwork.addFriendship("Bob", "David", 3);
    socialNetwork.addFriendship("Charlie", "David", 1);

    cout << "\nNetwork Visualization:\n";
    socialNetwork.displayNetwork();

    cout << "\nBFS from Alice:\n";
    for (auto& user : socialNetwork.bfs("Alice")) {
        cout << user << " ";
    }

    cout << "\n\nDFS from Alice:\n";
    for (auto& user : socialNetwork.dfs("Alice")) {
        cout << user << " ";
    }

    cout << "\n\nMutual Friends between Bob and Charlie:\n";
    for (auto& friendName : socialNetwork.findMutualFriends("Bob", "Charlie")) {
        cout << friendName << " ";
    }

    cout << "\n\nFriend Suggestions for Alice:\n";
    for (auto& suggestion : socialNetwork.suggestFriends("Alice")) {
        cout << suggestion << " ";
    }

    cout << "\n\nDijkstra from Alice:\n";
    socialNetwork.dijkstra("Alice");

    socialNetwork.exportToFile("network.txt");

    return 0;
}
