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

			case 1:{

				case_anadirPaciente();

			}break;

			case 2:{

				case_eliminarPaciente();

			}break;

			case 3:{

				case_modificarPaciente();

			}break;

			case 4:{
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
						case 1:{ // mostrar historial
							list <ElementoHistorial> historial = f.getHistorialPaciente(DNI);
							for(list <ElementoHistorial>::iterator it = historial.begin(); it != historial.end(); it++){
								cout << it -> getFecha() << endl
									 << it -> getObservaciones() << endl;
							}
							cin.ignore();
							cin.get();
						}break;

						case 2:{
							/*Cita c = aux.getUltimaCita();
							cout << "PRÓXIMA CITA DE " << aux.getNombreCompleto() << ": " << endl
								 << c.getFecha() << endl
								 << c.getHora() << endl
								 << "Duración: " << c.getDuracion() << endl;
							cin.ignore();
							cin.get();*/
						}break;

						case 3:{
							// eliminar cita
						}break;

						case 4:{
							// modificar cita
						}break;

						case 5:{
							
						}break;

						case 6:{

						}break;

						case 7:{

						}break;

						case 8:{
							break;
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

			case 5:{
				
				case_anadirCita();

			}break;

			case 6:{
				cout << "Citas de hoy" << endl;
				GestorFichero f;
				list <Cita> citas = f.getCitasHoy();
				cout << "Hoy tiene las siguientes citas: " << endl;
				for(list <Cita>::iterator it = citas.begin(); it != citas.end(); it++){
					cout << "Hora: " << it -> getHora() << endl
						 << "Duración: " << it -> getDuracion() << " minutos" << endl;
				}
				cout << "Pulse ENTER para continuar...";
				cin.ignore();
				cin.get();
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
