#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include "hash.h"
#include "ArvQ.h"

class Arquivo{
public:
    int leArqProcessado(HashTable* ht, string endr,int n);
    int leArqCord(ArvoreQ* ht, string endr, int n);
    void geraSaida();



};

#endif // ARQUIVO_H_INCLUDED
