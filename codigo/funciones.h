#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "paciente.h"

#include <string>

using namespace std;

void convertirDNIMayuscula(string &dni);

bool validarDNI(string DNI);

bool validarTelefono(string telefono);

void mostrar_menu();

void mostrar_menu_paciente(Paciente p);

void mostrar_menu_modificar();

void case_anadirPaciente();

void case_eliminarPaciente();

void case_modificarPaciente();

void case_anadirCita();

#endif