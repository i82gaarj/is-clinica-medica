#ifndef GESTORFICHERO_H
#define GESTORFICHERO_H
#include <string>
#include <list>
#include "cita.h"
#include "paciente.h"

using namespace std;

class GestorFichero{
private:
    string nombreFichero_;

public:
    GestorFichero(string nombreFichero = "pacientes.txt");
    
    inline string getNombreFichero(){
        return nombreFichero_;
    }

    inline void setNombreFichero(string nombreFichero){
        nombreFichero_ = nombreFichero;
    }

    list <Paciente> getTodosPacientes();

    list <Cita> getCitasHoy();

    void anadirPaciente(Paciente p);

    Paciente getPacienteFromDNI(string DNI);

    void anadirCitaPaciente(Paciente p);

    void anadirTratamientoPaciente(Paciente p);

    list <Cita> getCitasPaciente(Paciente p);

    Tratamiento getTratamientoPaciente(Paciente p);

    list <ElementoHistorial> getHistorialPaciente(Paciente p);

    bool buscarPaciente(string nombreCompleto);

    void modificarTratamientoPaciente(Paciente p);

    void modificarCitaPaciente(Paciente p);

    Cita getUltimaCitaPaciente(string DNI);

    bool eliminarPaciente(string DNI);

    bool eliminarCita(Paciente p, Cita c);

};

#endif