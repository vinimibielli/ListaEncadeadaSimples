#include "ListaEncadeada.h"
#include <iostream>

ListaEncadeada::ListaEncadeada()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    Nodo *nodoAtual = this->head;
    Nodo *nodoAnterior = nullptr;
    while (nodoAtual != nullptr)
    {
        nodoAnterior = nodoAtual;
        nodoAtual = nodoAtual->getNext();
        delete nodoAnterior;
    }
}

void ListaEncadeada::adicionar(char letra)
{
    Nodo *novoNodo = new Nodo(letra);
    if (this->head == nullptr)
    {
        this->head = novoNodo;
        this->tail = novoNodo;
    }
    else
    {
        this->tail->setNext(novoNodo);
        this->tail = novoNodo;
        this->size++;
    }
}

void ListaEncadeada::adicionarInicio(char letra)
{
    Nodo *novoNodo = new Nodo(letra);
    if (this->head == nullptr)
    {
        this->head = novoNodo;
        this->tail = novoNodo;
    }
    else
    {
        Nodo *aux = this->head;
        this->head = novoNodo;
        this->head->setNext(aux);
        this->size++;
    }
}

void ListaEncadeada::adicionarPosicao(char letra, int posicao)
{
    Nodo *novoNodo = new Nodo(letra);
    if (this->head == nullptr)
    {
        this->head = novoNodo;
        this->tail = novoNodo;
    }
    else
    {
        if (posicao <= 0)
        {
            this->adicionarInicio(letra);
        }
        else if (posicao >= this->size)
        {
            this->adicionar(letra);
        }
        else
        {
            Nodo *aux = this->head;
            for (int i = 0; i < posicao - 1; i++)
            {
                aux = aux->getNext();
            }
            novoNodo->setNext(aux->getNext());
            aux->setNext(novoNodo);
            this->size++;
        }
    }
}

void ListaEncadeada::remover()
{
    if (this->head == nullptr)
    {
        std::cout << "Lista vazia" << std::endl;
    }
    else
    {
        Nodo *aux = this->head;
        while(aux->getNext() != this->tail)
        {
            aux = aux->getNext();
        }
        aux->setNext(nullptr);
        this->tail = aux;
         delete aux;
        this->size--;
    }
}

void ListaEncadeada::removerInicio()
{
    if (this->head == nullptr)
    {
        std::cout << "Lista vazia" << std::endl;
    }
    else
    {
        Nodo *aux = this->head;
        this->head = aux->getNext();
        delete aux;
        this->size--;
    }
}

void ListaEncadeada::removerPosicao(int posicao){
    if(this->head == nullptr){
        std::cout << "Lista vazia" << std::endl;
    } else {
        if(posicao <= 0){
            this->removerInicio();
        } else if(posicao >= this->size){
            this->remover();
        } else {
            Nodo *aux = this->head;
            for(int i = 0; i < posicao - 1; i++){
                aux = aux->getNext();
            }
            Nodo *aux2 = aux->getNext();
            aux->setNext(aux2->getNext());
            delete aux2;
            this->size--;
        }
    }
}

bool ListaEncadeada::listaVazia()
{
    if(size == 0){
        return true;
    } else {
        return false;
    }
}

int ListaEncadeada::encontrarPosicao(char letra)
{
    if (this->head == nullptr)
    {
        std::cout << "Lista vazia" << std::endl;
        return -1;
    }
    else
    {
        Nodo *aux = this->head;
        int posicao = 0;
        while (aux != nullptr)
        {
            if (aux->getLetra() == letra)
            {
                return posicao;
            }
            aux = aux->getNext();
            posicao++;
        }
        return -1;
    }
}

bool ListaEncadeada::contem(char letra)
{
    if (this->head == nullptr)
    {
        std::cout << "Lista vazia" << std::endl;
        return false;
    }
    else
    {
        Nodo *aux = this->head;
        while (aux != nullptr)
        {
            if (aux->getLetra() == letra)
            {
                return true;
            }
            aux = aux->getNext();
        }
        return false;
    }
}