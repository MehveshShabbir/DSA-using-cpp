#include <iostream>

using namespace std;

const int MAX_SIZE = 10; // maximum number of vertices in the graph

int graph[MAX_SIZE][MAX_SIZE]; // adjacency matrix to store the graph
bool visited[MAX_SIZE]; // array to keep track of visited vertices

void DFS(int v, int dest, int n) {
    visited[v] = true; // mark current vertex as visited
    
    if(v == dest){
        cout << v << " "; // print the vertex if it is the destination
        return;
    }
    
    cout << v << " "; // print the current vertex
    
    // recursively visit all adjacent vertices of the current vertex
    for(int i=0; i<n; i++) {
        if(graph[v][i] && !visited[i]) {
            DFS(i, dest, n);
        }
    }
}

int main() {
    int n, src, dest;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    
    // initialize the adjacency matrix with 0
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }
    
    // take input from user and populate the adjacency matrix
    int u, v;
    while(true) {
        cout << "Enter an edge (u v) (enter -1 to stop): ";
        cin >> u >> v;
        if(u == -1 || v == -1) {
            break;
        }
        graph[u][v] = 1;
        graph[v][u] = 1; // assuming undirected graph
    }
    
    cout << "Enter the source vertex: ";
    cin >> src;
    
    cout << "Enter the destination vertex: ";
    cin >> dest;
    
    cout << "DFS traversal from " << src << " to " << dest << ": ";
    DFS(src, dest, n);
    cout << endl;
    
    return 0;
}
