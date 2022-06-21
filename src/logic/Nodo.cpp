#include "includes/Nodo.h"
#include "Persona.cpp"

Nodo::Nodo(){

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
int Nodo::getPersona(){
    return this->persona;
}
Nodo :: ~Nodo(){

}