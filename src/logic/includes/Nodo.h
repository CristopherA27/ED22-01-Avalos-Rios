#ifndef ED22_01_AVALOS_RIOS_NODO_H
#define ED22_01_AVALOS_RIOS_NODO_H

class Nodo{
    private:
    int numero;
    Nodo* next;

    public:
    Nodo();
    Nodo(int numero);
    void setNext(Nodo* nodo);
    Nodo* getNext();
    int getNumber();
    ~Nodo();
};

//#endif //ED22_01_AVALOS_RIOS_NODO_H