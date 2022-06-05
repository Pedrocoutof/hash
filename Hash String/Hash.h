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
    unsigned int tam;
    const float A = 0.4;
    Lista * tabela;
    int funcaoHashPorDivisao(int chave);
    int funcaoHashPorMultiplicacao(int chave);

public:
    Hash(int tam);
    ~Hash();

    int funcaoHashPorDivisaoParaString(string chave);
    void insere(string chave, string metodo = "");
    Lista * busca(string chave);
    void imprime();


    bool posicaoVazia(int index);

    void insereSondagemLinear(string chave, string metodo = "");
    void insereDuploHash(string chave, string metodo = "");

    bool verificaChaveIdentica(string chave);

    void salvaTabelaHashTxt(string arqNome);

    int duploHash();

    int funcaoHashPorMultiplicacaoParaString(string chave);

    int duploHash(int indexBase, string chave, int tentativas);

    void salvaTabelaHashCSV(string nomeArquivo, bool ignoraPosicaoVazia = true);

    int buscaRetornaIndex(string chave);

    void imprimePorIndex();

    void imprimePorIndex(int index);
};


#endif //HASH_SIMPLES_HASH_H
