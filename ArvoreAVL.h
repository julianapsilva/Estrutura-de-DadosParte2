#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED
#include "NoArv.h"
#include "hash.h"

class ArvoreAVL
{
public:
    ArvoreAVL(HashTable *t);
    int busca(int val);
    void insere(string data, int codCidade);
    void imprime(std::ostream&);
    int calculaAltura(NoArv *p);
    long double getTempoInsercao(){ return tempoInsercao;};
    double getTempoBusca(){ return tempoBusca;};
    int getComparacoes(){ return comparacoes;};

private:
    HashTable* h;
    long double tempoInsercao;
    double tempoBusca;
    int comparacoes=0;
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* raiz; // ponteiro para o No raiz da árvore
    int auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, string data, int codCidade);
    void imprimePorNivel(NoArv* p, int nivel,std::ostream&);
    NoArv* rotSimplesEsq(NoArv* p);
    NoArv* rotSimplesDir(NoArv* p);
    NoArv* verificaBalanceamento(NoArv *p);
};

#endif // ARVOREAVL_H_INCLUDED
