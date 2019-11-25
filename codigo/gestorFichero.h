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
    GestorFichero(string nombreFichero);
    
    inline string nombreFichero(){
        return nombreFichero_;
    }

    inline void setNombreFichero(string nombreFichero){
        nombreFichero_ = nombreFichero;
    }

    list <Paciente> getTodosPacientes();

    list <Cita> getCitasHoy();

    void anadirPaciente(Paciente p);

    void getDatosPaciente(Paciente p);

    void anadirCitaPaciente(Paciente p);

    void anadirTratamientoPaciente(Paciente p);

    list <Cita> getCitasPaciente(Paciente p);

    Tratamiento getTratamientoPaciente(Paciente p);

    list <ElementoHistorial> getHistorialPaciente(Paciente p);

    bool buscarPaciente(Paciente p);

    void modificarTratamientoPaciente(Paciente p);

    void modificarCitaPaciente(Paciente p);

};

#endif