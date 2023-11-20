#include "nodo.h"

Nodo::Nodo()
{
    this->letra = ' ';
    this->next = nullptr;
}

Nodo::Nodo(char letra)
{
    this->letra = letra;
    this->next = nullptr;
}

Nodo *Nodo::getNext()
{
    return this->next;
}

char Nodo::getLetra()
{
    return this->letra;
}

void Nodo::setNext(Nodo *next)
{
    this->next = next;
}

char Nodo::getLetra()
{
    return this->letra;
}