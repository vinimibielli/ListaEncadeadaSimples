#ifndef ListaEncadeada_h
#define ListaEncadeada_h

#include "Nodo.h"

class ListaEncadeada
{
private:
    Nodo *head;
    Nodo *tail;
    int size;
public:
    ListaEncadeada(); // Criar Lista
    ~ListaEncadeada(); // Destruir Lista
    void adicionar(char letra);
    void adicionarInicio(char letra);
    void adicionarPosicao(char letra, int posicao);
    void remover();
    void removerInicio();
    void removerPosicao(int posicao);
    bool listaVazia();
    int encontrarPosicao(char letra);
    bool contem(char letra);

};

#endif