#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "Hash.h"
#include "Lista.h"

void testeHash(){

    Hash hash3(7);

    string arrStrings [] = {"Pe", "Pe", "Pe", "Pedr", "Pedro"};

    for(int i = 0 ; i < 5 ; i ++){
        cout << arrStrings[i];
        hash3.insereSondagemLinear(arrStrings[i]);
    }

    hash3.imprime();

    hash3.busca("Pedr");

}

string clearString(string key){
    string dest = "";

    for(int i = 0; i < key.length(); i++){
        if((key[i] >= 97 && key[i] <= 122)){
            dest+= key[i];
        }
    }

    return dest;
}

string lowerCase(string key){
    for(int i = 0; i < key.length() ; i++){
        if(isupper(key[i])){
            key[i] = tolower(key[i]);
        }
    }
    return key;
}

void testesHashComArquivo(){
    ifstream domCasmurro;

    domCasmurro.open("../DomCasmurro.txt");

    Hash hash(53413);

    string line;
    stringstream iss;
    string word;

    while(domCasmurro.peek() != EOF){
        line.clear();
        iss.clear();


        getline(domCasmurro, line );

        iss << line;

        while(getline(iss, word, ' ')){
            string strClean;
            strClean.clear();
            strClean = clearString(lowerCase(word));
            if(strClean.length() > 3)
                hash.insereDuploHash(strClean);
        }

    }
    hash.salvaTabelaHashTxt("tabela1");
    hash.imprime();
}

int main() {
    //testeHash();
    testesHashComArquivo();
    return 0;
}
