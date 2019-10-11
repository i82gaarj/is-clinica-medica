## Añadir nuevo paciente

**ID**: 05
**Descripción**: Una vez encontrado un paciente, se selecciona la opción "mostrar historial de medicación", y el sistema lo muestra.

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en el sistema.
* Haber seleccionado a un paciente con anterioridad.


**Flujo principal**:
1. El secretario desea consultar el historial de medicación de un paciente 
1. Se le pedirá al secretario el nombre y apellidos del paciente y se buscará como se indica en el caso de uso 04.
1. Una vez encontrado, el secretario selecciona la opción para mostrar el historial de medicación.
1. El sistema muestra por pantalla el historial de medicación del paciente seleccionado.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el paciente.

**Flujos alternativos**:

* 4.a. Si no tiene medicación en vigor se mostrará un mensaje indicándolo.