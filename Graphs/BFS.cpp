#include<iostream>
#include <stdlib.h>
#include "queue.cpp"
using namespace std;

const int m_size = 100;

int adj_matrix[m_size][m_size];    // adjacency matrix
bool visited[m_size];      // visited array
int vertices,  edges; // number of vertices
Queue <int> q;

bool IsEmpty()
{
    
}
void bfs(int source, int dest) {
    visited[source] = true;
    q.Enqueue(source);
    while (q.Front() != q.Rear()) {
        int v1 = q.Dequeue();
        if (v1 == dest) {
            cout << "Path found!" << endl;
            return;
        }
        for (int v2 = 1; v2 <= vertices; v2++) {
            if (adj_matrix[v1][v2] == 1 && !visited[v2]) {
                visited[v1] = true;
                q.Enqueue(v2);
            }
        }
    }
    cout << "Path not found!" << endl;
}

int main() {
    int source, dest, v1, v2;
     cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // read edge information from user and update adjacency matrix
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        cout << "Enter edge " << i+1 << " (v1 v2): ";
        cin >> v1 >> v2;
        adj_matrix[v1][v2] = 1;
        adj_matrix[v2][v1] = 1; // if the graph is undirected
    }
    // cout << "Enter the number of vertices: ";
    // cin >> vertices;
    // cout << "Enter the adjacency matrix:" << endl;
    // for (int i = 1; i <= vertices; i++) {
    //     for (int j = 1; j <= vertices; j++) {
    //         cin >> adj_matrix[i][j];
    //     }
    // }
    cout << "Enter the source and destination vertices: ";
    cin >> source >> dest;
    bfs(source, dest);
    return 0;
}
