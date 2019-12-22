#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
#include <string>

using namespace std;

class Tratamiento{
private:
    string medicamento_;
    string fechaComienzo_;
    string fechaFin_;
    string observaciones_;

public:
    Tratamiento(string medicamento, string fechaComienzo, string fechaFin, string observaciones);

    inline string getMedicamento(){
        return medicamento_;
    }

    inline string getFechaComienzo(){
        return fechaComienzo_;
    }

    inline string getFechaFin(){
        return fechaFin_;
    }

    inline string getObservaciones(){
        return observaciones_;
    }

    inline void setMedicamento(string medicamento){
        medicamento_ = medicamento;
    }

    inline void setFechaComienzo(string fecha){
        fechaComienzo_ = fecha;
    }

    inline void setFechaFin(string fecha){
        fechaFin_ = fecha;
    }

    inline void setObservaciones(string observaciones){
        observaciones_ = observaciones;
    }
};

#endif