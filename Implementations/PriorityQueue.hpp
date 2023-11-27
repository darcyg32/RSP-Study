#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

template <typename T>
class PriorityQueue {
    private:
        // Binary heap to store elements
        std::vector<T> heap;

        // Move the element up the heap to maintain the heap property after insertion
        void heapifyUp() {
            int index = size() - 1;                             // Start with the last element
            while (index > 0) {
                int parentIndex = (index - 1) / 2;              // Calculate parent index
                if (heap[index] < heap[parentIndex]) {          // If the current element is smaller than its parent
                    std::swap(heap[index], heap[parentIndex]);  // Swap them
                    index = parentIndex;                        // Move up to the parent
                } else {
                    break;                                      // If the heap property is satisfied, break out of the loop
                }
            }
        }

        // Move the element down the heap to maintain the heap property after removal
        void heapifyDown() {
            int index = 0; // Start from the root
            int leftChild, rightChild, minIndex;
            while (true) {
                leftChild = 2 * index + 1;                      // Calculate left child index
                rightChild = 2 * index + 2;                     // Calculate right child index
                minIndex = index;                               // Assume the current index has the minimum value

                // Check if the left child is smaller than the current minimum
                if (leftChild < T(size()) && heap[leftChild] < heap[minIndex]) {
                    minIndex = leftChild;
                }

                // Check if the right child is smaller than the current minimum
                if (rightChild < T(size()) && heap[rightChild] < heap[minIndex]) {
                    minIndex = rightChild;
                }

                if (minIndex != index) {
                    // If the minimum is not at the current index, swap with the minimum
                    std::swap(heap[index], heap[minIndex]);
                    index = minIndex;                           // Move down to the minimum
                } else {
                    break;                                      // If the heap property is satisfied, break out of the loop
                }
            }
        }

    public:
        bool empty() const {
            return heap.empty();
        }

        size_t size() const {
            return heap.size();
        }

        const T& top() const {
            if (empty()) {
                throw std::out_of_range("PriorityQueue is empty");
            }
            return heap[0];
        }

        void push(const T& value) {
            heap.push_back(value);  // Add the element to the end of the heap
            heapifyUp();            // Restore the heap property by moving the element up
        }

        void pop() {
            if (empty()) {
                throw std::out_of_range("PriorityQueue is empty");
            }

            heap[0] = heap.back();  // Replace the root with the last element
            heap.pop_back();        // Remove the last element
            heapifyDown();          // Restore the heap property by moving the new root down
        }
};

#endif