#include "funciones.h"
#include "paciente.h"
#include "gestorFichero.h"
#include "cita.h"
#include "tratamiento.h"

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
		 << "7. Salir" << endl
         << "8. Mostrar una lista de todos los pacientes" << endl;
}

void mostrar_menu_paciente(Paciente p){
	cout << endl << "SELECCIONE: " << endl 
		 << "1. Mostrar el historial de " << p.getNombreCompleto() << endl
		 << "2. Mostrar citas de " << p.getNombreCompleto() << endl
		 << "3. Cancelar cita asignada" << endl
		 << "4. Modificar cita asignada" << endl
		 << "5. Añadir historial médico a " << p.getNombreCompleto() << endl
		 << "6. Asignar tratamiento a " << p.getNombreCompleto() << endl
		 << "7. Volver atrás" << endl
         << "8. Mostrar tratamientos" << endl;
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
    cin.ignore();
    cout << "Introduzca el DNI, debe tener 8 numeros y una letra." << endl
         << "Si es un NIE debe tener una letra, 7 numeros y otra letra." << endl;

    getline(cin, DNI);

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
    getline(cin, nombreCompleto);

    cout << "Introduzca la fecha de nacimiento:" << endl;
    getline(cin, fechaNacimiento);

    cout << "Introduzca el número de teléfono:" << endl;
    getline(cin, telefono);

    while(!validarTelefono(telefono)){
        cout << "Número de teléfono no válido. Introdúzcalo de nuevo" << endl;
        getline(cin, telefono);
    }

    cout << "Introduzca el sexo:" << endl;
    getline(cin, sexo);

    cout << "Introduzca la dirección y localidad:" << endl;
    getline(cin, direccion);

    Paciente p(DNI, nombreCompleto, fechaNacimiento, stoi(telefono), sexo, direccion);
    
    f.anadirPaciente(p);
    cout << "Paciente añadido. Pulse ENTER para continuar..." << endl;
    cin.get();
}

