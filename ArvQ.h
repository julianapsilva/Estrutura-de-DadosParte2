#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED

#include "NoQArv.h"
#ifndef COORDENADA_H_INCLUDED
#include "Coordenada.h"
#endif

#include <iostream>
#include <queue>
#include <string>
#include <ostream>

class ArvoreQ
{
public:
    ArvoreQ();
    ~ArvoreQ();
    bool vazia(); // verifica se a árvore está vazia
    NoQArv* busca(coord val);
    void imprime(std::ostream&);
    void insere(int estado, int cidade, std::string ncidade,double x, double y, int C);
    void insere(NoQArv* n);

    NoQArv* busca(int);
    std::queue<NoQArv> listaZona(coord c0, coord c1);



private:
    NoQArv* raiz; // ponteiro para o No raiz da árvore
    NoQArv* auxBusca(NoQArv* p, int );

    void auxInsere(NoQArv *val);
    void imprimePorNivel(NoQArv* p, int nivel,std::ostream&o);
    NoQArv* libera(NoQArv *p);
};

#endif // ARVBINBUSCA_H_INCLUDED
