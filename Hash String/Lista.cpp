//
// Created by pedro on 25/05/2022.
//
#include <cstring>
#include "Lista.h"
#include "iostream"
using namespace std;

Lista::Lista(){
    this->tam = -1;
    this->inicio = nullptr;
    this->indexProx = -1;
}

Lista::~Lista(){
    // TODO
}

void Lista::insere(string chave) {

    if(this->inicio == nullptr){
        No * novoNo = new No;
        novoNo->setInfo(chave);
        novoNo->setProx(nullptr);
        this->inicio = novoNo;
        this->tam = this->tam + 1;
        return;
    }

    else if(strcmp(chave.c_str(), this->inicio->getInfo().c_str()) == 0){
        cout << "Chaves identicas";
        this->tam = this->tam + 1;
        return;
    }

    else {
        No * novoNo = new No;
        novoNo->setInfo(chave);
        novoNo->setProx(this->inicio);
        this->inicio = novoNo;
        this->tam = this->tam + 1;
    }
}

void Lista::iniciaLista(){
    this->tam = -1;
    this->inicio = nullptr;
    this->indexProx = -1;
}

void Lista::imprime(){
    if(this->inicio != nullptr){
        No * aux = this->inicio;
        while (aux){
            cout << aux->getInfo() << " ";
            aux = aux->getProx();
        }
    }else{
        cout << "Lista vazia!";
    }
}

No * Lista::getInicio(){
    return this->inicio;
}

int Lista::getTam(){
    return this->tam;
}

int Lista::getColisoes(){
    return this->colisoes;
}

void Lista::incrementaColicoes(){
    this->colisoes++;
}

void Lista::incrementaTam(){
    this->tam++;
}

int Lista::setIndexProx(int indexProx){
    return this->indexProx = indexProx;
}

int Lista::getIndexProx(){
    return this->indexProx;
}

