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

int Hash::funcaoHashPorMultiplicacao(int chave){
    return tam * ( fmod(chave * A, 1));
}

int Hash::funcaoHashPorDivisaoParaString(string chave){
    unsigned int aux = 0;

    for(int i = 0; i < chave.length(); i++){
        aux += chave[i] * (i + 1);
    }

    return funcaoHashPorDivisao(aux);
}

int Hash::funcaoHashPorMultiplicacaoParaString(string chave){
    unsigned int aux = 0;

    for(int i = 0; i < chave.length(); i++){
        aux += chave[i] * (i + 1);
    }

    return funcaoHashPorDivisao(aux);
}

void Hash::insere(string chave, string metodo){

    if(metodo.compare("multiplicacao")){
        this->tabela[funcaoHashPorMultiplicacaoParaString(chave)].insere(chave);
    }

    //Utilizando como padrao o metodo da divisao
    else{
        this->tabela[funcaoHashPorDivisaoParaString(chave)].insere(chave);
    }
}

bool Hash::busca(string chave){
    if(this->tabela[funcaoHashPorDivisaoParaString(chave)].getInicio() != nullptr){
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