#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "NoB.h"

class ArvoreB {
private:
    NoB* raiz;
    int dMin;
    HashTable* h;
    long double tempoInsercao;
    long double tempoBusca;
    int comparacoes=0;

public:
    ArvoreB(int dMin, HashTable* h);
    void insere(string data, int codCidade);
    void imprime(std::ostream&);
    long double getTempoInsercao(){ return tempoInsercao;};
    long double getTempoBusca(){ return tempoBusca;};
    int busca(int codigo);
};


#endif // ARVOREB_H_INCLUDED
