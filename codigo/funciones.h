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

void case_citasHoy();

void case_buscarPaciente();

void case_mostrarListaPacientes();

void case_submenu_mostrarHistorial(Paciente p);

void case_submenu_mostrarCitas(Paciente p);

void case_submenu_eliminarCita(Paciente p);

void case_submenu_modificarCita(Paciente p);

void case_submenu_anadirHistorialMedico(Paciente p);

void case_submenu_anadirTratamiento(Paciente p);

void case_submenu_eliminarTratamiento(Paciente p);

void case_submenu_mostrarTratamientos(Paciente p);

void case_submenu_modificarTratamiento(Paciente p);

#endif