#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED
#include "hash.h"

class NoB {
private:
    HashTable* h;
    int* chaves;
    bool folha;
    int dMin;
    NoB** filhos;
    int n;
    int comparacoes=0;

public:

    NoB(int dMin, HashTable* h);
    void insereComEspaco(int codCidade, string data);
    void divideFilho(NoB* p, int i);
    void imprime(std::ostream&);
    int busca(int codigo);
    int getComparacoes(){return comparacoes;};

    NoB* getFilho(int i) { return filhos[i]; }
    void setFilho(NoB* val, int i) { filhos[i] = val; }

    int getN() { return n; }
    void setN(int val) { n = val; }

    bool eFolha() { return folha; }
    void setFolha(bool val) { folha = val; }

    int getChave(int i) { return chaves[i]; }
    void setChave(int val, int i) { chaves[i] = val; }

};



#endif // NOB_H_INCLUDED
