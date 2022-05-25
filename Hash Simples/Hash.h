//
// Created by pedro on 25/05/2022.
//

#ifndef HASH_SIMPLES_HASH_H
#define HASH_SIMPLES_HASH_H


#include "Lista.h"

class Hash {
private:
    int tam;
    Lista * tabela;

public:
    Hash(int tam);
    ~Hash();

    int funcaoHashPorDivisao(int chave);
    void insere(int chave);
    bool busca(int chave);
    void imprime();


};


#endif //HASH_SIMPLES_HASH_H
