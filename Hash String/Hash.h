//
// Created by pedro on 25/05/2022.
//

#ifndef HASH_SIMPLES_HASH_H
#define HASH_SIMPLES_HASH_H


#include "Lista.h"
#include "math.h"

#include "string"
using namespace std;

class Hash {
private:
    int tam;
    const float A = 0.4;
    Lista * tabela;
    int funcaoHashPorDivisao(int chave);
    int funcaoHashPorMultiplicacao(int chave);

public:
    Hash(int tam);
    ~Hash();

    int funcaoHashPorDivisaoParaString(string chave);
    int funcaoHashPorMultiplicacaoParaString(string chave);
    void insere(string chave, string metodo = "");
    bool busca(string chave);
    void imprime();


};


#endif //HASH_SIMPLES_HASH_H
