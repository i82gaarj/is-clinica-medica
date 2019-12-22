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
    
    void modificarPaciente(Paciente p_nuevo, string DNI);

    Paciente getPacienteFromDNI(string DNI);

    void anadirCitaPaciente(string DNI, Cita c);

    void anadirTratamientoPaciente(string DNI, Tratamiento t);

    list <Tratamiento> getTratamientosPaciente(string DNI);

    list <ElementoHistorial> getHistorialPaciente(string DNI);

    bool buscarPaciente(string nombreCompleto);

    void modificarTratamientoPaciente(Paciente p);

    void modificarCitaPaciente(string DNI, string fecha_antigua, string hora_antigua, Cita citaNueva);

    bool buscarCita(string fecha, string hora);

    bool buscarCita(string fecha, string hora, string DNI);
    
    list <Cita> getCitasPaciente(string DNI);

    bool eliminarPaciente(string DNI);

    bool eliminarCita(string DNI, string fecha, string hora);

    void anadirHistorialPaciente(string DNI, ElementoHistorial h);

    list <Cita> getTodasCitas();

    list <Cita> getProximasCitasPaciente(string DNI);

};

#endif
