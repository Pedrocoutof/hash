#include <iostream>
using namespace std;

#include "Hash.h"
#include "Lista.h"

void testeHash(){
    Hash hash(7);

    hash.insere("P", "multiplicacao");
    hash.insere("Pe", "multiplicacao");
    hash.insere("Ped", "multiplicacao");
    hash.insere("Pedr", "multiplicacao");
    hash.insere("Pedro", "multiplicacao");

    hash.imprime();


    Hash hash2(7);

    hash2.insere("P");
    hash2.insere("Pe");
    hash2.insere("Ped");
    hash2.insere("Pedr");
    hash2.insere("Pedro");

    hash2.imprime();

}

int main() {
    testeHash();
    return 0;
}
