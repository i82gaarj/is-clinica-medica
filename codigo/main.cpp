#include <iostream>
#include <string>
#include "paciente.h"
using namespace std:

int main() {

	int opcion;
	
	cout << "Seleccione una de las siguientes opciones: " << endl;
	cout << "1. Añadir paciente." << endl;
	cout << "2. Eliminar paciente." << endl;
	cout << "3. Modificar paciente." << endl;

	switch(opcion) {

		case 1: 

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

		break;

		case 2:

			string DNIe;

			cout << "Introduzca el DNI del paciente que desea eliminar:" << endl;
			cin >> DNIb;

			if(DNIe == DNI) {



			}

		break;

		case 3:

			string DNIm;

			cout << "Introduzca el DNI del paciente que desea eliminar:" << endl;
			cin >> DNIm;

			if(DNIm == DNI) {

				int opcion2;
				swtich(opcion2) {

					string DNIm;
					string nombrecm;
					string fechnm;
					int numm;
					char sexom;
					string direcm;

					cout << "Seleccione la opción que desea modificar:" << endl;
					cout << "1. DNI." << endl;
					cout << "2. Nombre Completo." << endl;
					cout << "3. Fecha de nacimiento." << endl;
					cout << "4. Número de teléfono." << endl;
					cout << "5. Sexo." << endl;
					cout << "6. Dirección." << endl;

					case 1;

						cout << "Introduzca el DNI modificado:" << endl;
						cin >> DNIm;
						num = numm;

					break;

					case 2;

						cout << "Introduzca el nombre completo modificado:" << endl;
						cin >> nombrecm;
						nombrec = nombrecm;

					break;

					case 3;

						cout << "Introduzca la fecha de nacimiento modificada:" << endl;
						cin >> fechnm;
						fechn = fechnm;								

					break;

					case 4;

						cout << "Introduzca el número de teléfono modificado:" << endl;
						cin >> numm;
						num = numm;

					break;

					case 5;

						cout << "Introduzca el sexo modificado:" << endl;
						cin >> sexom;
						sexo = sexom;

					break;

					case 6;

						cout << "Introduzca la dirección modificada modificada:" << endl;
						cin >> direcm;
						direc = direcm;

					break;

				}

			}	

		break;

	}

}
