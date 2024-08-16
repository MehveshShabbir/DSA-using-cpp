#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int MAX_SIZE = 100;

void dfs(int G[][MAX_SIZE], bool visited[], int v, int dest) {
    visited[v] = true;
    cout << v << " ";

    if (v == dest)
        return;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (G[v][i] == 1 && !visited[i])
            dfs(G, visited, i, dest);
    }
}

void bfs(int G[][MAX_SIZE], bool visited[], int v, int dest) {
    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        if (curr == dest)
            break;

        for (int i = 0; i < MAX_SIZE; i++) {
            if (G[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, m, u, v, source, dest;
    int G[MAX_SIZE][MAX_SIZE] = {0};
    bool visited[MAX_SIZE] = {false};

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Enter the edge (u, v): ";
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    cout << "Enter the destination vertex: ";
    cin >> dest;

    cout << "DFS from source vertex " << source << ": ";
    dfs(G, visited, source, dest);
    cout << endl;

    for (int i = 0; i < MAX_SIZE; i++)
        visited[i] = false;

    cout << "BFS from source vertex " << source << ": ";
    bfs(G, visited, source, dest);
    cout << endl;

    return 0;
}
