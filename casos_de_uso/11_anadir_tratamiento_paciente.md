## Añadir tratamiento a un paciente

**ID**: 11
**Descripción**: Una vez seleccionado el paciente, se añade un tratamiento.

**Actores principales**: Secretario

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea modificar el tratamiento de un paciente.
1. Se le pedirá al secretario el nombre y apellidos del paciente y se buscará.
1. El secretario selecciona la opción de añadir un tratamiento.
1. El secretario introduce el nuevo tratamiento.
1. El sistema guarda el nuevo tratamiento.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el nuevo paciente.

**Flujos alternativos**:

* 2.a. Si el paciente no existe, se muestra un mensaje de error.