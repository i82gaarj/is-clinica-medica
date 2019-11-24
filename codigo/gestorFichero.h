#ifndef GESTORFICHERO_H
#define GESTORFICHERO_H
#include <string>
#include <list>
#include "paciente.h"
#include "cita.h"

class GestorFichero{
private:
    string nombreFichero_;

public:
    GestorFichero();
    
    inline string nombreFichero(){
        return nombreFichero_;
    }

    inline void setNombreFichero(string nombreFichero){
        nombreFichero_ = nombreFichero;
    }

    list <Paciente> getTodosPacientes();
    list <Cita> getCitasHoy();
};

#endif