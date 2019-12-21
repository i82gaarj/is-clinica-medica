#include <iostream>
#include <string>

#include "funciones.h"
#include "paciente.h"
#include "gestorFichero.h"

using namespace std;

int main() {

	int opcion;

	do{
		system("clear");
		mostrar_menu();
		cin >> opcion;
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
				string DNI;
				cout << "Introduzca dni: ";
				cin >> DNI;
				convertirDNIMayuscula(DNI);
				GestorFichero f;
				if (f.buscarPaciente(DNI) == true){
					Paciente aux = f.getPacienteFromDNI(DNI);
					cout << "DNI " << DNI << endl
						 << "Nombre: " << aux.getNombreCompleto() << endl
						 << "Sexo: " << aux.getSexo() << endl
						 << "Fecha Nacimiento: " << aux.getFechaNacimiento() << endl
						 << "Teléfono: " << aux.getTelefono() << endl
						 << "Dirección: " << aux.getDireccion() << endl;

					int opcion2;
					mostrar_menu_paciente(aux);
					cin >> opcion2;
					switch(opcion2){
						case 1:{ // Mostrar historial
							list <ElementoHistorial> historial = f.getHistorialPaciente(DNI);
							for(list <ElementoHistorial>::iterator it = historial.begin(); it != historial.end(); it++){
								cout << it -> getFecha() << endl
									 << it -> getObservaciones() << endl;
							}
							cin.ignore();
							cin.get();
						}break;

						case 2:{
							list <Cita> citas = f.getProximasCitasPaciente(DNI);
							cout << "PRÓXIMAS CITAS DE " << aux.getNombreCompleto() << ": " << endl;
							for(Cita &c : citas){
								cout << c.getFecha() << " a las " << c.getHora() << endl
									 << "Duración: " << c.getDuracion() << " minutos" << endl;
							}
							cin.ignore();
							cin.get();
						}break;

						case 3:{ // Eliminar cita
							
						}break;

						case 4:{ // Modificar cita
							
						}break;

						case 5:{ // Añadir historial médico
							
						}break;

						case 6:{ // Iniciar tratamiento

						}break;

						case 7:{ // Volver atrás

						}break;

						default:{
							cout << "Opcion no válida. Presione ENTER para continuar...";
							cin.ignore();
							cin.get();
						}break;
					}
				}
				else{
					cout << "Paciente con DNI " << DNI << " no existe" << endl;
					cin.ignore();
					cin.get();
				}
			}break;

			case 5:{ // Añadir una cita a un paciente
				
				case_anadirCita();

			}break;

			case 6:{ // Mostrar las citas de hoy
				
				case_citasHoy();
				
			}break;

			case 7:{

				return 0;

			}break;
			
			default:{
				cout << "Opcion no valida" << endl;
			}break;
		}
	}while(opcion != 7);
}
