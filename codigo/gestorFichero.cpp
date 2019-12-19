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
}

Paciente GestorFichero::getPacienteFromDNI(string DNI){
	fstream file;
	file.open(nombreFichero_.c_str(), ios::in | ios::app);
	string nombreCompleto, fechaNacimiento, sexo, direccion, telefono;

	while(!file.eof()){
		string str;
		getline(file, str);
		if (DNI == str){
			getline(file, nombreCompleto);
			getline(file, fechaNacimiento);
			getline(file, telefono);
			getline(file, sexo);
			getline(file, direccion);
		}
	Paciente p(DNI, nombreCompleto, fechaNacimiento, atoi(telefono.c_str()), sexo, direccion);
	return p;
	}
}

void GestorFichero::anadirCitaPaciente(Paciente p){

}

void GestorFichero::anadirTratamientoPaciente(Paciente p){

}

list <Cita> GestorFichero::getCitasPaciente(Paciente p){

}

Tratamiento GestorFichero::getTratamientoPaciente(Paciente p){

}

list <ElementoHistorial> GestorFichero::getHistorialPaciente(Paciente p){

}

bool GestorFichero::buscarPaciente(string DNI){

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
