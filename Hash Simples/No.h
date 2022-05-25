//
// Created by pedro on 25/05/2022.
//

#ifndef HASH_SIMPLES_NO_H
#define HASH_SIMPLES_NO_H


class No {
private:
    int info;
    No * prox;

public:
    void setInfo(int chave);
    void setProx(No * novoNo);
    int getInfo();
    No * getProx();
};


#endif //HASH_SIMPLES_NO_H
