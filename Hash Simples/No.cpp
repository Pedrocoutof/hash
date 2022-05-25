//
// Created by pedro on 25/05/2022.
//

#include "No.h"


void No::setInfo(int chave) {
    this->info = chave;
}

void No::setProx(No *novoNo) {
    this->prox = novoNo;
}

int No::getInfo(){
    return this->info;
}

No * No::getProx(){
    return this->prox;
}