#include <iostream>
#include "ArvQ.h"
#include <queue>

using namespace std;


ArvoreQ::ArvoreQ()
{
    raiz = NULL;
}

bool ArvoreQ::vazia()
{
    return raiz == NULL;
}

void ArvoreQ::insere(int estado, int cidade, string ncidade, double x, double y, int C)
{
    NoQArv* val = new NoQArv(estado, cidade, ncidade, x, y, C);
    auxInsere(val);
}
void ArvoreQ::insere(NoQArv* n)
{
    NoQArv* val = new NoQArv(n);
    auxInsere(val);
}

void ArvoreQ::auxInsere(NoQArv* valu)
{
    NoQArv* k = raiz;

    if (raiz == NULL)
        raiz = valu;
    else
    {
        while (k != NULL)
        {
            if (k->getCoord().x < valu->getCoord().x)
                if (k->getCoord().y < valu->getCoord().y)
                    if (k->getSw() != NULL)
                        k = k->getSw();
                    else
                    {
                        k->setSw(valu);
                        break;
                    }
                else if (k->getNw() != NULL)
                    k = k->getNw();
                else
                {
                    k->setNw(valu);

                    break;
                }
            else if (k->getCoord().y < valu->getCoord().y)
                if (k->getSe() != NULL)
                    k = k->getSe();
                else
                {
                    k->setSe(valu);
                    break;
                }
            else if (k->getNe() != NULL)
                k = k->getNe();
            else
            {
                k->setNe(valu);
                break;
            }
        }
    }
}


NoQArv* ArvoreQ::busca(int codC)
{
    return auxBusca(raiz, codC);

}

NoQArv* ArvoreQ::auxBusca(NoQArv* p, int codC)
{
    if (p == NULL)
        return NULL;

    if (p->getCodC() == codC)
        return p;
    NoQArv* aux;
    aux = auxBusca(p->getSe(), codC);
    if (aux != NULL)
        return aux;
    aux = auxBusca(p->getNe(), codC);
    if (aux != NULL)
        return aux;

    aux = auxBusca(p->getSw(), codC);
    if (aux != NULL)
        return aux;

    aux = auxBusca(p->getNw(), codC);
    if (aux != NULL)
        return aux;
}
NoQArv* ArvoreQ::busca(coord val)
{

    NoQArv* k = raiz;
    while (k != NULL)
    {
        if (k->getCoord().x < val.x)
            if (k->getCoord().y < val.y)
                if (!(k->getCoord() == val))
                    k = k->getSw();
                else
                {
                    return k;

                }
            else if (!(k->getCoord() == val))
                k = k->getNw();
            else
            {
                return k;


            }
        else if (k->getCoord().y < val.y)
            if (!(k->getCoord() == val))
                k = k->getSe();
            else
            {
                return k;

            }
        else if (!(k->getCoord() == val))
            k = k->getNe();
        else
        {
            return k;
        }
        return NULL;
    }


}



void ArvoreQ::imprime(std::ostream& o)
{
    imprimePorNivel(raiz, 0, o);
}

void ArvoreQ::imprimePorNivel(NoQArv* p, int nivel, std::ostream& o)
{
    if (p != NULL)
    {
        o << "(" << nivel << ")";
        for (int i = 1; i <= nivel; i++)
            o << "--";
        o << p->toString() << endl;

        if (p->getNe() != NULL)
            o << endl << "NE";
        imprimePorNivel(p->getNe(), nivel + 1, o);
        if (p->getNw() != NULL)
            o << endl << "NW";
        imprimePorNivel(p->getNw(), nivel + 1, o);
        if (p->getSe() != NULL)
            o << endl << "SE";
        imprimePorNivel(p->getSe(), nivel + 1, o);
        if (p->getSw() != NULL)
            o << endl << "SW";
        imprimePorNivel(p->getSw(), nivel + 1, o);

    }
}

ArvoreQ::~ArvoreQ()
{
    //    raiz = libera(raiz);
}

NoQArv* ArvoreQ::libera(NoQArv* p)
{
    if (p != NULL)
    {
        p->setNe(libera(p->getNe()));
        p->setNw(libera(p->getSe()));
        p->setSw(libera(p->getSe()));
        p->setSe(libera(p->getSe()));
        delete p;
        p = NULL;
    }
    return p;
}

queue<NoQArv> ArvoreQ::listaZona(coord c0, coord c1) {
    queue<NoQArv*> fila;
    queue<NoQArv> result;
    NoQArv* p;
    fila.push(raiz);
    while (!fila.empty()) {
        p = fila.front();
        fila.pop();

        if (p == NULL){
            continue;
        }
        coord i = p->getCoord();
        if (i.x > c0.x)
        {
         if (i.y > c0.y)
             if (p->getNw() != NULL)
                fila.push(p->getSw());
         if (i.y < c1.y)
               if (p->getSw())
                   fila.push(p->getNw());
        }
        if (i.x < c1.x)
        {
            if (i.y > c0.y)
                if (p->getNe() != NULL)
                    fila.push(p->getSe());
            if (i.y < c1.y)
                if (p->getSe())
                    fila.push(p->getNe());

        }
        if (i.x > c0.x && i.x<c1.x && i.y>c0.y && i.y < c1.y)
            result.push(NoQArv(p));
    }

    return result;

}
