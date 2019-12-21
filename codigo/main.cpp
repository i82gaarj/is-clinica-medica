#include <iostream>
#include <string>
#include "paciente.h"
#include "gestorFichero.h"

using namespace std;

void mostrar_menu(){
	cout << "Seleccione una de las siguientes opciones: " << endl
		 << "1. Añadir paciente." << endl
		 << "2. Eliminar paciente." << endl
		 << "3. Modificar paciente." << endl
		 << "4. Buscar paciente." << endl
		 << "5. Añadir cita." << endl
		 << "6. Mostrar citas de hoy." << endl
		 << "7. Salir" << endl;
}

int main() {

	int opcion;

	do{
		system("clear");
		mostrar_menu();
		cin >> opcion;
		switch(opcion) {

			case 1:{

				string DNI;
				string nombrec;
				string fechn;
				int num;
				string sexo;
				string direc;

				GestorFichero f;

				cout << "Introduzca el DNI:" << endl;
				cin >> DNI;
				if (f.buscarPaciente(DNI)){
					cout << "El paciente ya existe. Presione una tecla para continuar" << endl;
					cin.ignore();
					cin.get();
					break;
				}
				cout << "Introduzca el nombre completo:" << endl;
				cin.ignore();
				getline(cin, nombrec);
				cout << "Introduzca la fecha de nacimiento:" << endl;
				cin >> fechn;
				cout << "Introduzca el número de teléfono:" << endl;
				cin >> num;
				cout << "Introduzca el sexo:" << endl;
				cin >> sexo;
				cout << "Introduzca la dirección y localidad:" << endl;
				cin.ignore();
				getline(cin, direc);

				Paciente p(DNI, nombrec, fechn, num, sexo, direc);
				
				f.anadirPaciente(p);
			}break;

			case 2:{

				string DNI;

				cout << "Introduzca el DNI del paciente que desea eliminar:" << endl;
				cin >> DNI;

				GestorFichero f("pacientes.txt");
				f.eliminarPaciente(DNI);

			}break;

			case 3:{

				string DNI;

				cout << "Introduzca el DNI del paciente que desea modificar:" << endl;
				cin >> DNI;

				GestorFichero f;

				if(f.buscarPaciente(DNI) == true){
					Paciente aux = f.getPacienteFromDNI(DNI);

					int opcion2;
					string DNI2;
					string nombrecm2;
					string fechnm2;
					int tlf2;
					char sexo2;
					string direc2;

					cout << "Seleccione la opción que desea modificar:" << endl;
					cout << "1. DNI." << endl;
					cout << "2. Nombre completo." << endl;
					cout << "3. Fecha de nacimiento." << endl;
					cout << "4. Número de teléfono." << endl;
					cout << "5. Sexo." << endl;
					cout << "6. Dirección." << endl;

					cin >> opcion2;

					switch(opcion2) {
						case 1:{

							cout << "Introduzca el DNI modificado:" << endl;
							cin >> DNI2;
							aux.setDNI(DNI2);

						}break;

						case 2:{

							cout << "Introduzca el nombre completo modificado:" << endl;
							cin >> nombrecm2;
							aux.setNombreCompleto(nombrecm2);

						}break;

						case 3:{

							cout << "Introduzca la fecha de nacimiento modificada:" << endl;
							cin >> fechnm2;
							aux.setFechaNacimiento(fechnm2);								

						}break;

						case 4:{

							cout << "Introduzca el número de teléfono modificado:" << endl;
							cin >> tlf2;
							aux.setTelefono(tlf2);

						}break;

						case 5:{

							cout << "Introduzca el sexo modificado:" << endl;
							cin >> sexo2;
							aux.setSexo(sexo2);

						}break;

						case 6:{

							cout << "Introduzca la dirección modificada modificada:" << endl;
							cin >> direc2;
							aux.setDireccion(direc2);

						}break;
					}
				}

			}break;

			case 4:{
				string DNI;
				cout << "Introduzca dni: ";
				cin >> DNI;
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
					cout << endl << "SELECCIONE: " << endl 
						 << "1. Mostrar el historial de " << aux.getNombreCompleto() << endl
						 << "2. Mostrar próxima cita de " << aux.getNombreCompleto() << endl
						 << "3. Cancelar cita asignada" << endl
						 << "4. Modificar cita asignada" << endl;
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
							Cita c = aux.getUltimaCita();
							cout << "PRÓXIMA CITA DE " << aux.getNombreCompleto() << ": " << endl
								 << c.getFecha() << endl
								 << c.getHora() << endl
								 << "Duración: " << c.getDuracion() << endl;
							cin.ignore();
							cin.get();
						}break;
						case 3:{
							// eliminar cita
						}break;
						case 4:{
							// modificar cita
						}
						case 5:{
							break;
						}
						default:{
							cout << "Opcion no válida";
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
				cout << "Introduzca el DNI del paciente al que quiere añadir la cita" << endl;
				string DNI;
				cin >> DNI;

				GestorFichero f;
				
				if(f.buscarPaciente(DNI) == true){
					string fecha, hora, duracion;
					//int duracion;

					cout << "Introduce la fecha: (FORMATO DD/MM/AAAA)" << endl;
					cin >> fecha;

					cout << "Introduce la hora: (FORMATO HH:MM)" << endl;
					cin >> hora;

					cout << "Introduce la duración en minutos" << endl;
					cin >> duracion;

					Cita c(fecha, hora, atoi(duracion.c_str()));
					f.anadirCitaPaciente(DNI, c);
					
				}
				else{
					cout << "El DNI introducido no se corresponde a ningun paciente" << endl;
				}
			}break;

			case 6:{
				cout << "Citas de hoy" << endl;
				GestorFichero f;
				list <Cita> citas = f.getCitasHoy();
				for(list <Cita>::iterator it = citas.begin(); it != citas.end(); it++){
					cout << it -> getFecha() << endl
						 << it -> getHora() << endl
						 << it -> getDuracion() << endl;
				}
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
