#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class Node {
    public:
        T item;
        Node *next; // Pointer to next item in list

        // Constructor
        Node(T value) : item(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
    private:
        Node<T>* head;

    public:
        // Constructor
        LinkedList() : head(nullptr) {}

        // Destructor
        ~LinkedList() {
            clear();
            std::cout << "Destroyed Linked List.\n";
        }

        // Function to remove all elements from list
        void clear() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }

        // Iterative search function
        Node<T>* search(T x) {
            Node<T>* currNode = head;

            while (currNode != nullptr) {
                if (currNode->item == x) {
                    std::cout << "Node with item " << x << " found!\n";
                    return currNode;
                } else {
                    currNode = currNode->next;
                }
            }

            // If item not found, return nullptr
            std::cout << "Error: Node with item " << x << " not found.\n";
            return nullptr;
        }

        // Function to add an element to the start of the list
        void insert(T x) {
            // Create new node with given value
            Node<T>* newNode = new Node<T>(x);

            // Set the next pointer of the new node to the current head
            newNode->next = head;

            // Set the head pointer to the newNode
            head = newNode;

            std::cout << "Inserted node with item " << x << ".\n";
        }

        // Function to delete an element from the list
        void deleteNode(T x) {

            // Check if list is empty
            if (head == nullptr) {
                std::cout << "Error: List is empty.\n";
                return;
            }

            // Case where the node to be deleted is the head
            if (head->item == x) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                std::cout << "Deleted node with item " << x << " from head.\n";
                return;
            }

            // Find node to delete
            Node<T>* currNode = head;
            Node<T>* prevNode = nullptr;
            
            while (currNode != nullptr && currNode->item != x) {
                prevNode = currNode;
                currNode = currNode->next;
            }

            // If the node was not found
            if (currNode == nullptr) {
                std::cout << "Error: Node with item " << x << " not found.\n";
                return;
            }

            // Update the next pointer of the previous node
            prevNode->next = currNode->next;

            // Free memory
            delete currNode;
            std::cout << "Deleted node with item " << x << ".\n";
            return;
        }

        // Function to print elements of list
        void printList() {
            if (head == nullptr) {
                std::cout << "Error: List is empty.\n";
            }

            Node<T>* currNode = head;
            while (currNode != nullptr) {
                std::cout << currNode->item << " ";
                currNode = currNode->next;
            }
            std::cout << "\n";
        }
};

#endif