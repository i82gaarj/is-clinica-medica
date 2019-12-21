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
	list <Cita> citas;

	time_t t = time(0);
	tm* now = localtime(&t);
	string hoy = to_string(now -> tm_mday) + "/" + to_string(now -> tm_mon  + 1) + "/" + to_string(now -> tm_year + 1900);

	list <Cita> todas = getTodasCitas();
	for(Cita &c : todas){
		cout << c.getFecha();
		if (c.getFecha() == hoy){
			citas.push_back(c);
		}
	}
	return citas;
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
			int countLines = 0;
			string line;
			while(getline(file, line)){
				if (line == DNI){
					for (int i = 0; i < 5; i++) {
						file.ignore(std::numeric_limits<streamsize>::max(), '\n');
					}
				}
				else{
					countLines++;
				}
			}
			file.clear();
			file.seekg(0, ios_base::beg);
			for(int i = 0; i < countLines; i++){
				string aux;
				getline(file, aux);
				if (aux == DNI){
					for (int i = 0; i < 5; i++) {
						file.ignore(std::numeric_limits<streamsize>::max(), '\n');
					}
				}
				else if (i == countLines){
					file_aux << aux;					
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

void GestorFichero::modificarPaciente(Paciente p_nuevo, string DNI){
	// Eliminamos paciente sin borrar su historial
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
	}
	
	// Añade paciente modificado sin borrar su historial, citas...
	fstream file2;
	file2.open(nombreFichero_.c_str(), ios::out | ios::app);
	file2 << p_nuevo.getDNI() << endl
		  << p_nuevo.getNombreCompleto() << endl
		  << p_nuevo.getFechaNacimiento() << endl
		  << p_nuevo.getTelefono() << endl
		  << p_nuevo.getSexo() << endl
		  << p_nuevo.getDireccion() << endl;
	file2.close();
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

			list<Cita> citas_paciente = getCitasPaciente(dni);
			citas.insert(citas.end(), citas_paciente.begin(), citas_paciente.end());
		}
		file.close();
	}

	return citas;
}

list <Cita> GestorFichero::getCitasPaciente(string DNI){
	list <Cita> citas;
	ifstream file((DNI + "_citas.txt").c_str());

	if (file){
		string fecha, hora, duracion;
		while(!file.eof()){
			getline(file, fecha);
			getline(file, hora);
			getline(file, duracion);
			Cita c(fecha, hora, atoi(duracion.c_str()));
			citas.push_back(c);
		}
	}
	return citas;
}