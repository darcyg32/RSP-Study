#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the length of the Longest Increasing Subsequence
int longestIncreasingSubsequence(const std::vector<int>& sequence) {
    int n = sequence.size();

    // Initialize an array to store the length of the LIS ending at each index
    std::vector<int> lis(n, 1);

    // Dynamic Programming: Compute the LIS for each index i
    for (int i = 1; i < n; ++i) {
        // Iterate over all indices j where j < i
        for (int j = 0; j < i; ++j) {
            // Check if the element at index i can extend the LIS ending at index j
            if (sequence[i] > sequence[j] && lis[i] < lis[j] + 1) {
                // Update the LIS at index i with the maximum length found so far
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Find the maximum LIS value in the lis array
    int maxLIS = *std::max_element(lis.begin(), lis.end());

    // Return the length of the Longest Increasing Subsequence
    return maxLIS;
}

int main() {
    std::vector<int> sequence = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    
    int result = longestIncreasingSubsequence(sequence);

    std::cout << "Length of the Longest Increasing Subsequence: " << result << std::endl;

    return 0;
}
