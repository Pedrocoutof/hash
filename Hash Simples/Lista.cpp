//
// Created by pedro on 25/05/2022.
//
#include "Lista.h"

#include "iostream"
using namespace std;

Lista::Lista(){
    this->tam = -1;
    this->inicio = nullptr;
}

Lista::~Lista(){
    // TODO
}

void Lista::insere(int chave) {
    if(this->inicio == nullptr){
        No * novoNo = new No;
        novoNo->setInfo(chave);
        novoNo->setProx(nullptr);
        this->inicio = novoNo;
        this->inicio++;
    }
    else{
        No * novoNo = new No;
        novoNo->setInfo(chave);
        novoNo->setProx(this->inicio);
        this->inicio = novoNo;
        this->inicio++;
    }
}

void Lista::iniciaLista(){
    this->tam = -1;
    this->inicio = nullptr;
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
