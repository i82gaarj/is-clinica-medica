## Añadir nuevo paciente

**ID**: 06
**Descripción**: Se desea modificar el tratamiento actual de un paciente.

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea modificar el tratamiento de un paciente.
1. El secretario selecciona la opción de modificar el tratamiento actual.
1. Se le pedirá al secretario el nombre y apellidos del paciente y se buscará como se indica en el caso de uso 04.
1. El sistema muestra por pantalla el tratamiento actual del paciente y pide al secretario introducir el nuevo.
1. El secretario introduce el nuevo tratamiento.
1. El sistema guarda el nuevo tratamiento.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el nuevo paciente.

**Flujos alternativos**:

* 4.a. Si no hay ningun tratamiento, el sistema lo indicará, y se podrá añadir uno nuevo.