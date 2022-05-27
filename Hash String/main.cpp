#include <iostream>
using namespace std;

#include "Hash.h"
#include "Lista.h"

string lowerCase(string str){
    for(int i = 0; i < str.length(); i++)
        if(isupper(str[i]))
            str[i] = tolower(str[i]);

    return str;
}

void testeHash(){
    /*
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
    */
    Hash hash3(7);

    string arrStrings [] = {"Pe", "Pe", "Pe", "Pedr", "Pedro"};

    for(int i = 0 ; i < 5 ; i ++){
        cout << arrStrings[i];
        hash3.insereTeste(arrStrings[i]);
    }

    hash3.imprime();

    hash3.busca("Pedr");

}

int main() {
    testeHash();
    return 0;
}
