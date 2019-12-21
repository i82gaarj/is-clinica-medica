#include "funciones.h"
#include "paciente.h"
#include "gestorFichero.h"
#include "cita.h"

#include <string>
#include <cctype>
#include <iostream>

using namespace std;

// Convierte las letras del DNI a mayúscula
void convertirDNIMayuscula(string &dni){
    for (int i = 0; i < dni.length(); i++){
        dni[i] = toupper(dni[i]);
    }
}

// Validación NIF y NIE
bool validarDNI(string DNI){
    if (DNI.length() != 9){
        return false;
    }
    convertirDNIMayuscula(DNI);
    // Para el NIE
    if (DNI[0] == 'X'){
        DNI[0] = '0';
    }
    else if(DNI[0] == 'Y'){
        DNI[0] = '1';
    }
    else if(DNI[0] == 'Z'){
        DNI[0] = '2';
    }

    // Comprobar que los 8 primeros caracteres son numeros
    for (int i = 0; i < (DNI.length() - 1); i++){
        if (!isdigit(DNI[i])){
            return false;
        }
    }

    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    
    char letra = letras[stoi(DNI.substr(0,8)) % 23]; 
    if (DNI[8] != letra) {
        return false;
    }
    else{
        return true;
    }
}

// Validación número de teléfono
bool validarTelefono(string telefono){
    if (telefono.length() != 9){
        return false;
    }
    else{
        return true;
    }
}

void mostrar_menu(){
	cout << "Seleccione una de las siguientes opciones: " << endl
		 << "1. Añadir paciente." << endl
		 << "2. Eliminar paciente." << endl
		 << "3. Modificar paciente." << endl
		 << "4. Buscar paciente (submenu)." << endl
		 << "5. Añadir cita." << endl
		 << "6. Mostrar citas de hoy." << endl
		 << "7. Salir" << endl;
}

void mostrar_menu_paciente(Paciente p){
	cout << endl << "SELECCIONE: " << endl 
		 << "1. Mostrar el historial de " << p.getNombreCompleto() << endl
		 << "2. Mostrar citas de " << p.getNombreCompleto() << endl
		 << "3. Cancelar cita asignada" << endl
		 << "4. Modificar cita asignada" << endl
		 << "5. Añadir historial médico a " << p.getNombreCompleto() << endl
		 << "6. Asignar tratamiento a " << p.getNombreCompleto() << endl
		 << "7. Volver atrás" << endl;
}

void mostrar_menu_modificar(){
    cout << "Seleccione la opción que desea modificar:" << endl
         << "1. DNI." << endl
		 << "2. Nombre completo." << endl
		 << "3. Fecha de nacimiento." << endl
		 << "4. Número de teléfono." << endl
		 << "5. Sexo." << endl
		 << "6. Dirección." << endl;
}

void case_anadirPaciente(){
    string DNI, nombreCompleto, fechaNacimiento, telefono, sexo, direccion;

    GestorFichero f;

    cout << "Introduzca el DNI, debe tener 8 numeros y una letra." << endl
            << "Si es un NIE debe tener una letra, 7 numeros y otra letra." << endl;
    cin >> DNI;
    if (!validarDNI(DNI)){
        cout << "DNI no válido. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        return;
    }
    convertirDNIMayuscula(DNI);

    if (f.buscarPaciente(DNI)){
        cout << "El paciente ya existe. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Introduzca el nombre completo:" << endl;
    cin.ignore();
    getline(cin, nombreCompleto);

    cout << "Introduzca la fecha de nacimiento:" << endl;
    cin >> fechaNacimiento;

    cout << "Introduzca el número de teléfono:" << endl;
    cin >> telefono;

    if(!validarTelefono(telefono)){
        cout << "Número de teléfono no válido. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Introduzca el sexo:" << endl;
    cin >> sexo;

    cout << "Introduzca la dirección y localidad:" << endl;
    cin.ignore();
    getline(cin, direccion);

    Paciente p(DNI, nombreCompleto, fechaNacimiento, stoi(telefono), sexo, direccion);
    
    f.anadirPaciente(p);
}

void case_eliminarPaciente(){
    string DNI;

    cout << "Introduzca el DNI del paciente que desea eliminar:" << endl;
    cin >> DNI;

    GestorFichero f("pacientes.txt");
    f.eliminarPaciente(DNI);
}

void case_modificarPaciente(){
    string DNI;

    cout << "Introduzca el DNI del paciente que desea modificar:" << endl;
    cin >> DNI;
    convertirDNIMayuscula(DNI);
    GestorFichero f;

    if(f.buscarPaciente(DNI) == true){
        Paciente aux = f.getPacienteFromDNI(DNI);

        mostrar_menu_modificar();
        int opcion_modificar;
        cin >> opcion_modificar;

        switch(opcion_modificar) {
            case 1:{

                string DNI_modificar;
                cout << "Introduzca el DNI modificado:" << endl;
                cin >> DNI_modificar;
                aux.setDNI(DNI_modificar);

            }break;

            case 2:{

                string nombreCompleto_modificar;
                cout << "Introduzca el nombre completo modificado:" << endl;
                cin >> nombreCompleto_modificar;
                aux.setNombreCompleto(nombreCompleto_modificar);

            }break;

            case 3:{

                string fechaNacimiento_modificar;
                cout << "Introduzca la fecha de nacimiento modificada:" << endl;
                cin >> fechaNacimiento_modificar;
                aux.setFechaNacimiento(fechaNacimiento_modificar);								

            }break;

            case 4:{

                string telefono_modificar;
                cout << "Introduzca el número de teléfono modificado:" << endl;
                cin >> telefono_modificar;
                if (validarTelefono(telefono_modificar)){
                    aux.setTelefono(stoi(telefono_modificar));
                }
                else{
                    break;
                }

            }break;

            case 5:{
                
                string sexo_modificar;
                cout << "Introduzca el sexo modificado:" << endl;
                cin >> sexo_modificar;
                aux.setSexo(sexo_modificar);

            }break;

            case 6:{

                string direccion_modificar;
                cout << "Introduzca la dirección modificada:" << endl;
                cin >> direccion_modificar;
                aux.setDireccion(direccion_modificar);

            }break;
        }
        f.modificarPaciente(aux, DNI);
    }
}

void case_anadirCita(){
    cout << "Introduzca el DNI del paciente al que quiere añadir la cita" << endl;
    string DNI;
    cin >> DNI;
    convertirDNIMayuscula(DNI);
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
}

void case_citasHoy(){
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
}