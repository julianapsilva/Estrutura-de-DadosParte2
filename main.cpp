#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include "ArvQ.h"
#include "hash.h"
#include <sstream>
#include <stdlib.h>
#include "ArvoreAVL.h"
#include "ArvoreB.h"
#include <time.h>
#include "Arquivo.h"
#include <random>
#include<queue>
using namespace std;
int numeroInsert=0;
double tb2=0;
double tba=0;
double tb1=0;

int random(int min, int max) {
   /* std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distribution(min, max);*/

    //generating a random integer:
//   int x = distribution(gen);

 // se for rodar no codeblocks trocar parte comentada

     unsigned long x;
    x = rand();
    x <<= 15;
    x ^= rand();
    x %= max;

   return x;

    }

NodeHT* getRandomValue(HashTable* ht){

    int i = 0, max = ht->getTam();
    do{
         i = random(0, max);

    } while(ht->operator[](i)==NULL);

    NodeHT* n= ht->operator[](i);
    return n;
}


void teste(int n, int op, HashTable* dados, ArvoreQ* loc) {

    ofstream filestream("saidaDeTestes.txt");
    switch (op) {
    case 1: {
        HashTable h(n + n / 10);

        for (int i = 0; i < n; i++) {

            NodeHT* m = (getRandomValue(dados));
            h.insere(m);
        }
        h.print((n < 20) ? cout : filestream);
        break;
    }

    case 2: {
        ArvoreAVL arv(dados);
        for (int i = 0; i < n; i++) {

            NodeHT* m = getRandomValue(dados);
            arv.insere(m->data, m->codcidade);
        }
        arv.imprime((n < 20) ? cout : filestream);

        break;
    }

    case 3: {
        ArvoreQ arv;
        for (int i = 0; i < n; i++) {

            NodeHT* m;
            NoQArv* na;
            do {
                m = (getRandomValue(dados));
                na = loc->busca(m->codcidade);
            } while (arv.busca(m->codcidade) != NULL || na == nullptr);


            arv.insere(na);
        }

        arv.imprime((n < 20) ? cout : filestream);

        break;
    }


    case 4: {
        ArvoreB arv(4, dados);

        for (int i = 0; i < n; i++) {

            NodeHT* m = getRandomValue(dados);
            arv.insere(m->data, m->codcidade);
        }
        arv.imprime((n < 20) ? cout : filestream);

        break;
    }
    }
}

void s1(ArvoreB *ab,ArvoreAVL*avl,  int cod) {

   // int aux = ab->busca(cod);
    //cout << endl << "ARVORE B(20) FEZ " << " COMPARACORES COM RESULTADO =" <<aux<< endl;
    int aux= avl->busca(cod);
    cout<< "ARVORE AVL REALIZOU " << avl->getComparacoes() << " COMPARACOES E RETORNOU UM TOTAL DE " << aux<< " CASOS"<< endl;
    cout << endl << "BUSCA S1 CONCLUIDA" << endl;

}
void printLista(queue<NoQArv> n) {

    while (!n.empty())
    {
        cout << n.front().toString()<<endl;
        n.pop();

    }
}

void s2(ArvoreQ *Q,ArvoreB *ab,ArvoreAVL* avl, double x0,double x1,double y0,double y1) {

    queue<NoQArv> lista;
    lista = Q->listaZona(coord{ x0,y0 }, coord{ x1,y1 });
   /* int count=0;
    while (!lista.empty())
    {
        count += ab->busca(lista.front().getCodC());
        lista.pop();

    }*/

    int count = 0; int resultado=0;
    lista= Q->listaZona(coord{ x0,y0 }, coord{ x1,y1 });
    double tempo=0;
    while (!lista.empty())
    {
        count += avl->busca(lista.front().getCodC());
        lista.pop();
        tempo += avl->getTempoBusca();

    }
    cout << endl << "ARVORE AVL RESULTADO =" << count << endl<<" Tempo:"<<tempo;

    cout << endl << "BUSCA S2 CONCLUIDA" << endl;

}


