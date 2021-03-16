#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include "ArvQ.h"
#include "hash.h"
#include "Arquivo.h"
#include <sstream>
#include <stdlib.h>
#include "ArvoreB.h"
using namespace std;


int Arquivo::leArqProcessado(HashTable* ht, string endr,int n)
{   cout<< "iniciando a leitura do arquivo processado" << endl;
    std::ifstream arq(endr);
    if(!arq.is_open())
        return -1;
    string str;
    int i=0;
    getline(arq, str);
    while(getline(arq,str))
    {

      char *subdado;
      subdado = strtok( &str[0], ",");
      string data=subdado;
      subdado = strtok( NULL, ",");
      string estado= subdado;
      subdado = strtok( NULL, ",");
      string cidade= subdado;
      subdado = strtok( NULL, ",");
      int cod= atoi(subdado);
      subdado = strtok( NULL, ",");
      int casos= atoi(subdado);
      subdado = strtok( NULL, ",");
      int  mortes= atoi(subdado);
      ht->insere(cod,data,cidade,estado,casos,mortes);
        if(i++>n && n!=-1)
            break;
    }
    return 0;
cout<< "leitura concluida" << endl;
}
int Arquivo::leArqCord(ArvoreQ* ht, string endr, int n) {
    cout<< "iniciando a leitura do arquivo coordenadas" << endl;
    std::ifstream arq(endr);
    if (!arq.is_open())
        return -1;
    string str;
    int i = 0;
    getline(arq, str);

    while (getline(arq, str))
    {

        char* subdado;
        subdado = strtok(&str[0], ",");
        int estado = atoi(subdado);
        subdado = strtok(NULL, ",");
        int cidade = atoi(subdado)/10;
        subdado = strtok(NULL, ",");
        string nome = subdado;
        subdado = strtok(NULL, ",");
        double x = atof(subdado);
        subdado = strtok(NULL, ",");
        double  y = atof(subdado);
        subdado = strtok(NULL, ",");
        int  cap = atoi(subdado);
        ht->insere(estado,  cidade,nome, x,y,cap);
        if (i++ > n && n != -1)
            break;
    }
    return 0;
cout<< "leitura concluida" << endl;
}
