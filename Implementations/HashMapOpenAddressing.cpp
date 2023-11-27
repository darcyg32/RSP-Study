#include "HashMapOpenAddressing.hpp"
#include <iostream>
using namespace std;

int main()
{
    HashMap<int, int>* h = new HashMap<int, int>;
    h->insert(1, 109);
    h->insert(2, 346);
    h->insert(2, 1255);
    h->insert(20, 122);
    h->insert(12, 11124);
    h->insert(53, 999);
    h->display();
    cout << h->sizeofMap() << endl;
    h->remove(2);
    cout << h->sizeofMap() << endl;
    cout << h->isEmpty() << endl;
    cout << h->get(2) << endl;
    cout << h->get(1) << endl;
    h->remove(1);
    h->display();
 
    return 0;
}