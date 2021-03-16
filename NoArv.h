#ifndef NOARV_H_INCLUDED
#define NOARV_H_INCLUDED

class NoArv
{
  public:
    NoArv()               { };
    ~NoArv()              { };
    void setEsq(NoArv *p) { esq = p; };
    void setInfo(int val) { info = val; };
    void setDir(NoArv *p) { dir = p; };
    void setFator(int val) { fator = val; };
    NoArv* getEsq()       { return esq; };
    int getInfo()         { return info; };
    int getFator()        { return fator; };
    NoArv* getDir()       { return dir; };
  private:
    NoArv* esq; // ponteiro para o filho a esquerda
    int info;   // informação do No (int)
    int fator;  //fator de balanceamento
    NoArv* dir; // ponteiro para o filho a direita
};

#endif // NOARV_H_INCLUDED
