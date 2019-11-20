#ifndef ENTRADAHISTORIAL_H
#define ENTRADAHISTORIAL_H
#include "paciente.h"
#include <string>

class EntradaHistorial(){
private:
    string fecha_;
    string observaciones_;

public:
    string getFecha();
    string getObservaciones();

    bool setFecha();
    bool setObservaciones();
};

#endif