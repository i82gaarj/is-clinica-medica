## Mostrar citas de un paciente

**ID**: 08
**Descripción**: Una vez seleccionado el paciente, el sistema muestra por pantalla todas las citas previas y la actual del mismo.

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea ver las citas previas del paciente hasta la fecha.
1. Se le pedirá al secretario el nombre y apellidos del paciente y se buscará.
1. El secretario selecciona la opción en el menú principal para ver todas las citas.
1. El sistema muestra por pantalla todo el historial de citas médicas.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el nuevo paciente.

**Flujos alternativos**:

* 2.a. Si no existe el paciente, se muestra un mensaje de error.
* 4.a. Si el paciente no tiene citas en el historial, se mostrará un mensaje que lo indique.