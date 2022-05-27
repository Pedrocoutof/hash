//
// Created by pedro on 25/05/2022.
//

#ifndef HASH_SIMPLES_LISTA_H
#define HASH_SIMPLES_LISTA_H


#include "No.h"

#include "string"
using namespace std;

class Lista {
private:
    No * inicio;
    int tam;
    // AO INVES DE GUARDAR COLISOES, GUARDAR POSICAO DO QUE COLIDIU
    int colisoes;
    int indexProx;

public:
    Lista();
    ~Lista();

    void insere(string chave);
    void imprime();
    void iniciaLista();

    No * getInicio();
    int getTam();

    int getColisoes();
    void incrementaColicoes();

    int setColisoes(int indexProx);

    int getIndexProx();

    int setIndexProx(int indexProx);

    void incrementaTam();
};


#endif //HASH_SIMPLES_LISTA_H
