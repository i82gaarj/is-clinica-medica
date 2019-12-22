## Mostrar historial de un paciente

**ID**: 05
**Descripción**: Una vez encontrado un paciente, se selecciona la opción "Mostrar historial", y el sistema lo muestra.

**Actores principales**: Secretario

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea consultar el historial de medicación de un paciente.
1. El secretario selecciona la opción de buscar paciente.
1. Se le pedirá al secretario el DNI del paciente y se buscará.
1. Una vez encontrado, el secretario selecciona la opción para mostrar el historial de medicación.
1. El sistema muestra por pantalla el historial de medicación del paciente seleccionado.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el paciente.

**Flujos alternativos**:

* 3.a. Si el paciente no existe, se muestra un mensaje de error.
* 5.a. Si no tiene historial se mostrará un mensaje indicándolo.
