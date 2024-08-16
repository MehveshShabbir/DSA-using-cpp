#include <iostream>

using namespace std;

const int Vertices_limit = 100;

int main() {

    int adj_matrix[Vertices_limit][Vertices_limit] = {0}; // initialize adjacency matrix with 0
    
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // read edge information from user and update adjacency matrix
    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cout << "Enter edges for " << i << " (v1 v2): ";
        cin >> v1 >> v2;
        adj_matrix[v1][v2] = 1;
        adj_matrix[v2][v1] = 1; // if the graph is undirected
    }

    // print adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= vertices; i++) {
        cout<<"Vertex "<<i<<" : ";
        for (int j = 1; j <= vertices; j++) {
            if(adj_matrix[i][j] != 0)
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
