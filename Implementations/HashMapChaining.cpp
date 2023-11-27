#include "HashMapChaining.hpp"
#include <iostream>

using namespace std;

int main() {
    HashMap<std::string, int> myHashMap;

    // Insert key-value pairs
    myHashMap.insert("one", 1);
    myHashMap.insert("two", 2);
    myHashMap.insert("three", 3);

    // Retrieve and print values
    std::cout << "Value for key 'one': " << myHashMap.get("one") << std::endl;
    std::cout << "Value for key 'two': " << myHashMap.get("two") << std::endl;
    std::cout << "Value for key 'three': " << myHashMap.get("three") << std::endl;

    // Remove a key-value pair
    myHashMap.remove("two");

    // Attempt to retrieve the value for the removed key
    std::cout << "Value for key 'two' after removal: " << myHashMap.get("two") << std::endl;

    return 0;
}