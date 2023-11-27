#ifndef HASHTABLEOPENADDRESSING_H
#define HASHTABLEOPENADDRESSING_H
#include <iostream>

// Class representing a key-value pair
template <typename K, typename V>
class KeyValuePair {
    public:
        K key;
        V value;

        KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
};

// Hashmap class
template <typename K, typename V>
class HashMap {
    private:
        int capacity;
        int size;
        KeyValuePair<K, V>** arr; // Hash element array
        KeyValuePair<K, V>* dummy;    // Dummy node

        // A simple hash function to determine the index of the key in the hash table
        int hashFunction(const K& key) {
            return key % capacity;
        }

    public:
        // Constructor
        HashMap() {
            // Initial capacity of hash array
            capacity = 20;
            size = 0;
            arr = new KeyValuePair<K, V>*[capacity];

            // Initialize all elements of arr as V{}
            for (int i = 0 ; i < capacity ; i++) {
                arr[i] = nullptr;
            }

            // Dummy node with value and key -1
            dummy = new KeyValuePair<K, V>(-1, -1);
        }

        // Function to insert key value pair
        void insert(K key, V value) {
            KeyValuePair<K, V>* temp = new KeyValuePair<K, V>(key, value);

            // Apply hash function to get index for given key
            int hashIndex = hashFunction(key);

            // Find next free space using linear probing
            while (arr[hashIndex] != nullptr && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
                hashIndex++;
                hashIndex %= capacity;
            }

            // If the key already exists, update the value
            if (arr[hashIndex] != nullptr && arr[hashIndex]->key == key) {
                arr[hashIndex]->value = value;
            } else {
                // If new node to be inserted, increase the current size
                if (arr[hashIndex] == nullptr || arr[hashIndex]->key == -1) {
                    size++;
                }
                arr[hashIndex] = temp;
            }
        }

        // Function to delete a key value pair
        void remove (K key) {
            int hashIndex = hashFunction(key);

            while (arr[hashIndex] != V{}) {
                if (arr[hashIndex]->key == key) {
                    KeyValuePair<K, V>* temp = arr[hashIndex];

                    arr[hashIndex] = dummy;

                    size--;
                    delete temp;
                    return;
                }
                hashIndex++;
                hashIndex %= capacity;
            }

        }

        // Function to find the value for a given key
        V get(K key) {
            int hashIndex = hashFunction(key);
            int counter = 0;

            // Find the key using linear probing
            while (arr[hashIndex] != nullptr) {
                if (counter++ > capacity) {
                    return V{};
                }

                if (arr[hashIndex]->key == key) {
                    return arr[hashIndex]->value;
                }

                hashIndex++;
                hashIndex %= capacity;
            }

            return V{};
        }

        // Return current size
        int sizeofMap() {
            return size;
        }

        // Return true is size is 0
        bool isEmpty() {
            return size == 0;
        }

        // Display stored key value pairs
        void display() {
            for (int i = 0 ; i < capacity ; i++) {
                if (arr[i] != V{} && arr[i]->key != -1) {
                    std::cout << "key = " << arr[i]->key << " value = " << arr[i]->value << "\n";
                }
            }
        }
};

#endif