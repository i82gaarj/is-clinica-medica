#ifndef ELEMENTOHISTORIAL_H
#define ELEMENTOHISTORIAL_H
#include <string>

class ElementoHistorial(){
private:
    string fecha_;
    string observaciones_;

public:
    inline string getFecha(){
        return fecha_;
    }
    inline string getObservaciones(){
        return observaciones_;
    }

    void setFecha();
    void setObservaciones(string observaciones);
};

#endif