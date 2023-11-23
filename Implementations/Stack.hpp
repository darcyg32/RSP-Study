#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stdexcept> // Required for std::runtime_error

template <typename T>
class Stack {
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* top;

    public:
        Stack() : top(nullptr) {}

        ~Stack() {
            while (!isEmpty()) {
                pop();
            }
        }

        void push(const T& value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (!isEmpty()) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

        T peek() {
            if (!isEmpty()) {
                return top->data;
            } else {
                throw std::runtime_error("Stack is empty. Cannot peek.");
            }
        }

        bool isEmpty() {
            return top == nullptr;
        }
};

#endif