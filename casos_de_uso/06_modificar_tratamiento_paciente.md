## Modificar el tratamiento de un paciente

**ID**: 06
**Descripción**: Una vez seleccionado el paciente, se modifica el tratamiento actual del mismo.

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea modificar el tratamiento de un paciente.
1. Se le pedirá al secretario el nombre y apellidos del paciente y se buscará.
1. El secretario selecciona la opción de modificar el tratamiento actual.
1. El sistema muestra por pantalla el tratamiento actual del paciente y pide al secretario introducir el nuevo.
1. El secretario introduce el nuevo tratamiento.
1. El sistema guarda el nuevo tratamiento.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el nuevo paciente.

**Flujos alternativos**:

* 4.a. Si no hay ningun tratamiento, el sistema lo indicará, y se podrá añadir uno nuevo.