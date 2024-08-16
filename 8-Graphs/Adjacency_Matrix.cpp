#include <iostream>
using namespace std;

void displayAdjMatrix(int **adjMatrix, int V) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // dynamically allocate memory for adjacency matrix
    int **adjMatrix = new int*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new int[V];
    }

    // input adjacency matrix from user
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    // display adjacency matrix
    displayAdjMatrix(adjMatrix, V);

    // free dynamically allocated memory for adjacency matrix
    for (int i = 0; i < V; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
