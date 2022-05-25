//
// Created by pedro on 25/05/2022.
//

#include "Hash.h"

#include "iostream"
using namespace std;

Hash::Hash(int tam){
    this->tam = tam;
    this->tabela = new Lista [tam];

    for(int i = 0; i < tam; i++)
        tabela[i].iniciaLista();
}

Hash::~Hash(){
    delete [] this->tabela;
}

int Hash::funcaoHashPorDivisao(int chave) {
    return (chave % this->tam);
}

void Hash::insere(int chave){
    this->tabela[funcaoHashPorDivisao(chave)].insere(chave);
}

bool Hash::busca(int chave){
    if(this->tabela[funcaoHashPorDivisao(chave)].getInicio() != nullptr){
        return true;
    }
    return false;
}

void Hash::imprime() {
    cout << endl << "=== Imprimindo Lista ===" << endl;
    for(int i = 0; i < this->tam; i++){
        cout << "[" << i << "] - ";
        this->tabela[i].imprime();
        cout << endl;
    }

    cout << endl << "========================";
}