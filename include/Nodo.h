#ifndef Nodo_h
#define Nodo_h

class Nodo
{
private:
    Nodo *next;
    char letra;
public:
    Nodo();
    Nodo(char letra);
    Nodo *getNext();
    char getLetra();
    void setNext(Nodo *next);
};

#endif