#include <iostream>

using namespace std;

const int Vertices_limit = 100;

int main() {

    int adj_matrix[Vertices_limit][Vertices_limit] = {0}; // initialize adjacency matrix with 0
    
    int vertices, edges, weight;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // read edge information from user and update adjacency matrix
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        cout << "Enter edge " << i+1 << " (v1 v2 weight): ";
        cin >> v1 >> v2>> weight;
        adj_matrix[v1][v2] = weight;
    }

    // print adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
