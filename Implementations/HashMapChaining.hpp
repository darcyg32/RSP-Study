#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include <list>
#include <iterator>

const int TABLE_SIZE = 10; // Size of the hash table

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
        std::list<KeyValuePair<K, V>> table[TABLE_SIZE]; // Array of linked lists

        // A simple hash function to determine the index of the key in the hash table
        int hashFunction(const K& key) {
            return std::hash<K>{}(key) % TABLE_SIZE;
        }

    public:
        // Insert a key-value pair into the hashmap
        void insert(const K& key, const V& value) {
            int index = hashFunction(key);
            table[index].push_back(KeyValuePair<K, V>(key, value));
        }

        // Retrieve the value associated with a given key
        V get(const K& key) {
            int index = hashFunction(key);

            // Search for the key in the linked list at the calculated index
            for (auto& kv : table[index]) {
                if (kv.key == key) {
                    return kv.value; // Return the value if the key is found
                }
            }

            // Else, return a default value
            return V();
        }

        // Remove a key-value pair from the hashmap
        void remove(const K& key) {
            int index = hashFunction(key);

            // Iterate thorugh the linked list at the calculated index
            for (auto it = table[index].begin(); it != table[index].end(); it++) {
                if (it->key == key) {
                    table[index].erase(it); // Remove the key-value pair if the key is found
                    return;
                }
            }
        }
};

#endif