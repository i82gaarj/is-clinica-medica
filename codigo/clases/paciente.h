#include <string>
#include "historial.h"

class Paciente{
private:
    string nombre_;
    string apellidos_;
    int edad_;
    int telefono_;
    char sexo_;
    Historial h_;
public:
    Paciente();

    anadir();
    modificar();
    eliminar();

    mostrar_historial_medico();
    mostrar_historial_citas();
};