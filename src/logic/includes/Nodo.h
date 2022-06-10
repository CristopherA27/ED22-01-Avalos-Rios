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