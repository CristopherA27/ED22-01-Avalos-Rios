#include "Nodo.hpp"
#include "Persona.hpp"


#include <iostream>
#include <string>

using namespace std;

class LinkedList{
    private:
        Nodo *first;
    public:
        LinkedList(){
            first = NULL;
        }

    void addNode(Persona persona){
        Nodo *nuevo = new Nodo;
        nuevo->persona = persona;
        nuevo -> setNext(NULL);

        if(first == NULL){
            first == nuevo;
        }

        
    }

};