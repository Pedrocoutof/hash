//
// Created by pedro on 25/05/2022.
//

#ifndef HASH_STRING_NO_H
#define HASH_STRING_NO_H

#include "string"
using namespace std;

class No {
private:
    string info;
    No * prox;

public:
    void setInfo(string chave);
    void setProx(No * novoNo);
    string getInfo();
    No * getProx();
};


#endif //HASH_STRING_NO_H
