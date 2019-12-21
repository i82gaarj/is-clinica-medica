#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>

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
	file.open(p.getDNI() + "_citas.txt", ios::out);
	file.close();
	file.open(p.getDNI() + "_historial.txt", ios::out);
	file.close();
	file.open(p.getDNI() + "_tratamientos.txt", ios::out);
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
	nombreFichero_ = DNI + "_citas.txt";
	ofstream file(nombreFichero_.c_str(), ios::app);
	if (file){
		file << c.getFecha() << endl
			 << c.getHora() << endl
			 << c.getDuracion() << endl;
	}
}

void GestorFichero::anadirTratamientoPaciente(Paciente p){

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
	if (buscarPaciente(DNI)){
		ifstream file(nombreFichero_.c_str());
		if (file){
			ofstream file_aux("pacientes_temp.txt");
			while(!file.eof()){
				string aux;
				getline(file, aux);
				if (aux == DNI){
					for (int i = 0; i < 5; i++) {
						file.ignore(std::numeric_limits<streamsize>::max(), '\n');
					}
				}
				else{
					file_aux << aux << endl;					
				}
			}
			remove("pacientes.txt");
			rename("pacientes_temp.txt", "pacientes.txt");
			remove((DNI + "_citas.txt").c_str());
			remove((DNI + "_historial.txt").c_str());
			remove((DNI + "_tratamientos.txt").c_str());
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}	
}

bool GestorFichero::eliminarCita(Paciente p, Cita c){

}

Cita GestorFichero::getUltimaCitaPaciente(string DNI){
	string name = DNI + "_citas.txt";
	setNombreFichero(name);
	
	ifstream file(nombreFichero_.c_str());

	if (file){
		string line, buffer[3];
		const size_t size = sizeof buffer / sizeof *buffer;
		size_t i = 0;
		while (getline(file, line)){
			buffer[i] = line;
			if ( ++i >= size ){
				i = 0;
			}
		}

		string fecha, hora, duracion;
		fecha = buffer[0];
		hora = buffer[1];
		duracion = buffer[2];
		Cita c(fecha, hora, atoi(duracion.c_str()));
		return c;
	}
}

void GestorFichero::anadirHistorialPaciente(string DNI, ElementoHistorial h){
	setNombreFichero(DNI + "_historial.txt");
	ofstream file(nombreFichero_.c_str(), ios::app);
	file << h.getFecha() << endl
		 << h.getObservaciones() << endl;

}

void GestorFichero::modificarPaciente(Paciente p){

}

list <Cita> GestorFichero::getTodasCitas(){
	list <Cita> citas;
	ifstream file(nombreFichero_);
	if (file) {
		while (!file.eof()) {
			if (file.peek() == ifstream::traits_type::eof()) {
				break;
			}

			string dni;
			getline(file, dni);

			for (int i = 0; i < 5; i++) {
				file.ignore(std::numeric_limits<streamsize>::max(), '\n');
			}

			Cita c = getUltimaCitaPaciente(dni);
			citas.push_back(c);
		}
		file.close();
	}

	return citas;
}