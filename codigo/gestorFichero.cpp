#include "gestorFichero.h"
#include "paciente.h"

using namespace std;

GestorFichero::GestorFichero(string nombreFichero){
	fstream file;
}

list <Paciente> getTodosPacientes(){

}

list <Cita> getCitasHoy(){

}

void anadirPaciente(Paciente p){
	file.open(nombreFichero.c_str(), ios::out | ios::app);
	file << p.getDNI() << endl
		 << p.getNombreCompleto() << endl
		 << p.getFechaNacimiento() << endl
		 << p.getTelefono() << endl
		 << p.getSexo() << endl
		 << p.getDireccion() << endl;
}

Paciente getDatosPaciente(string DNI){
	file.open(nombreFichero.c_str(), ios::in | ios::app);
	Paciente p;
	while(!file.eof()){
		string str;

		if (str == getline(file, str)){
			p.setDNI(str);

			getline(file, str);
			p.setNombreCompleto(str);

			getline(file, str);
			p.setFechaNacimiento(str);

			getline(file, str);
			p.setTelefono(stoi(str));

			getline(file, str);
			p.setSexo(str);

			getline(file, str);
			p.setDireccion(str);
		}
	}
}

void anadirCitaPaciente(Paciente p){

}

void anadirTratamientoPaciente(Paciente p){

}

list <Cita> getCitasPaciente(Paciente p){

}

Tratamiento getTratamientoPaciente(Paciente p){

}

list <ElementoHistorial> getHistorialPaciente(Paciente p){

}

bool buscarPaciente(string DNI){

}

void modificarTratamientoPaciente(Paciente p){

}

void modificarCitaPaciente(Paciente p){

}

bool eliminarPaciente(string DNI){

}

void eliminarCita(Paciente p, Cita c){

}

