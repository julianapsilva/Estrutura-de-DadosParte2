#ifndef COORDENADA_H_INCLUDED
#define COORDENADA_H_INCLUDED
#include <sstream>
struct coord{
    double x=NULL;
     double y=NULL;

    bool operator ==(coord b){
    return(x==b.x&&y==b.y);
    }
    void operator =(coord b){
        x=b.x;
        y=b.y;
    }
};
typedef struct coord coord;

inline std::string doubletos(double c)
{
    std::ostringstream o;
    o << c;

    return o.str();
};

inline std::string printCoord(coord c) {
    return "La[" + doubletos(c.x) + "] Lo[" + doubletos(c.y) + "]";
}
#endif // COORDENADA_H_INCLUDED
