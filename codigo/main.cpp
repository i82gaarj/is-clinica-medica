#include <iostream>

#include "funciones.h"

using namespace std;

int main() {

	int opcion;

	do{
		system("clear");
		cin.clear();
		mostrar_menu();
		cin >> opcion;
		cin.clear();
		switch(opcion) {

			case 1:{ // Añadir paciente

				case_anadirPaciente();

			}break;

			case 2:{ // Eliminar paciente

				case_eliminarPaciente();

			}break;

			case 3:{ // Modificar paciente

				case_modificarPaciente();

			}break;

			case 4:{ // Buscar paciente, incluye submenú
				
				case_buscarPaciente();

			}break;

			case 5:{ // Añadir una cita a un paciente
				
				case_anadirCita();

			}break;

			case 6:{ // Mostrar las citas de hoy
				
				case_citasHoy();
				
			}break;

			case 7:{ // Mostrar lista de pacientes

				case_mostrarListaPacientes();

			}break;

			case 8:{ // Salir

				break;

			}break;

			default:{

				cout << "Opción no valida" << endl;

			}break;
		}
	}while(opcion != 8);
}
