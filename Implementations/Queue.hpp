#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept> // Required for std::runtime_error

template <typename T>
class Queue {
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* front;
        Node* rear;

    public:
        Queue() : front(nullptr), rear(nullptr) {}

        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }

        void enqueue(const T& value) {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue() {
            if (!isEmpty()) {
                Node *temp = front;
                front = front->next;
                delete temp;
                if (front == nullptr) {
                    rear = nullptr; // If the queue is now empty, update the rear pointer as well
                }
            }
        }

        T peek() {
            if (!isEmpty()) {
                return front->data;
            } else {
                throw std::runtime_error("Queue is empty. Cannot peek.");
            }
        }

        bool isEmpty() {
            return front == nullptr;
        }
};

#endif