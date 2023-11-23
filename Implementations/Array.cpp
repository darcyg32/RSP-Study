#include <iostream>

using namespace std;

int main() {
    // Initialize 1D array
    int array[] = {3, 2, 5, 1, 4, 7};
    int n = sizeof(array) / sizeof(int);

    // Print values
    for (int i = 0 ; i < n ; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";


    // Initialize 2D Array (You have to specify the number of all dimensions expect the first)
    char Array2D [][4] = {{'a','b','c','d'}, {'e','f','g','h'}, {'i','j','k','l'}};
    n = 3;
    int m = 4;

    // Print values
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << Array2D[i][j] << " ";
        }
    }
    cout << "\n";

    return 0;
}

// std::vectors represent dynamic arrays. They include:
    // Dynamic sizing
    // Automatic memory management
    // Flexibility
    // Member functions
    // Iterators