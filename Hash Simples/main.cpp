#include <iostream>
using namespace std;

#include "Hash.h"
#include "Lista.h"

void testeHash(){
    Hash hash(7);

    hash.insere(1);
    hash.insere(5);
    hash.insere(10);
    hash.insere(20);
    hash.insere(25);
    hash.insere(24);

    hash.imprime();
}

int main() {
    testeHash();
    return 0;
}
