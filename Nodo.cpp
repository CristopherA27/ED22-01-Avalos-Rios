#include "Nodo.hpp"
#include "Persona.hpp"

Nodo::Nodo(){
    Nodo * nodo = new Nodo();
    nodo->persona = NULL;
    nodo->next = NULL;
    return Nodo;
    
}

Nodo::Nodo(Persona persona){
    Nodo * n = new Nodo();
    n->persona = persona;
    return Nodo;
    
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

void Nodo::setPersona(Persona persona){
    this-> persona = persona;
}