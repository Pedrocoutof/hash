//
// Created by pedro on 25/05/2022.
//

#include <cstring>
#include <fstream>
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
    return this->tabela[index].getInicio() == nullptr ? true : false;
}

int Hash::funcaoHashPorDivisao(int chave) {
    return (chave % this->tam);
}

int Hash::funcaoHashPorMultiplicacao(int chave){
    return tam * ( fmod(chave * A, 1));
}

int Hash::duploHash(int indexBase, string chave, int tentativas){
    unsigned int auxHash2 = funcaoHashPorDivisao(indexBase);

    return  (indexBase + (tentativas * auxHash2)) % this->tam;
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

Lista * Hash::busca(string chave){
    int index = buscaRetornaIndex(chave);

    if(index != -1){

        imprimePorIndex(index);
        // TODO : CONSERTAR RETORNO DA FUNCAO BUSCA
        exit(404);
        return this->tabela;
    }

    return nullptr;

}

int Hash::buscaRetornaIndex(string chave){

    int indexBase = 0;

    // TODO VERIFICAR SE O NUMERO DE COLISOES > 0 ? TRUE : FALSE.
    for(int tentativas = 0; tentativas-1 < this->tabela[indexBase].getColisoes() ; tentativas++){

        indexBase = duploHash(funcaoHashPorDivisaoParaString(chave), chave, tentativas);

        if(!posicaoVazia(indexBase))
            if(strcmp(this->tabela[indexBase].getInicio()->getInfo().c_str(), chave.c_str()) == 0){
                return indexBase;
            }
    }
    return -1;
}

void Hash::insereSondagemLinear(string chave, string metodo) {

    for(int tentativas = 0; ; tentativas++)
    {

        int index = funcaoHashPorDivisao(funcaoHashPorDivisaoParaString(chave) + tentativas);
        if (posicaoVazia(index)) {
            this->tabela[index].insere(chave);
            return;
        }
        cout << "[ " << index << " ] - Posicao ocupada para a chave : " << chave << endl;
    }
}

void Hash::insereDuploHash(string chave, string metodo) {

    for(int tentativas = 0; ; tentativas++)
    {
        int index = duploHash(funcaoHashPorDivisaoParaString(chave), chave, tentativas);

        if (posicaoVazia(index)) {
            this->tabela[index].insere(chave);
            return;
        }else if(strcmp(chave.c_str(), tabela[index].getInicio()->getInfo().c_str()) == 0){
            tabela[index].incrementaTam();
            return;
        }
        else{
            this->tabela[index].incrementaColisoes();
        }

       // cout << "[ " << index << " ] - Posicao ocupada para a chave : " << chave << endl;
    }
}

void Hash::imprime() {
    cout << endl << "=== Imprimindo Lista ===" << endl;
    for(int i = 0; i < this->tam; i++){
        cout << "[" << i << "] - ";
        this->tabela[i].imprime();
        cout << "\t Numero de repeticoes: [" << tabela[i].getTam() + 1 << "]";
        cout << "\t Numero de colisoes: [" << tabela[i].getColisoes() << "]";
        cout << endl;
    }

    cout << endl << "========================" << endl;
}

void Hash::imprimePorIndex(int index){
    cout << endl;
    cout << "[ " << index << " ] - " << this->tabela[index].getInicio()->getInfo();
    cout << " \t- \tNumero de repeticoes: " << this->tabela[index].getTam() + 1;
    cout << " \t- \tNumero de colisoes: " << this->tabela[index].getColisoes();
    cout << endl;
}

void Hash::salvaTabelaHashTxt(string nomeArquivo){
    ofstream of_txt;

    of_txt.open("../output/" + nomeArquivo + ".txt");

    of_txt << endl << "=== Imprimindo Tabela ===" << endl;
    for(int index = 0; index < this->tam; index++){
        of_txt << "[" << index << "] - ";

        if(!posicaoVazia(index)){
            of_txt << this->tabela[index].getInicio()->getInfo();
            of_txt << "\t Numero de repeticoes: [" << tabela[index].getTam() + 1 << "]";
            of_txt << "\t Numero de colisoes: [" << tabela[index].getColisoes() << "]";
        }else{
            of_txt << "\t Posicao vazia!";
        }

        of_txt << endl;
    }

    of_txt << endl << "========================" << endl;


}

void Hash::salvaTabelaHashCSV(string nomeArquivo, bool ignoraPosicaoVazia){
    ofstream arq_csv;

    arq_csv.open("../output/" + nomeArquivo + ".csv");

    arq_csv << "index;chave;repeticoes;colisoes" << endl;

    for(int index = 0 ; index < this->tam; index++) {
        if (!posicaoVazia(index)){
            arq_csv << index << ";";
            arq_csv << this->tabela[index].getInicio()->getInfo() << ";";
            arq_csv << this->tabela[index].getTam()+1 << ";";
            arq_csv << this->tabela[index].getColisoes() << endl;
        }
        else if(!ignoraPosicaoVazia){
            arq_csv << index << ";";
            arq_csv << ";";
            arq_csv << ";";
            arq_csv << endl;
        }
    }

}