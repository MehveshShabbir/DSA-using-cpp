#include<iostream>
#include<queue> // for queue data structure
using namespace std;

const int MAX = 100;

int graph[MAX][MAX]; // adjacency matrix
bool visited[MAX]; // visited array
int n; // number of vertices

// Function to perform BFS from a given start vertex to a given destination vertex
void bfs(int start, int dest) {
    queue<int> q;
    vector<int> path(n + 1, -1); // initialize all path elements to -1
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == dest) {
            // found the destination, print the path and return
            vector<int> path_nodes;
            int current_node = u;
            while (current_node != -1) {
                path_nodes.push_back(current_node);
                current_node = path[current_node];
            }
            cout << "Path found: ";
            for (int i = path_nodes.size() - 1; i >= 0; i--) {
                cout << path_nodes[i];
                if (i != 0) {
                    cout << " -> ";
                }
            }
            cout << endl;
            return;
        }
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                path[v] = u; // set the previous node of v to u
                q.push(v);
            }
        }
    }
    cout << "Path not found!" << endl;
}


int main() {
    int start, dest;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the source and destination vertices: ";
    cin >> start >> dest;
    bfs(start, dest);
    return 0;
}
