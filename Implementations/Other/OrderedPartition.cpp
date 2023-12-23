#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100;  // Adjust the value of MAXN as needed
const int MAXINT = 1e9; // A large value representing infinity

void print_books(int s[], int start, int end);
void reconstruct_partition(int s[], int d[MAXN + 1][MAXN + 1], int n, int k);

void partition(int s[], int n, int k) {
    int p[MAXN + 1];              // Prefix sums array
    int m[MAXN + 1][MAXN + 1];    // DP table for values
    int d[MAXN + 1][MAXN + 1];    // DP tables for dividers
    int cost;                     // Test split cost
    int i, j, x;                  // Counters

    // Construct prefix sums
    p[0] = 0;
    for (i = 1; i <= n; i++) {
        p[i] = p[i - 1] + s[i];
    }

    // Initialize boundaries
    for (i = 1; i <= n; i++) {
        m[i][1] = p[i];
    }

    for (j = 1; j <= k; j++) {
        m[1][j] = s[1];
    }

    

    // Evaluate main recurrence
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            // Initialize the minimum cost to a large value
            m[i][j] = MAXINT;

            // Iterate through possible positions to split the array
            for (x = 1; x <= (i - 1); x++) {
                // Calculate the cost of the current split
                cost = max(m[x][j - 1], p[i] - p[x]);

                // Update the minimum cost and store the position of the divider
                if (m[i][j] > cost) {
                    m[i][j] = cost;
                    d[i][j] = x;
                }
            }
        }
    }

    std::cout << max(m[1][2 - 1], p[3] - p[1]);

    for (i = 0; i <= n ; i++) {
        for (j = 0; j <= k ; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Use the results in m[][] and d[][] as needed in your application
    // For example, you can call reconstruct_partition(s, d, n, k) to print the partitions
    reconstruct_partition(s, d, n, k);
}

void reconstruct_partition(int s[], int d[MAXN + 1][MAXN + 1], int n, int k) {
    if (k == 1) {
        print_books(s, 1, n);
    } else {
        reconstruct_partition(s, d, d[n][k], k - 1);
        print_books(s, d[n][k] + 1, n);
    }
}

void print_books(int s[], int start, int end) {
    int i;    // Counter

    cout << "{";
    for (i = start; i <= end; i++) {
        cout << " " << s[i] << " ";
    }
    cout << "}" << endl;
}

int main() {
    // Example usage
    const int n = 9;
    const int k = 3;
    int s[n + 1] = {0,1,2,3,4,5,6,7,8,9};  // Adjust the array values as needed

    partition(s, n, k);

    return 0;
}
