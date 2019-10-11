## Buscar a un paciente por nombre y apellidos

**ID**: 01
**Descripción**: El secretario introduce el nombre y los apellidos del paciente y el sistema muestra los datos del mismo

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario quiere consultar los datos de algún paciente en concreto
1. El secretario comienza seleccionando la opción del menú principal que corresponde a "Buscar paciente".
1. El secretario introduce el nombre y los apellidos del paciente.
1. El sistema muestra por pantalla los datos del paciente correspondiente.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación con el paciente.

**Flujos alternativos**:

* 4.a. Si no existe el paciente, se muestra en la pantalla un mensaje de error.