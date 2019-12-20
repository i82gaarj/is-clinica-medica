#include "paciente.h"
#include "gestorFichero.h"
#include "cita.h"

using namespace std;

Paciente::Paciente(string dni, string nombreCompleto, string fechaNacimiento, int telefono, string sexo, string direccion){
    dni_ = dni;
    nombreCompleto_ = nombreCompleto;
    fechaNacimiento_ = fechaNacimiento;
    telefono_ = telefono;
    sexo_ = sexo;
    direccion_ = direccion;
}

Cita Paciente::getUltimaCita(){
    GestorFichero f;
    Cita c = f.getUltimaCitaPaciente(dni_);
    return c;
}