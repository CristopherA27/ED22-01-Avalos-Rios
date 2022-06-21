#include "Nodo.hpp"
#include "Persona.hpp"

Nodo::Nodo(){
    Nodo * nodo = new Nodo();
    nodo->persona = persona;
    nodo->next = NULL;
}

Nodo::Nodo(Persona persona){
    this->persona = persona;
}  
void Nodo::setNext(Nodo* nodo){
    this->next = nodo;
}
Nodo* Nodo::getNext(){
    return this->next;
}
Persona Nodo::getPersona(){
    return this->persona;
}
Nodo :: ~Nodo(){

}