#include <iostream>

using namespace std;

void min_heap(int array[], int n, int parent) {
    int smallest = parent;
    int left = 2 * parent ;
    int right = 2 * parent + 1;

    if (left <= n && array[left] > array[smallest])
        smallest = left;

    if (right <= n && array[right] > array[smallest])
        smallest = right;

    if (smallest != parent) {
        swap(array[parent], array[smallest]); 
        min_heap(array, n, smallest);               // proof checking for sub trees
    }
}


void build_min(int array[], int n) {
    int i = n / 2 ;                     //setting iteration for half -1 times of array size
                                        // probably 1 before half    
    for (int parent = i ; parent > 0; parent--)
        min_heap(array, n, parent);     //sending parent as root
}

void print_arrayay(int array[], int n) {
    cout << "Heaped array: ";
    for (int i = 1; i <= n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void in_order_traversal(int array[], int n, int root) {
    if (root > n)
        return;
    cout<<array[root]<<" | ";
    in_order_traversal(array, n, 2*root );      // traverse left subtree
    in_order_traversal(array, n, 2*root+1);     // traverse right subtree
}



int main() {
    int n;
    cout << "Enter the size of the arrayay: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements of the arrayay: ";
    for (int i = 1; i <= n; i++)
        cin >> array[i];

    print_arrayay(array, n);
    build_min(array, n);
    print_arrayay(array, n);
    cout<<"IN-ORDER: ";
    in_order_traversal(array, n, 1);

    return 0;
}
