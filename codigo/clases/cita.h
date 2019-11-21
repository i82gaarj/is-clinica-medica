#ifndef CITA_H
#define CITA_H
#include <string>

using std::string;

class Cita{
private:
    string fecha_;
    string hora_;
    int duracion_;
    
public:
    Cita(string fecha, string hora, int duracion){
        *this -> setFechaHoraDuracion(fecha, hora, duracion);
    }

    inline string getFecha(){
        return fecha_;
    }

    inline string getHora(){
        return hora_;
    }

    inline int getDuracion(){
        return duracion_;
    }

    inline void setFecha(string fecha){
        fecha_ = fecha;
    }

    inline void setHora(string hora){
        hora_ = hora;
    }
    
    inline void setDuracion(int duracion){
        duracion_ = duracion;
    }

    string getFechaHoraDuracion(); // devuelve info completa

    string setFechaHoraDuracion(string fecha, string hora, int duracion); // función grande, comprobar si no solapa otra cita
};

#endif