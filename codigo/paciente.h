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
    string sexo_;
    string direccion_;

public:
    Paciente(string dni, string nombreCompleto, string fechaNacimiento, int telefono, string sexo, string direccion);

    inline string getNombreCompleto() const{
        return nombreCompleto_;
    }

    inline string getFechaNacimiento() const{
        return fechaNacimiento_;
    }

    inline string getSexo() const{
        return sexo_;
    }

    inline int getTelefono() const{
        return telefono_;
    }

    inline string getDNI() const{
        return dni_;
    }

    inline string getDireccion() const{
        return direccion_;
    }

    inline void setNombreCompleto(string nombreCompleto){
        nombreCompleto_ = nombreCompleto;
    }

    inline void setFechaNacimiento(string fechaNacimiento){
        fechaNacimiento_ = fechaNacimiento;
    }

    inline void setSexo(string sexo){
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

    inline Tratamiento getTratamiento() const{

    }

    inline void setTratamiento(Tratamiento tratamiento){

    }
    
    /*inline void finalizarTratamiento(){
        tratamiento_ = NULL;
    }*/

};

#endif