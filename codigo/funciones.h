#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "paciente.h"

#include <string>

using namespace std;

bool validarFecha(const string &str);

bool validarHora(const string &str);

bool validarDuracion(const string &str);

int strGetHora(const string &str);

int strGetMinutos(const string &str);

void convertirDNIMayuscula(string &dni);

bool validarDNI(string DNI);

bool validarTelefono(string telefono);

void mostrar_menu();

void mostrar_menu_paciente(Paciente p);

void mostrar_menu_modificar();

void case_anadirPaciente(); // CASO DE USO 1

void case_eliminarPaciente(); // CASO DE USO 2

void case_modificarPaciente(); // CASO DE USO 7

void case_anadirCita(); // CASO DE USO 9

void case_citasHoy(); // CASO DE USO 13

void case_buscarPaciente(); // CASO DE USO 4

void case_mostrarListaPacientes(); // CASO DE USO 3

void case_submenu_mostrarHistorial(Paciente p); // CASO DE USO 5

void case_submenu_mostrarCitas(Paciente p); // CASO DE USO 8

void case_submenu_eliminarCita(Paciente p); // CASO DE USO 10

void case_submenu_modificarCita(Paciente p); // CASO DE USO 12

void case_submenu_anadirHistorialMedico(Paciente p); // CASO DE USO 14

void case_submenu_anadirTratamiento(Paciente p); // CASO DE USO 11

void case_submenu_eliminarTratamiento(Paciente p); // CASO DE USO 16

void case_submenu_mostrarTratamientos(Paciente p); // CASO DE USO 15

void case_submenu_modificarTratamiento(Paciente p); // CASO DE USO 6

bool validarCita(const Cita &c1, const Cita &c2);

#endif