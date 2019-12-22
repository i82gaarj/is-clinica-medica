#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <ctime>

#include "cita.h"
#include "paciente.h"
#include "gestorFichero.h"
#include "tratamiento.h"

using namespace std;

GestorFichero::GestorFichero(string nombreFichero){
	nombreFichero_ = nombreFichero;
}

list <Paciente> GestorFichero::getTodosPacientes(){
	list <Paciente> pacientes;

	ifstream file(nombreFichero_.c_str());
	if (file){
		string dni, nombreCompleto, telefono, direccion, sexo, fechaNacimiento;
		while(getline(file, dni)){
			getline(file, nombreCompleto);
			getline(file, fechaNacimiento);
			getline(file, telefono);
			getline(file, sexo);
			getline(file, direccion);

			Paciente p(dni, nombreCompleto, fechaNacimiento, atoi(telefono.c_str()), sexo, direccion);

			pacientes.push_back(p);
		}
	}
	file.close();
	return pacientes;
}

list <Cita> GestorFichero::getCitasHoy(){
	list <Cita> citas;

	time_t t = time(0);
	tm* now = localtime(&t);
	string day = now->tm_mday < 10 ? "0" + now->tm_mday : std::to_string(now->tm_mday);
	string hoy = day + "/" + to_string(now -> tm_mon  + 1) + "/" + to_string(now -> tm_year + 1900);

	list <Cita> todas = getTodasCitas();
	for(Cita &c : todas){
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
	file.close();
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
	file.close();
	Paciente p(DNI, nombreCompleto, fechaNacimiento, atoi(telefono.c_str()), sexo, direccion);
	return p;
}

void GestorFichero::anadirCitaPaciente(string DNI, Cita c){
	nombreFichero_ = DNI + "_citas.txt";
	fstream file;
	file.open(nombreFichero_.c_str(), ios::out | ios::app);
	if (file){
		file << c.getFecha() << endl
			 << c.getHora() << endl
			 << c.getDuracion() << endl;
	}
	file.close();
}

void GestorFichero::anadirTratamientoPaciente(string DNI, Tratamiento t){
	nombreFichero_ = DNI + "_tratamientos.txt";
	ofstream file(nombreFichero_.c_str(), ios::app);

	file << t.getMedicamento() << endl
		 << t.getFechaComienzo() << endl
		 << t.getFechaFin() << endl
		 << t.getObservaciones() << endl;

	file.close();
}

list <Tratamiento> GestorFichero::getTratamientosPaciente(string DNI){
	nombreFichero_ = DNI + "_tratamientos.txt";
	ifstream file(nombreFichero_.c_str());
	string medicamento, fecha_i, fecha_f, observaciones;
	list <Tratamiento> tratamientos;
	while(getline(file, medicamento)){
		getline(file, fecha_i);
		getline(file, fecha_f);
		getline(file, observaciones);
		Tratamiento t(medicamento, fecha_i, fecha_f, observaciones);
		tratamientos.push_back(t);
	}
	file.close();
	return tratamientos;
}

list <ElementoHistorial> GestorFichero::getHistorialPaciente(string DNI){
	fstream file;
	file.open(DNI + "_historial.txt", ios::in);

	list <ElementoHistorial> historial;
	string fecha, observaciones;
	while(getline(file, fecha)){
		getline(file, observaciones);
		ElementoHistorial h(fecha, observaciones);
		historial.push_back(h);
	}
	return historial;
}

bool GestorFichero::buscarPaciente(string DNI){
	ifstream file(nombreFichero_.c_str());
	if (file){
		string dni_buscar;
		while(!file.eof()){
			getline(file, dni_buscar);
			if (DNI == dni_buscar){
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

void GestorFichero::modificarCitaPaciente(string DNI, string fecha_antigua, string hora_antigua, Cita citaNueva){
	eliminarCita(DNI, fecha_antigua, hora_antigua);
	anadirCitaPaciente(DNI, citaNueva);
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
			file.close();
			file_aux.close();
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

bool GestorFichero::eliminarCita(string DNI, string fecha, string hora){
	ifstream file((DNI + "_citas.txt").c_str());
	ofstream file_tmp("citastemp.txt");
	int countCitas = 0;
	string fecha_f, hora_f, duracion_f;
	while(getline(file, fecha_f)){
		getline(file, hora_f);
		if (fecha == fecha_f && hora == hora_f){
			file.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
		else{
			countCitas++;
			file.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	}
	file.clear();
	file.seekg(0, ios_base::beg);

	int i = 0;
	while(getline(file, fecha_f)){
		getline(file, hora_f);
		if (fecha == fecha_f && hora == hora_f){
			file.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
		else if (i == countCitas){
			file_tmp << fecha_f << endl
					 << hora_f << endl;
			getline(file, duracion_f);
			file_tmp << duracion_f;
			i++;
		}
		else{
			file_tmp << fecha_f << endl
					 << hora_f << endl;
			getline(file, duracion_f);
			file_tmp << duracion_f << endl;
			i++;
		}
	}
	file.close();
	file_tmp.close();
	remove((DNI + "_citas.txt").c_str());
	rename("citastemp.txt", (DNI + "_citas.txt").c_str());

}

list <Cita> GestorFichero::getProximasCitasPaciente(string DNI){
	list <Cita> citas_paciente = getCitasPaciente(DNI);
	list <Cita> proximas_citas_paciente;

	time_t t = time(0);

	for(Cita &c : citas_paciente){
		tm fechaCita;
		strptime((c.getFecha() + " " + c.getHora()).c_str(), "%d/%m/%Y %H:%M", &fechaCita);
		time_t fechaCita_ = mktime(&fechaCita);
		if ((difftime(fechaCita_, t)) > 0){ // Comparamos la fecha de hoy y de cada cita
			proximas_citas_paciente.push_back(c);
		}
	}
	return proximas_citas_paciente;
}

void GestorFichero::anadirHistorialPaciente(string DNI, ElementoHistorial h){
	setNombreFichero(DNI + "_historial.txt");
	ofstream file(nombreFichero_.c_str(), ios::app);
	file << h.getFecha() << endl
		 << h.getObservaciones() << endl;
	file.close();
}

void GestorFichero::modificarPaciente(Paciente p_nuevo, string DNI){
	// Eliminamos paciente sin borrar su historial
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
		while(getline(file, fecha)){
			getline(file, hora);
			getline(file, duracion);
			Cita c(fecha, hora, stoi(duracion));
			citas.push_back(c);
		}
	}
	file.close();
	return citas;
}

bool GestorFichero::buscarCita(string fecha, string hora){
	list <Cita> citas = getTodasCitas();
	for(Cita &c : citas){
		if (c.getFecha() == fecha && c.getHora() == hora){
			return true;
		}
	}
	return false;
}

bool GestorFichero::buscarCita(string fecha, string hora, string DNI){
	list <Cita> citas = getCitasPaciente(DNI);
	for(Cita &c : citas){
		if (c.getFecha() == fecha && c.getHora() == hora){
			return true;
		}
	}
	return false;
}

void GestorFichero::eliminarTratamiento(string DNI, string medicamento){
	nombreFichero_ = DNI + "_tratamientos.txt";
	ifstream file(nombreFichero_.c_str());
	if (file){
		ofstream file_aux("tratamientos_temp.txt");
		int countLines = 0;
		string line;
		while(getline(file, line)){
			if (line == medicamento){
				for (int i = 0; i < 3; i++){
					file.ignore(std::numeric_limits<streamsize>::max(), '\n');
				}
			}
			else{
				countLines++;
			}
		}
		file.clear();
		file.seekg(0, ios_base::beg);
		int i = 0;
		while(getline(file, line)){
			if (line == medicamento){
				for (int j = 0; j < 3; j++){
					file.ignore(std::numeric_limits<streamsize>::max(), '\n');
				}
			}
			else{
				file_aux << line << endl;
				i++;
			}
		}
		file.close();
		file_aux.close();
		remove(nombreFichero_.c_str());
		rename("tratamientos_temp.txt", nombreFichero_.c_str());
	}
}

void GestorFichero::modificarTratamiento(string DNI, string medicamento, Tratamiento nuevo){
	eliminarTratamiento(DNI, medicamento);
	anadirTratamientoPaciente(DNI, nuevo);
}

bool GestorFichero::buscarTratamiento(string DNI, string medicamento){
	nombreFichero_ = DNI + "_tratamientos.txt";
	ifstream file(nombreFichero_.c_str());
	if (file){
		string aux;
		while(getline(file, aux)){
			if (aux == medicamento){
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}
}