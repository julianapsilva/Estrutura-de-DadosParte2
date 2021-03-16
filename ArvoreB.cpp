#include "ArvoreB.h"
#include "hash.h"
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

ArvoreB::ArvoreB(int dMin, HashTable* h) {
    raiz = NULL;
    this->dMin = dMin;
    this->h = h;
}

void ArvoreB::insere(string data, int codCidade) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    if (raiz == NULL) {
        raiz = new NoB(dMin, h);
        raiz->setFolha(true);
        raiz->setChave(h->getIndice(data, codCidade), 0);
        raiz->setN(1);
    }

    else {

        if (raiz->getN() == 2 * dMin - 1) {
            NoB* novo = new NoB(dMin, h);
            novo->setFolha(false);
            novo->setFilho(raiz, 0);
            novo->divideFilho(raiz, 0);

            int i = 0;

            if (h->getCidade(novo->getChave(0)) < codCidade ||
                (h->getCidade(novo->getChave(0)) == codCidade && h->getData(novo->getChave(0)) < data)) {
                i++;
            }
            novo->getFilho(i)->insereComEspaco(codCidade, data);
            raiz = novo;
        }
        else
            raiz->insereComEspaco(codCidade, data);
    }
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    tempoInsercao=duration_cast<duration<double>>(fim - inicio).count();
}

void ArvoreB::imprime(std::ostream& o) {
    if (raiz != NULL) {
        raiz->imprime(o);
    }
}

int ArvoreB::busca(int codigo) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
      if (raiz == NULL)
         return 0;

      else
        return raiz->busca(codigo);

  high_resolution_clock::time_point fim = high_resolution_clock::now();
    tempoBusca=duration_cast<duration<double>>(fim - inicio).count();
}








