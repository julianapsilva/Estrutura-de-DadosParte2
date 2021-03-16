#ifndef NOQARV_H_INCLUDED
#define NOQARV_H_INCLUDED
#include "Coordenada.h"
#include <string>

class NoQArv
{
private:
    int codC, codE, C;
    int info;
    std::string nome;
    coord coordenadas;
    int fator;
    NoQArv* ne = NULL, * se = NULL, * nw = NULL, * sw = NULL;

  public:
      coord getCoord() { return coordenadas; };
      void setCoord(coord val) { coordenadas = val; };
      std::string toString() { return "" + nome + "  "+ std::to_string(codC); }
    void setNe(NoQArv *p) { ne = p; };
    void setSe(NoQArv *p) { se = p; };
    void setSw(NoQArv *p) { sw = p; };
    void setNw(NoQArv *p) { nw = p; };
    NoQArv(int estado,int cidade, std::string ncidade,int x,int y,int C) {
        this->codE = estado; this->codC = cidade; this-> nome= ncidade; this->coordenadas.x = x; this->coordenadas.y = y; this->C = C;
    };
    NoQArv(NoQArv*n) {
        this->codE = n->codE; this->codC = n->codC; this->nome = n->nome; this->coordenadas = n->coordenadas; this->C =n->C;
    };
    ~NoQArv() {};
    NoQArv* getNe()       { return ne; };
    NoQArv* getSe()       { return se; };
    NoQArv* getSw()       { return sw; };
    NoQArv* getNw()       { return nw; };
    void setFator(int val) { fator = val; };
    int getFator()        { return fator; };
    int getX() { return coordenadas.x ; };
    void setX(int p) { coordenadas.x = p; };
    int getY() { return coordenadas.y; };
    void setY(int p) { coordenadas.y = p; };
    int getCodC() { return codC; };
    void setCodC(int p) { codC = p; };
    int getCodE() { return codE; };
    void setCodE(int p) { codE = p; };
    int getC() { return C; };
    void setC(int p) { C = p; };
    std::string getNome(){return nome; };
    void setCodC(std::string p) { nome = p; };


};


#endif // NOQARV_H_INCLUDED