void insere(ArvoreB* bMaior, ArvoreB* ab, ArvoreAVL* av,int n,HashTable *h) {

    ofstream filestream("saidaDeResult.txt");
    numeroInsert++;
    NodeHT* m = NULL;  long double tempo=0;
    cout<< "inserindo na Arvore B d(20)..."<< endl;
    for (int i = 0; i < n; i++) {
        m = getRandomValue(h);
        ab->insere(m->data, m->codcidade);
        tempo+=ab->getTempoInsercao();
    }
     tb1+=tempo;

    filestream<< "TEMPO DE INSERCAO ARVORE B d(20): " << tempo << endl;
    tempo=0;
    cout<< "inserindo na Arvore B d(200)..."<< endl;
    for(int i=0;i<n;i++){
        m = getRandomValue(h);
        bMaior->insere(m->data,m->codcidade);
        tempo+=bMaior->getTempoInsercao();

    }
            tb2+=tempo;

    filestream<< "TEMPO DE INSERCAO ARVORE B d(200): " << tempo << endl;
    tempo=0;
     cout<< "inserindo na Arvore AVL..."<< endl;
    for (int i = 0; i < n; i++) {
        m = getRandomValue(h);
        av->insere(m->data, m->codcidade);
        tempo+=av->getTempoInsercao();
    }
            tba+=tempo;

    filestream<< "TEMPO DE INSERCAO ARVORE AVL: " << tempo << endl;
   filestream<< "Media apos " << numeroInsert << endl <<" Arvore B(20) =="<<tb1/numeroInsert<<" Arvore B(200) =="<<tb2/numeroInsert<<" Arvore AVL(20) =="<<tba/numeroInsert<< endl;

}


void executa(int n, HashTable* h,ArvoreQ* Q) {

    ArvoreAVL* avl=new ArvoreAVL(h); ArvoreB *bMenor=new ArvoreB(20, h); ArvoreB *bMaior= new ArvoreB(200,h);
    cout <<endl<<endl<< "EXECUTANDO MODULO PRINCIPAL"<<endl;
    int k;
    do {
        cout << endl <<"DIGITE:"<<endl<<" 1 INSERCAO "<< endl << " 2 S1  " << endl << " 3 S2 " << endl;
        cin >> k;
        switch (k) {
        case 1:
            avl = new ArvoreAVL(h);
            bMenor = new ArvoreB(20, h);
            bMaior=new ArvoreB(200,h);
            insere(bMaior,bMenor, avl, n, h);
            break;
        case 3:
            double x0, x1, y0, y1;

            cout << "DIGITE X0"<<endl;
            cin >> x0;
            cin.clear();

            cout << "DIGITE Y0"<<endl;
            cin >> y0;
            cin.clear();

            cout << "DIGITE X1"<<endl;
            cin >> x1;
            cin.clear();

            cout << "DIGITE y1"<<endl;
            cin >> y1;
            cin.clear();

            s2(Q, bMenor, avl, x0, x1, y0, y1);
            break;
        case 2:
            cout << "DIGITE O CODIGO DA CIDADE";
            int a;
            cin >> a;
            s1(bMenor, avl, a);
            break;
        }

    } while (k != -1);
}

int main(int argc, char *argv[])
{
    Arquivo arq;
    string diretorio=argv[1];
    string arq1= diretorio+="/brazil_cities_coordinates.csv";
    string arq2= diretorio+="/brazil_covid19_cities_processado.csv";*/

    HashTable* ht = new HashTable(2000069);
    ArvoreQ* Q = new ArvoreQ();

   arq.leArqProcessado(ht,arq2,1431490);
    cout<< "Leitura finalizada do arquivo pre processado " << endl;
    arq.leArqCord(Q,arq1, 5571);
    cout<< "Leitura finalizada do arquivo de coordenadas" << endl;


    int op,ed,n=0;
    do {
        cout << "1- MODULO DE TESTES" << endl << "2- ANALISE DE BUSCAS" << endl << "3- SAIR"<< endl;
        cin >> op;

        if (op == 1)
        {
            cout << "1- Hash" << endl << "2- AVL" << endl << "3- QUAD" << endl<<"4- B"<<endl<<"5-SAIR";
            cin >> ed;
            if (ed == 5)
                op = 10;

        }
        if(op==1 || op==2)
            do {
                cout << endl << "DIGITE O TAMANHO DA ENTRADA" << endl;
                cin >> n;
            } while (n <= 0);

        if (op == 2)
           executa(n, ht, Q);
        if (op == 1)
            teste(n, ed, ht, Q);

    } while (op != 3);



    return 0;
}




