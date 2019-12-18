#include <iostream>
#include <string>
#include "paciente.h"
using namespace std;

int main() {

	int opcion;
	
	cout << "Seleccione una de las siguientes opciones: " << endl;
	cout << "1. Añadir paciente." << endl;
	cout << "2. Eliminar paciente." << endl;
	cout << "3. Modificar paciente." << endl;
	cout << "4. Buscar paciente." << endl;
	cout << "5. Añadir cita." << endl;
	cout << "6. Salir" << endl;

	switch(opcion) {

		case 1:{

			string DNI;
			string nombrec;
			string fechn;
			int num;
			char sexo;
			string direc;

			cout << "Introduzca el DNI:" << endl;
			cin >> DNI;
			cout << "Introduzca el nombre completo:" << endl;
			cin >> nombrec;
			cout << "Introduzca la fecha de nacimiento:" << endl;
			cin >> fechn;
			cout << "Introduzca el número de teléfono:" << endl;
			cin >> num;
			cout << "Introduzca el sexo:" << endl;
			cin >> sexo;
			cout << "Introduzca la dirección:" << endl;
			cin >> direc;

			Paciente p(DNI, nombrec, fechn, num, sexo, direc);
			GestorFichero f;
			f.anadirPaciente(p);
		}break;

		case 2:{

			string DNI;

			cout << "Introduzca el DNI del paciente que desea eliminar:" << endl;
			cin >> DNI;

			GestorFichero f;
			f.eliminarPaciente(DNI);

		}break;

		case 3:{

			string DNI;

			cout << "Introduzca el DNI del paciente que desea eliminar:" << endl;
			cin >> DNI;

			GestorFichero f;

			if(f.buscarPaciente(DNI) == true){
				Paciente aux = f.getDatosPaciente(DNI);

				int opcion2;
				switch(opcion2) {

					string DNI2;
					string nombrecm2;
					string fechnm2;
					int tlf2;
					char sexo2;
					string direc2;

					cout << "Seleccione la opción que desea modificar:" << endl;
					cout << "1. DNI." << endl;
					cout << "2. Nombre Completo." << endl;
					cout << "3. Fecha de nacimiento." << endl;
					cout << "4. Número de teléfono." << endl;
					cout << "5. Sexo." << endl;
					cout << "6. Dirección." << endl;

					case 1:

						cout << "Introduzca el DNI modificado:" << endl;
						cin >> DNI2;
						aux.setDNI(DNI2);

					break;

					case 2:

						cout << "Introduzca el nombre completo modificado:" << endl;
						cin >> nombrecm2;
						aux.setNombreCompleto(nombrecm2);

					break;

					case 3:

						cout << "Introduzca la fecha de nacimiento modificada:" << endl;
						cin >> fechnm2;
						aux.setFechaNacimiento(fechnm2);								

					break;

					case 4:

						cout << "Introduzca el número de teléfono modificado:" << endl;
						cin >> tlf2;
						aux.setTelefono(tlf2);

					break;

					case 5:

						cout << "Introduzca el sexo modificado:" << endl;
						cin >> sexo2;
						aux.setSexo(sexo2);

					break;

					case 6:

						cout << "Introduzca la dirección modificada modificada:" << endl;
						cin >> direc2;
						aux.setDireccion(direc2);

					break;

				}
			}

		}break;

		case 4:{
			string DNI;
			cout << "Introduzca dni";
			cin >> DNI;
			GestorFichero f;
			if (f.buscarPaciente(DNI3) == true){
				Paciente aux = f.getDatosPaciente(DNI);
				cout << "aqui los datos" << endl;

				int opcion2;

				switch(opcion2){
					cin >> opcion2;
					cout << "Seleccione: " << endl 
						 << "1. Mostrar el historial de" << DNI << endl
						 << "2. Mostrar citas de " << DNI << endl
						 << "3. Cancelar cita asignada" << endl
						 << "4. Modificar cita asignada" << endl;
					case 1:{ // mostrar historial

					}break;
					case 2:{
						// mostrar cita de paciente
					}break;
					case 3;{
						// eliminar cita
					}break;
				}
			}
		}break;

		case 5:{
			cout << "Introduzca el DNI del paciente al que quiere añadir la cita" <<endl;
			string DNI3;
			cin >> DNI3;

			GestorFichero f;
			
			if(f.buscarPaciente(DNI3)==true){

				//añadir cita
			}
			else{

				cout << "el DNI introducido no se corresponde a ningun paciente"<<endl;
			}
		}break;

		case 6:{

			exit();

		}break;

		default:{

		}break;
	}

}
