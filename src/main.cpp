#include <iostream>
#include "logic/includes/Nodo.h"

using namespace std;
int main(int, char**) {
    Nodo *n = new Nodo(10);
    cout<<"Numero del nodo"<< n->getNumber()<<endl;
    std::cout << "Hello, world!\n";
}

