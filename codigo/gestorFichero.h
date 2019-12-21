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
    
    void modificarPaciente(Paciente p);

    Paciente getPacienteFromDNI(string DNI);

    void anadirCitaPaciente(string DNI, Cita c);

    void anadirTratamientoPaciente(Paciente p);

    Tratamiento getTratamientoPaciente(Paciente p);

    list <ElementoHistorial> getHistorialPaciente(string DNI);

    bool buscarPaciente(string nombreCompleto);

    void modificarTratamientoPaciente(Paciente p);

    void modificarCitaPaciente(Paciente p);

    Cita getUltimaCitaPaciente(string DNI);

    bool eliminarPaciente(string DNI);

    bool eliminarCita(Paciente p, Cita c);

    void anadirHistorialPaciente(string DNI, ElementoHistorial h);

    list <Cita> getTodasCitas();
};

#endif