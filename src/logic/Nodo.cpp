#include "includes/Nodo.h"

Nodo::Nodo(){

}

Nodo::Nodo(int numero){
    this->numero = numero;
}  
void Nodo::setNext(Nodo* nodo){
    this->next = nodo;
}
Nodo* Nodo::getNext(){
    return this->next;
}
int Nodo::getNumber(){
    return this->numero;
}
Nodo :: ~Nodo(){

}