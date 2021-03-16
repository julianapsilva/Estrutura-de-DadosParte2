#ifndef NODEHT_H_INCLUDED
#define NODEHT_H_INCLUDED
#include <string>
typedef std::string string;

class NodeHT{
public :
    string data;
    int codcidade;
    string cidade,estado;
    int mortes,casos;

    NodeHT(int codcidade,string data,string cidade,string estado,int casos,int mortes){
        this->data = data;
        this->cidade=cidade;
        this->codcidade=codcidade;
        this->mortes=mortes;
        this->casos=casos;
        this->estado = estado;
    }
    string toString(){return  cidade;};
    bool equals(string dt,int cod){
        if(data==dt && codcidade==cod)
                return true;
        return false;
    }
};


#endif // NODEHT_H_INCLUDED
