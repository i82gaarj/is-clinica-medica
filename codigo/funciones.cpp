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
		 << "7. Mostrar una lista de todos los pacientes" << endl
         << "8. Salir" << endl;
}

void mostrar_menu_paciente(Paciente p){
    cout << "DNI " << p.getDNI() << endl
         << "Nombre: " << p.getNombreCompleto() << endl
         << "Sexo: " << p.getSexo() << endl
         << "Fecha Nacimiento: " << p.getFechaNacimiento() << endl
         << "Teléfono: " << p.getTelefono() << endl
         << "Dirección: " << p.getDireccion() << endl;
	cout << endl << "SELECCIONE: " << endl 
		 << "1. Mostrar el historial de " << p.getNombreCompleto() << endl
		 << "2. Mostrar citas de " << p.getNombreCompleto() << endl
		 << "3. Cancelar cita asignada" << endl
		 << "4. Modificar cita asignada" << endl
		 << "5. Añadir historial médico a " << p.getNombreCompleto() << endl
		 << "6. Asignar tratamiento a " << p.getNombreCompleto() << endl
		 << "7. Eliminar un tratamiento" << endl
         << "8. Mostrar tratamientos" << endl
         << "9. Modificar un tratamiento" << endl
         << "10. Volver atrás" << endl;
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

    cout << "Introduzca la fecha de nacimiento (FORMATO DD/MM/AAAA):" << endl;
    getline(cin, fechaNacimiento);

    while(!validarFecha(fechaNacimiento)){
        cout << "Fecha no válida. Introdúzcala de nuevo" << endl;
        getline(cin, fechaNacimiento);
    }

    cout << "Introduzca el número de teléfono, debe tener 9 dígitos:" << endl;
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
    convertirDNIMayuscula(DNI);
    GestorFichero f("pacientes.txt");
    if (f.buscarPaciente(DNI)){

        Paciente p = f.getPacienteFromDNI(DNI);
        string confirmar;
        cout << "¿Seguro que desea eliminar a " << p.getNombreCompleto() << "? [S|N]:" << endl;
        cin >> confirmar;
        while(confirmar != "S" && confirmar != "s" && confirmar != "N" && confirmar != "n"){
            cout << "Por favor, introduca S o N" << endl;
            cin >> confirmar;
        }
        if (confirmar == "S" || confirmar == "s"){
            f.eliminarPaciente(DNI);
            cout << "Paciente eliminado. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (confirmar == "N" || confirmar == "n"){
            cout << "Operación cancelada. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            return;
        }
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
                cout << "Introduzca la fecha de nacimiento modificada (FORMATO DD/MM/AAAA):" << endl;
                getline(cin, fechaNacimiento_modificar);
                if (validarFecha(fechaNacimiento_modificar)){
                    aux.setTelefono(stoi(fechaNacimiento_modificar));
                }
                else{
                    cout << "Nueva fecha de nacimiento no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
                    cin.ignore();
                    cin.get();
                    cin.clear();
                    break;
                }								

            }break;

            case 4:{

                string telefono_modificar;
                cout << "Introduzca el número de teléfono modificado, debe tener 9 dígitos:" << endl;
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

        cout << "Introduce la fecha: (FORMATO DD/MM/AAAA):" << endl;
        cin >> fecha;
        if (!validarFecha(fecha)){
            cout << "Fecha no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Introduce la hora (FORMATO HH:MM):" << endl;
        cin >> hora;
        if (!validarHora(hora)){
            cout << "Hora no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Introduce la duración en minutos" << endl;
        cin >> duracion;
        if (!validarDuracion(duracion)){
            cout << "Duracion no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            return;
        }

        Cita c(fecha, hora, atoi(duracion.c_str()));
        f.anadirCitaPaciente(DNI, c);
        
        cout << "Cita añadida. Pulse ENTER para continuar..." << endl;
        cin.ignore();
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
    cout << "Introduzca DNI: ";
    cin >> DNI;
    convertirDNIMayuscula(DNI);
    GestorFichero f;
    if (f.buscarPaciente(DNI) == true){
        Paciente aux = f.getPacienteFromDNI(DNI);

        int opcion_submenu = 0;
        do{
            system("clear");
            mostrar_menu_paciente(aux);
            cin >> opcion_submenu;
            cin.ignore();
            switch(opcion_submenu){
                case 1:{ // Mostrar historial
                    
                    case_submenu_mostrarHistorial(aux);
                    
                }break;

                case 2:{ // Mostrar citas
                    
                    case_submenu_mostrarCitas(aux);

                }break;

                case 3:{ // Eliminar cita

                    case_submenu_eliminarCita(aux);

                }break;

                case 4:{ // Modificar cita
                    
                    case_submenu_modificarCita(aux);
                    
                }break;

                case 5:{ // Añadir historial médico
                    
                    case_submenu_anadirHistorialMedico(aux);

                }break;

                case 6:{ // Añadir tratamiento

                    case_submenu_anadirTratamiento(aux);

                }break;

                case 7:{ // Eliminar tratamiento
                    
                    case_submenu_eliminarTratamiento(aux);

                }break;

                case 8:{ // Mostrar tratamientos
                    
                    case_submenu_mostrarTratamientos(aux);

                }break;

                case 9:{ // Modificar tratamiento
                    
                    case_submenu_modificarTratamiento(aux);

                }

                case 10:{ // Volver atrás

                    break;

                }

                default:{
                    cout << "Opcion no válida. Presione ENTER para continuar...";
                    cin.ignore();
                    cin.get();
                }break;
            }
        }while(opcion_submenu != 10);
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

    if (pacientes.size() == 0){
        cout << "No hay ningun paciente todavía" << endl;
        cout << "Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
    else{
        cout << "PACIENTES EN EL SISTEMA: " << endl;
        for(Paciente &p : pacientes){
            cout << "DNI " << p.getDNI() << " - " << p.getNombreCompleto() << endl;
        }

        cout << "Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
    
}

void case_submenu_mostrarHistorial(Paciente p){
    GestorFichero f;
    list <ElementoHistorial> historial = f.getHistorialPaciente(p.getDNI());
    if (historial.size() == 0){
        cout << "El paciente " << p.getNombreCompleto() << " no tiene historial médico" << endl;
        cout << "Pulse ENTER para continuar...";
        cin.ignore();
        cin.get();
        
    }
    else{
        cout << "Historial médico de " << p.getNombreCompleto() << ": " << endl;
        for(list <ElementoHistorial>::iterator it = historial.begin(); it != historial.end(); it++){
            cout << it -> getFecha() << endl
                    << it -> getObservaciones() << endl;
        }
        cout << "Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
}

void case_submenu_mostrarCitas(Paciente p){
    GestorFichero f;
    list <Cita> citas = f.getProximasCitasPaciente(p.getDNI());
    if (citas.size() == 0){
        cout << "No hay citas. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
    else{
        cout << "PRÓXIMAS CITAS DE " << p.getNombreCompleto() << ": " << endl;
        for(Cita &c : citas){
            cout << c.getFecha() << " a las " << c.getHora() << endl
                    << "Duración: " << c.getDuracion() << " minutos" << endl;
        }
    }
    cin.ignore();
    cin.get();
}

void case_submenu_eliminarCita(Paciente p){
    GestorFichero f;
    list <Cita> citas = f.getProximasCitasPaciente(p.getDNI());

    if (citas.size() != 0){
        cout << "PRÓXIMAS CITAS DE " << p.getNombreCompleto() << ": " << endl;
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
        if (f.buscarCita(fecha, hora, p.getDNI())){
            string confirmar;
            cout << "¿Seguro que desea eliminar la cita de " << p.getNombreCompleto() << " el día " << fecha << " a las " << hora << "? [S|N]:" << endl;
            cin >> confirmar;
            while(confirmar != "S" && confirmar != "s" && confirmar != "N" && confirmar != "n"){
                cout << "Por favor, introduca S o N" << endl;
                cin >> confirmar;
            }
            if (confirmar == "S" || confirmar == "s"){
                f.eliminarCita(p.getDNI(), fecha, hora);
                cout << "Cita eliminada. Pulse ENTER para continuar..." << endl;
                cin.ignore();
                cin.get();
            }
            else if (confirmar == "N" || confirmar == "n"){
                cout << "Operación cancelada. Pulse ENTER para continuar..." << endl;
                cin.ignore();
                cin.get();
                return;
            }
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
}

void case_submenu_modificarCita(Paciente p){
    GestorFichero f;
    list <Cita> citas = f.getProximasCitasPaciente(p.getDNI());
    if (citas.size() != 0){
        cout << "PRÓXIMAS CITAS DE " << p.getNombreCompleto() << ": " << endl;
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

        if (f.buscarCita(fecha_a, hora_a, p.getDNI())){
            cout << "Introduzca fecha nueva:" << endl;
            string fecha_n;
            cin >> fecha_n;
            if(!validarFecha(fecha_n)){
                cout << "Fecha no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
                cin.ignore();
                cin.get();
                return;
            }

            cout << "Introduzca hora nueva:" << endl;
            string hora_n;
            cin >> hora_n;
            if(!validarHora(hora_n)){
                cout << "Hora no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
                cin.ignore();
                cin.get();
                return;
            }

            cout << "Introduzca duración nueva: " << endl;
            string duracion_n;
            cin >> duracion_n;
            if(!validarDuracion(duracion_n)){
                cout << "Duración no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
                cin.ignore();
                cin.get();
                return;
            }

            Cita citaNueva(fecha_n, hora_n, stoi(duracion_n));

            f.modificarCitaPaciente(p.getDNI(), fecha_a, hora_a, citaNueva);
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
}

void case_submenu_anadirHistorialMedico(Paciente p){
    cout << "Introduzca la fecha:" << endl;
    string fecha;
    cin >> fecha;
    if (!validarFecha(fecha)){
        cout << "Fecha no válida. Pulse ENTER para continuar...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Introduzca observaciones:" << endl;
    string observaciones;
    cin.ignore();
    getline(cin, observaciones);
    ElementoHistorial h(fecha, observaciones);

    GestorFichero f;
    f.anadirHistorialPaciente(p.getDNI(), h);

    cout << "Historial añadido. Pulse ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
}

void case_submenu_anadirTratamiento(Paciente p){
    GestorFichero f;
    string medicamento, fecha_inicio, fecha_fin, observaciones;

    cout << "Introduce nombre del medicamento/tratamiento:" << endl;
    getline(cin, medicamento);
    if (f.buscarTratamiento(p.getDNI(), medicamento)){
        cout << "Este tratamiento para este paciente ya existe. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Introduce fecha de inicio (DD/MM/AAAA):" << endl;
    cin >> fecha_inicio;
    if (!validarFecha(fecha_inicio)){
        cout << "Fecha no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        return;
    } 

    cout << "Introduce fecha de fin (DD/MM/AAAA):" << endl;
    cin >> fecha_fin;
    if (!validarFecha(fecha_fin)){
        cout << "Fecha no válida. Operación cancelada. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        return;
    } 

    cout << "Introduce alguna descripción u observaciones:" << endl;
    cin.ignore();
    getline(cin, observaciones);

    Tratamiento t(medicamento, fecha_inicio, fecha_fin, observaciones);

    f.anadirTratamientoPaciente(p.getDNI(), t);

    cout << "Tratamiento añadido. Pulse ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
}

void case_submenu_eliminarTratamiento(Paciente p){
    GestorFichero f;
    list <Tratamiento> tratamientos = f.getTratamientosPaciente(p.getDNI());
    if (tratamientos.size() == 0){
        cout << "No hay tratamientos. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        cin.clear();
        return;
    }
    cout << "Lista de tratamientos: " << endl;
    for(Tratamiento &t : tratamientos){
        cout << endl << "Medicamento/Tratamiento: " << t.getMedicamento() << endl;
    }

    string medicamento;
    cout << "Introduzca el nombre del tratamiento que desea eliminar:" << endl;
    getline(cin, medicamento);

    if (f.buscarTratamiento(p.getDNI(), medicamento)){
        string confirmar;
        cout << "¿Seguro que desea eliminar el tratamiento " << medicamento << " de " << p.getNombreCompleto() << "? [S|N]:" << endl;
        cin >> confirmar;
        while(confirmar != "S" && confirmar != "s" && confirmar != "N" && confirmar != "n"){
            cout << "Por favor, introduca S o N" << endl;
            cin >> confirmar;
        }
        if (confirmar == "S" || confirmar == "s"){
            f.eliminarTratamiento(p.getDNI(), medicamento);
            cout << "Tratamiento eliminado. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (confirmar == "N" || confirmar == "n"){
            cout << "Operación cancelada. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            return;
        }
    }
    else{
        cout << "El tratamiento indicado no existe. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
}

void case_submenu_mostrarTratamientos(Paciente p){
    GestorFichero f;
    list <Tratamiento> tratamientos = f.getTratamientosPaciente(p.getDNI());
    if (tratamientos.size() == 0){
        cout << "No hay tratamientos. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        cin.clear();
        return;
    }
    cout << "Lista de tratamientos: " << endl;
    for(Tratamiento &t : tratamientos){
        cout << endl << "Medicamento/Tratamiento: " << t.getMedicamento() << endl
                << "Fecha inicio: " << t.getFechaComienzo() << endl
                << "Fecha fin: " << t.getFechaFin() << endl
                << "Observaciones: " << t.getObservaciones() << endl << endl;
    }

    cout << "Pulse ENTER para continuar" << endl;
    cin.ignore();
    cin.get();
}

void case_submenu_modificarTratamiento(Paciente p){
    GestorFichero f;
    list <Tratamiento> tratamientos = f.getTratamientosPaciente(p.getDNI());
    if (tratamientos.size() == 0){
        cout << "No hay tratamientos. Pulse ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
        return;
    }
    cout << "Lista de tratamientos: " << endl;
    for(Tratamiento &t : tratamientos){
        cout << endl << "Medicamento/Tratamiento: " << t.getMedicamento() << endl;
    }

    cout << "Escriba el nombre del tratamiento que desea modificar:" << endl;
    string medicamento;
    getline(cin, medicamento);
    if (f.buscarTratamiento(p.getDNI(), medicamento)){
        string medicamento_modificado, fecha_i, fecha_f, observaciones;
        cout << "Introduzca nuevo nombre (si no desea cambiarlo introduzca el mismo):" << endl;
        getline(cin, medicamento_modificado);

        cout << "Introduzca fecha inicio (FORMATO DD/MM/AAAA):" << endl;
        cin >> fecha_i;
        if (!validarFecha(fecha_i)){
            cout << "Fecha no válida. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Introduzca fecha de fin (FORMATO DD/MM/AAAA):" << endl;
        cin >> fecha_f;
        if (!validarFecha(fecha_f)){
            cout << "Fecha no válida. Pulse ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Introduzca observaciones o una breve descripcion:" << endl;
        cin >> observaciones;

        Tratamiento t(medicamento_modificado, fecha_i, fecha_f, observaciones);
        f.modificarTratamiento(p.getDNI(), medicamento, t);

        cout << "Tratamiento modificado. Pulse ENTER para continuar..." << endl;
    }
    else{
        cout << "El tratamiento indicado no existe. Pulse una tecla para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
}

//Extrae la hora de una string con formato HH:MM
int strGetHora (const std::string &str) {
    std::string hora = str.substr(0, 2);
    return std::stoi(hora);
}

//Extrae los minutos de una string con formato HH:MM
int strGetMinutos (const std::string &str) {
    std::string minuto = str.substr(3, 2);
    return std::stoi(minuto);
}

bool validarFecha (const string &str) {
    if (str.size() == 10) {
        //Comprueba el formato
        for (int i = 0; i < 10; i++) {
            if (i == 2 || i == 5) {
                if (str[i] != '/') {
                    return false;
                }
            }
            else {
                if (!isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba el mes
        int m = std::stoi(str.substr(3, 2));
        if (m < 1 || m > 12) {
            return false;
        }

        //Comprueba el dia en funcion del mes
        int d = std::stoi(str.substr(0, 2));
        if (d < 1) { return false; }

        switch (m) {
            case  1: return d <= 31;
            case  2: return d <= 28;
            case  3: return d <= 31;
            case  4: return d <= 30;
            case  5: return d <= 31;
            case  6: return d <= 30;
            case  7: return d <= 31;
            case  8: return d <= 31;
            case  9: return d <= 30;
            case 10: return d <= 31;
            case 11: return d <= 30;
            case 12: return d <= 31;
        }
    }
    else {
        return false;
    }

    return true;
}

//Comprueba que la hora este en el formato HH:MM y sea valida
bool validarHora (const std::string &str) {
    if (str.size() == 5) {
        //Comprueba el formato
        for (int i = 0; i < 5; i++) {
            if (i == 2) {
                if (str[i] != ':') {
                    return false;
                }
            }
            else {
                if (!std::isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba que la hora sea valida
        int h = strGetHora(str);
        if (h < 0 || h > 23) {
            return false;
        }

        //Comprueba que los minutos sean validos
        int m = strGetMinutos(str);
        if (m < 0 || m > 59) {
            return false;
        }
    }
    else {
        return false;        
    }

    return true;
}

bool validarDuracion(const string &duracion){
    for (int i = 0; i < duracion.size(); i++){
        if (!isdigit(duracion[i])){
            return false;
        }
    }
    if (stoi(duracion) <= 0){
        return false;
    }
    else{
        return true;
    }
}