#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include "elementoHistorial.h"
#include "tratamiento.h"
#include "cita.h"

using std::string;

class Paciente{
private:
    string dni_;
    string nombreCompleto_;
    string fechaNacimiento_;
    int telefono_;
    char sexo_;
    string direccion_;
    Tratamiento tratamiento_;

public:
    Paciente(string dni, string nombreCompleto);

    void mostrar_historial_medico();

    inline string getNombre(){
        return nombreCompleto_;
    }

    inline string getFechaNacimiento(){
        return fechaNacimiento_;
    }

    inline char getSexo(){
        return sexo_;
    }

    inline int getTelefono(){
        return telefono_;
    }

    inline int getDNI(){
        return dni_;
    }

    inline string getDireccion(){
        return direccion_;
    }

    inline void setNombre(string nombreCompleto){
        nombreCompleto_ = nombreCompleto;
    }

    inline void setFechaNacimiento(string fechaNacimiento){
        fechaNacimiento_ = fechaNacimiento;
    }

    inline void setSexo(char sexo){
        sexo_ = sexo;
    }

    inline void setTelefono(int telefono){
        telefono_ = telefono;
    }

    inline void setDNI(string dni){
        dni_ = dni;
    }

    inline void setDireccion(string direccion){
        direccion_ = direccion;
    }

    inline Tratamiento getTratamiento(){
        return tratamiento_;
    }

    inline void setTratamiento(){
        tratamiento_ = tratamiento;
    }

    bool addCita(Cita cita);
    
    inline void finalizarTratamiento(){
        tratamiento_ = NULL;
    }
};

#endif