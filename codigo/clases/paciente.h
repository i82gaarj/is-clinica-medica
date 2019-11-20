#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include "historial.h"

class Paciente{
private:
    string DNI;
    string nombreCompleto_;
    string fechaNacimiento;
    int telefono_;
    char sexo_;
    Historial h_;
public:
    Paciente();

    bool anadir();
    bool modificar();
    bool eliminar();

    void mostrar_historial_medico();

    string getNombre();
    string getFechaNacimiento();
    char getSexo();
    int getTelefono();
    int getDNI();
};

#endif