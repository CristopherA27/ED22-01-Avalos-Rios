#include "Persona.hpp"

class Nodo{
    private:
    Persona persona;
    Nodo* next;

    public:
    Nodo();
    Nodo(Persona persona);
    void setNext(Nodo* nodo);
    Nodo* getNext();
    int getPersona();
    ~Nodo();
};