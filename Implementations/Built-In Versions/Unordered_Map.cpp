#include <iostream>
#include <unordered_map>

int main() {
    // Creating an unordered_map
    std::unordered_map<int, std::string> myMap;

    // Inserting key-value pairs
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Displaying the elements
    std::cout << "Initial Map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Accessing elements
    std::cout << "\nValue at key 2: " << myMap[2] << std::endl;

    // Checking if a key is present
    if (myMap.find(4) != myMap.end()) {
        std::cout << "Key 4 is present." << std::endl;
    } else {
        std::cout << "Key 4 is not present." << std::endl;
    }

    // Modifying elements
    myMap[2] = "Two Modified";
    std::cout << "\nModified Map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Deleting elements
    myMap.erase(1);
    std::cout << "\nMap after erasing key 1:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Size of the map
    std::cout << "\nSize of the Map: " << myMap.size() << std::endl;

    // Clearing the map
    myMap.clear();
    std::cout << "\nMap after clearing:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