void case_eliminarPaciente(){
    string DNI;

    cout << "Introduzca el DNI del paciente que desea eliminar:" << endl;
    cin >> DNI;
    GestorFichero f("pacientes.txt");
    if (f.buscarPaciente(DNI)){
        f.eliminarPaciente(DNI);

        cout << "Paciente eliminado. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
    else{
        cout << "No existe el paciente con ese DNI" << endl;
        cin.ignore();
        cin.get();
    }
    
}

void case_modificarPaciente(){
    string DNI;

    cout << "Introduzca el DNI del paciente que desea modificar:" << endl;
    cin >> DNI;
    convertirDNIMayuscula(DNI);
    GestorFichero f;

    if(f.buscarPaciente(DNI) == true){
        Paciente aux = f.getPacienteFromDNI(DNI);

        cout << "Paciente " << aux.getNombreCompleto() << endl;
        mostrar_menu_modificar();
        int opcion_modificar;
        cin >> opcion_modificar;
        cin.ignore();
        switch(opcion_modificar) {
            case 1:{

                string DNI_modificar;
                cout << "Introduzca el DNI modificado:" << endl;

                getline(cin, DNI_modificar);
                aux.setDNI(DNI_modificar);

            }break;

            case 2:{

                string nombreCompleto_modificar;
                cout << "Introduzca el nombre completo modificado:" << endl;
                getline(cin, nombreCompleto_modificar);
                aux.setNombreCompleto(nombreCompleto_modificar);

            }break;

            case 3:{

                string fechaNacimiento_modificar;
                cout << "Introduzca la fecha de nacimiento modificada:" << endl;
                getline(cin, fechaNacimiento_modificar);
                aux.setFechaNacimiento(fechaNacimiento_modificar);								

            }break;

            case 4:{

                string telefono_modificar;
                cout << "Introduzca el número de teléfono modificado:" << endl;
                getline(cin, telefono_modificar);
                if (validarTelefono(telefono_modificar)){
                    aux.setTelefono(stoi(telefono_modificar));
                }
                else{
                    cout << "Nuevo número de teléfono no válido. Operación cancelada. Pulse ENTER para continuar..." << endl;
                    cin.ignore();
                    cin.get();
                    cin.clear();
                    break;
                }

            }break;

            case 5:{
                
                string sexo_modificar;
                cout << "Introduzca el sexo modificado:" << endl;
                cin.ignore();
                getline(cin, sexo_modificar);
                aux.setSexo(sexo_modificar);

            }break;

            case 6:{

                string direccion_modificar;
                cout << "Introduzca la dirección modificada:" << endl;
                cin.ignore();
                getline(cin, direccion_modificar);
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

        cout << "Introduce la fecha: (FORMATO DD/MM/AAAA)" << endl;
        cin >> fecha;

        cout << "Introduce la hora: (FORMATO HH:MM)" << endl;
        cin >> hora;

        cout << "Introduce la duración en minutos" << endl;
        cin >> duracion;

        Cita c(fecha, hora, atoi(duracion.c_str()));
        f.anadirCitaPaciente(DNI, c);
        
        cout << "Cita añadida. Pulse ENTER para continuar..." << endl;
        cin.clear();
        cin.get();
        cin.clear();
    }
    else{
        cout << "El DNI introducido no se corresponde a ningun paciente. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        cin.clear();
    }
}

void case_citasHoy(){
    cout << "Citas de hoy" << endl;
    GestorFichero f;
    list <Cita> citas = f.getCitasHoy();
    if (citas.size() == 0){
        cout << "Hoy no tiene citas. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        cin.clear();
    }
    else{
        cout << "Hoy tiene las siguientes citas: " << endl;
        for(list <Cita>::iterator it = citas.begin(); it != citas.end(); it++){
            cout << "Hora: " << it -> getHora() << endl
                    << "Duración: " << it -> getDuracion() << " minutos" << endl;
        }
        cout << "Pulse ENTER para continuar...";
        cin.ignore();
        cin.get();
        cin.clear();
    }
    
}

void case_buscarPaciente(){
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

        int opcion_submenu;
        do{
            system("clear");
            mostrar_menu_paciente(aux);
            cin >> opcion_submenu;
            cin.ignore();
            switch(opcion_submenu){
                case 1:{ // Mostrar historial
                    list <ElementoHistorial> historial = f.getHistorialPaciente(DNI);
                    if (historial.size() == 0){
                        cout << "El paciente " << aux.getNombreCompleto() << " no tiene historial médico" << endl;
                        cout << "Pulse ENTER para continuar...";
                        cin.ignore();
                        cin.get();
                        
                    }
                    else{
                        cout << "Historial médico de " << aux.getNombreCompleto() << ": " << endl;
                        for(list <ElementoHistorial>::iterator it = historial.begin(); it != historial.end(); it++){
                            cout << it -> getFecha() << endl
                                    << it -> getObservaciones() << endl;
                        }
                        cout << "Pulse ENTER para continuar..." << endl;
                        cin.ignore();
                        cin.get();
                    }
                    
                }break;

                case 2:{
                    list <Cita> citas = f.getProximasCitasPaciente(DNI);
                    if (citas.size() == 0){
                        cout << "No hay citas. Pulse ENTER para continuar..." << endl;
                        cin.ignore();
                        cin.get();
                    }
                    else{
                        cout << "PRÓXIMAS CITAS DE " << aux.getNombreCompleto() << ": " << endl;
                        for(Cita &c : citas){
                            cout << c.getFecha() << " a las " << c.getHora() << endl
                                    << "Duración: " << c.getDuracion() << " minutos" << endl;
                        }
                    }
                    cin.ignore();
                    cin.get();
                }break;

                case 3:{ // Eliminar cita

                    list <Cita> citas = f.getProximasCitasPaciente(DNI);

                    if (citas.size() != 0){
                        cout << "PRÓXIMAS CITAS DE " << aux.getNombreCompleto() << ": " << endl;
                        for(Cita &c : citas){
                            cout << c.getFecha() << " a las " << c.getHora() << endl
                                    << "Duración: " << c.getDuracion() << " minutos" << endl;
                        }
                        
                        cout << "Introduzca fecha de la cita a eliminar:" << endl;
                        string fecha;
                        cin >> fecha;

                        cout << "Introduzca hora:" << endl;
                        string hora;
                        cin >> hora;
                        if (f.buscarCita(fecha, hora, DNI)){
                            f.eliminarCita(DNI, fecha, hora);
                        }
                        else{
                            cout << "La cita indicada no existe." << endl;
                        }
                        cout << "Cita eliminada. Pulse ENTER para continuar..." << endl;
                        cin.ignore();
                        cin.get();
                    }
                    else{
                        cout << "No hay citas. Pulse ENTER para continuar" << endl;
                        cin.ignore();
                        cin.get();
                    }

                }break;

                case 4:{ // Modificar cita
                    
                    list <Cita> citas = f.getProximasCitasPaciente(DNI);
                    if (citas.size() != 0){
                        cout << "PRÓXIMAS CITAS DE " << aux.getNombreCompleto() << ": " << endl;
                        for(Cita &c : citas){
                            cout << c.getFecha() << " a las " << c.getHora() << endl
                                    << "Duración: " << c.getDuracion() << " minutos" << endl;
                        }

                        cout << "Va a modificar una cita" << endl;
                        cout << "Introduzca fecha:" << endl;
                        string fecha_a;
                        cin >> fecha_a;
                        cout << "Introduzca hora:" << endl;
                        string hora_a;
                        cin >> hora_a;

                        if (f.buscarCita(fecha_a, hora_a, DNI)){
                            cout << "Introduzca fecha nueva:" << endl;
                            string fecha_n;
                            cin >> fecha_n;

                            cout << "Introduzca hora nueva:" << endl;
                            string hora_n;
                            cin >> hora_n;

                            cout << "Introduzca duración nueva: " << endl;
                            string duracion_n;
                            cin >> duracion_n;

                            Cita citaNueva(fecha_n, hora_n, stoi(duracion_n));

                            f.modificarCitaPaciente(DNI, fecha_a, hora_a, citaNueva);
                            cout << "Cita modificada. Pulse ENTER para continuar..." << endl;
                            cin.ignore();
                            cin.get();
                        }
                        else{
                            cout << "La cita indicada no existe. Pulse ENTER para continuar..." << endl;
                            cin.ignore();
                            cin.get();
                        }
                    }
                    else{
                        cout << "No hay citas. Pulse ENTER para continuar..." << endl;
                        cin.ignore();
                        cin.get();
                    }
                    
                }break;

                case 5:{ // Añadir historial médico
                    
                    cout << "Introduzca la fecha:" << endl;
                    string fecha;
                    cin >> fecha;

                    cout << "Introduzca observaciones:" << endl;
                    string observaciones;
                    cin.ignore();
                    getline(cin, observaciones);
                    ElementoHistorial h(fecha, observaciones);

                    GestorFichero f;
                    f.anadirHistorialPaciente(DNI, h);

                    cout << "Historial añadido. Pulse ENTER para continuar..." << endl;
                    cin.get();
                    cin.clear();

                }break;

                case 6:{ // Añadir tratamiento

                    GestorFichero f;
                    string medicamento, fecha_inicio, fecha_fin, observaciones;

                    cout << "Introduce nombre del medicamento/tratamiento:" << endl;
                    cin.ignore();
                    getline(cin, medicamento);

                    cout << "Introduce fecha de inicio (DD/MM/AAAA):" << endl;
                    cin >> fecha_inicio; 

                    cout << "Introduce fecha de fin (DD/MM/AAAA):" << endl;
                    cin >> fecha_fin;

                    cout << "Introduce alguna descripción u observaciones:" << endl;
                    getline(cin, observaciones);

                    Tratamiento t(medicamento, fecha_inicio, fecha_fin, observaciones);

                    f.anadirTratamientoPaciente(DNI, t);

                    cout << "Tratamiento añadido" << endl;
                    cin.get();
                    cin.clear();

                }break;

                case 7:{ // Volver atrás
                    
                    break;

                }break;

                case 8:{ // Mostrar tratamientos
                    GestorFichero f;
                    list <Tratamiento> tratamientos = f.getTratamientosPaciente(DNI);
                    if (tratamientos.size() == 0){
                        cout << "No hay tratamientos. Pulse ENTER para continuar..." << endl;
                        cin.ignore();
                        cin.get();
                        cin.clear();
                    }
                    cout << "Lista de tratamientos: " << endl;
                    for(Tratamiento &t : tratamientos){
                        cout << endl << "Medicamento/Tratamiento: " << t.getMedicamento() << endl
                             << "Fecha inicio: " << t.getFechaComienzo() << endl
                             << "Fecha fin: " << t.getFechaFin() << endl
                             << "Observaciones: " << t.getObservaciones() << endl << endl;
                    }

                    cout << "Pulse ENTER para continuar" << endl;
                    cin.get();
                    cin.clear();

                }break;

                case 9:{
                    
                }

                default:{
                    cout << "Opcion no válida. Presione ENTER para continuar...";
                    cin.ignore();
                    cin.get();
                }break;
            }
        }while(opcion_submenu != 7);
    }
    else{
        cout << "Paciente con DNI " << DNI << " no existe" << endl;
        cin.ignore();
        cin.get();
    }
}

void case_mostrarListaPacientes(){
    GestorFichero f;
    list <Paciente> pacientes = f.getTodosPacientes();

    cout << "PACIENTES EN EL SISTEMA: " << endl;
    for(Paciente &p : pacientes){
        cout << "DNI " << p.getDNI() << " - " << p.getNombreCompleto() << endl;
    }

    cout << "Pulse ENTER para continuar...";
    cin.ignore();
    cin.get();
}