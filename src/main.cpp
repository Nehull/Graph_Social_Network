#include "graph.h"

int main() {
    Graph socialNetwork;

    // Adding users
    socialNetwork.addUser("Nehul");
    socialNetwork.addUser("Nakul");
    socialNetwork.addUser("Shreyash");
    socialNetwork.addUser("Aryan");

    // Adding friendships with weights
    socialNetwork.addFriendship("Nehul", "Nakul", 1);
    socialNetwork.addFriendship("Nehul", "Shreyash", 2);
    socialNetwork.addFriendship("Nakul", "Aryan", 3);
    socialNetwork.addFriendship("Shreyash", "Aryan", 1);

    cout << "\nNetwork Visualization:\n";
    socialNetwork.displayNetwork();

    cout << "\nBFS from Nehul:\n";
    for (auto& user : socialNetwork.bfs("Nehul")) {
        cout << user << " ";
    }

    cout << "\n\nDFS from Nehul:\n";
    for (auto& user : socialNetwork.dfs("Nehul")) {
        cout << user << " ";
    }

    cout << "\n\nMutual Friends between Nakul and Shreyash:\n";
    for (auto& friendName : socialNetwork.findMutualFriends("Nakul", "Shreyash")) {
        cout << friendName << " ";
    }

    cout << "\n\nFriend Suggestions for Nehul:\n";
    for (auto& suggestion : socialNetwork.suggestFriends("Nehul")) {
        cout << suggestion << " ";
    }

    cout << "\n\nDijkstra from Nehul:\n";
    socialNetwork.dijkstra("Nehul");

    socialNetwork.exportToFile("network.txt");

    return 0;
}

