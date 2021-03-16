#include "NoB.h"
#include "hash.h"
#include <iostream>
using namespace std;

NoB::NoB(int dMin, HashTable* h) {
    this->dMin = dMin;
    folha = true;
    this->h = h;
    chaves = new int[2 * dMin - 1];
    this->filhos = new NoB * [2 * dMin];
    n = 0;
}

void NoB::insereComEspaco(int codCidade, string data) {
    int i = n;
    if (folha) {
        while (i > 0 && (h->getCidade(chaves[i - 1]) > codCidade ||
            (h->getCidade(chaves[i - 1]) == codCidade && h->getData(chaves[i - 1]) > data))) {
            chaves[i] = chaves[i - 1];
            i--;
        }
        chaves[i] = h->getIndice(data, codCidade);
        n++;
    }
    else {
        while (i > 0 && (h->getCidade(chaves[i - 1]) > codCidade ||
            (h->getCidade(chaves[i - 1]) == codCidade && h->getData(chaves[i - 1]) > data)))
            i--;

        if (filhos[i]->n == 2 * dMin - 1) {
            divideFilho(filhos[i], i);

            if (codCidade > h->getCidade(chaves[i]) ||
                (codCidade == h->getCidade(chaves[i]) && data > h->getData(chaves[i])))
                i++;
        }

        filhos[i]->insereComEspaco(codCidade, data);
    }
}


void NoB::divideFilho(NoB* p, int i) {
    NoB* aux = new NoB(dMin, h);
    aux->setFolha(p->folha);
    aux->n = dMin - 1;

    for (int j = 0; j < dMin - 1; j++)
        aux->chaves[j] = p->chaves[j + dMin];

    if (!p->folha) {
        for (int j = 0; j < dMin; j++)
            aux->filhos[j] = p->filhos[j + dMin];
    }

    p->n = dMin - 1;
    for (int j = n; j >= i + 1; j--)
        filhos[j + 1] = filhos[j];

    filhos[i + 1] = aux;

    for (int j = n - 1; j >= i; j--)
        chaves[j + 1] = chaves[j];

    chaves[i] = p->chaves[dMin - 1];
    n++;
}

int NoB::busca(int codigo) {
    int i = 0; int casos = 0;
    while (i < n && codigo > h->getCidade(chaves[i])){
        comparacoes++;
        i++;
    }
    if (h->getCidade(chaves[i]) == codigo){
        comparacoes++;
        casos += h->getCasos(chaves[i]);
    }
    if (folha)
        return 0;

    casos = filhos[i]->busca(codigo);

    return casos;
}

void NoB::imprime(std::ostream& o) {
    int i;
    for (i = 0; i < n; i++) {
        if (!folha)
            filhos[i]->imprime(o);
        o << "codCidade: " << h->getCidade(chaves[i]) << " data: " << h->getData(chaves[i]) << endl;
    }
    if (!folha)
        filhos[i]->imprime(o);
}

