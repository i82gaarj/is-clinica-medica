#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>

#include "cita.h"
#include "paciente.h"
#include "gestorFichero.h"

using namespace std;

GestorFichero::GestorFichero(string nombreFichero){
	nombreFichero_ = nombreFichero;
}

list <Paciente> GestorFichero::getTodosPacientes(){
	list <Paciente> pacientes;

	ifstream file(nombreFichero_.c_str());
	if (file){
		while(!file.eof()){
			if (file.peek() == ifstream::traits_type::eof()){
				break;
			}

			string dni, nombreCompleto, telefono, direccion, sexo, fechaNacimiento;

			getline(file, dni);
			getline(file, nombreCompleto);
			getline(file, fechaNacimiento);
			getline(file, telefono);
			getline(file, sexo);
			getline(file, direccion);

			Paciente p(dni, nombreCompleto, fechaNacimiento, atoi(telefono.c_str()), sexo, direccion);

			pacientes.push_back(p);
		}
	}
	return pacientes;
}

list <Cita> GestorFichero::getCitasHoy(){

}

void GestorFichero::anadirPaciente(Paciente p){
	fstream file;
	file.open(nombreFichero_.c_str(), ios::out | ios::app);
	file << p.getDNI() << endl
		 << p.getNombreCompleto() << endl
		 << p.getFechaNacimiento() << endl
		 << p.getTelefono() << endl
		 << p.getSexo() << endl
		 << p.getDireccion() << endl;
	file.close();
	file.open(p.getDNI() + "_citas.txt", ios::out | ios::app);
	file.close();
	file.open(p.getDNI() + "_historial.txt", ios::out | ios::app);
	file.close();
	file.open(p.getDNI() + "_tratamientos.txt", ios::out | ios::app);
}

Paciente GestorFichero::getPacienteFromDNI(string DNI){
	fstream file;
	file.open(nombreFichero_.c_str(), ios::in);
	string dni_buscar, nombreCompleto, fechaNacimiento, sexo, direccion, telefono;
	while(!file.eof()){
		
		getline(file, dni_buscar);
		if (DNI == dni_buscar){
			getline(file, nombreCompleto);
			getline(file, fechaNacimiento);
			getline(file, telefono);
			getline(file, sexo);
			getline(file, direccion);
		}
	}
	Paciente p(DNI, nombreCompleto, fechaNacimiento, atoi(telefono.c_str()), sexo, direccion);
	return p;
}

void GestorFichero::anadirCitaPaciente(string DNI, Cita c){

}

void GestorFichero::anadirTratamientoPaciente(Paciente p){

}

list <Cita> GestorFichero::getCitasPaciente(Paciente p){

}

Tratamiento GestorFichero::getTratamientoPaciente(Paciente p){

}

list <ElementoHistorial> GestorFichero::getHistorialPaciente(string DNI){
	fstream file;
	file.open(DNI + "_historial.txt", ios::in);

	list <ElementoHistorial> historial;
	while(!file.eof()){
		string fecha, observaciones;
		getline(file, fecha);
		getline(file, observaciones);
		ElementoHistorial h(fecha, observaciones);
		historial.push_back(h);
	}
	return historial;
}

bool GestorFichero::buscarPaciente(string DNI){
	fstream file;
	file.open(nombreFichero_.c_str(), ios::in);
	string dni_buscar;
	while(!file.eof()){
		getline(file, dni_buscar);
		if (DNI == dni_buscar){
			return true;
		}
	}
	return false;
}

void GestorFichero::modificarTratamientoPaciente(Paciente p){

}

void GestorFichero::modificarCitaPaciente(Paciente p){

}

bool GestorFichero::eliminarPaciente(string DNI){

}

bool GestorFichero::eliminarCita(Paciente p, Cita c){

}

Cita GestorFichero::getUltimaCitaPaciente(string DNI){

}

void GestorFichero::anadirHistorialPaciente(string DNI, ElementoHistorial h){

}