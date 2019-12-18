#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include "elementoHistorial.h"
#include "tratamiento.h"
#include "cita.h"
#include "gestorFichero.h"

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

    void mostrar_historial_medico() const;

    inline string getNombre() const{
        return nombreCompleto_;
    }

    inline string getFechaNacimiento() const{
        return fechaNacimiento_;
    }

    inline char getSexo() const{
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

    inline Tratamiento getTratamiento() const{
        return tratamiento_;
    }

    inline void setTratamiento(Tratamiento tratamiento){
        tratamiento_ = tratamiento;
    }

    bool addCita(Cita cita);
    
    /*inline void finalizarTratamiento(){
        tratamiento_ = NULL;
    }*/

    Cita getUltimaCita() const{
        GestorFichero f;
        Cita c = f.getUltimaCitaPaciente(dni_);
        return c;
    }


};

#endif