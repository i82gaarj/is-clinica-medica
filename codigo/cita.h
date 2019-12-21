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
        fecha_ = fecha;
        hora_ = hora;
        duracion_ = duracion;
    }

    inline string getFecha() const{
        return fecha_;
    }

    inline string getHora() const{
        return hora_;
    }

    inline int getDuracion() const{
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

};

#endif