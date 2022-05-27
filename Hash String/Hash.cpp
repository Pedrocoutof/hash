//
// Created by pedro on 25/05/2022.
//

#include <cstring>
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

bool Hash::posicaoVazia(int index){
    return this->tabela[index].getInicio() == nullptr;
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

    return funcaoHashPorMultiplicacao(aux);
}

void Hash::insere(string chave, string metodo){

    /*
    if(metodo.compare("multiplicacao")){
        this->tabela[funcaoHashPorMultiplicacaoParaString(chave)].insere(chave);
    }
     */

    //Utilizando como padrao o metodo da divisao
    this->tabela[funcaoHashPorDivisaoParaString(chave)].insere(chave);

}

bool Hash::busca(string chave){
    int indexBase = funcaoHashPorDivisaoParaString(chave);
    int indexSoma = indexBase;

    if(posicaoVazia(indexBase)){
        return false;
    }

    for(int tentativas = 0; ; tentativas++){
        indexSoma += tentativas;
        indexBase = funcaoHashPorDivisao(indexSoma);

        if(strcmp(chave.c_str(), this->tabela[indexBase].getInicio()->getInfo().c_str()) == 0){
            cout << endl << "========================" << endl;
            cout << "Chave encontrada !" << endl;
            cout << chave << " == " << this->tabela[indexBase].getInicio()->getInfo() << endl;
            cout << "========================" << endl;
            return true;
        }
/*
        cout << endl << "Tentativas : " << tentativas << endl;
        cout << chave << " == " << this->tabela[indexBase].getInicio()->getInfo() << endl;

*/
    }
    return false;
}

void Hash::imprime() {
    cout << endl << "=== Imprimindo Lista ===" << endl;
    for(int i = 0; i < this->tam; i++){
        cout << "[" << i << "] - ";
        this->tabela[i].imprime();
        cout << "\t Numero de repeticoes: [" << tabela[i].getTam() + 1 << "]";
        cout << endl;
    }

    cout << endl << "========================" << endl;
}


void Hash::insereTeste(string chave, string metodo) {
    int indexBase = funcaoHashPorDivisaoParaString(chave);
    int indexSoma = indexBase;

        for(int tentativas = 0 ; ; tentativas++){
            indexSoma += tentativas;

            if(posicaoVazia(indexSoma)){
                this->tabela[indexSoma].insere(chave);
                this->tabela[indexBase].setIndexProx(indexSoma);

                return;
            }else{
                if(strcmp(chave.c_str(), this->tabela[indexBase].getInicio()->getInfo().c_str()) == 0){
                    this->tabela[indexBase].incrementaTam();
                    return;
                }
            }

            tabela[indexBase].incrementaColicoes();
    }
}