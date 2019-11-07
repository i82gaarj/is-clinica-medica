## Añadir cita a un paciente

**ID**: 09
**Descripción**: Se añade una nueva cita a su historial de citas.

**Actores principales**: Secretario

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea añadir una nueva cita para el paciente.
1. El secretario selecciona en el menú principal la opción "Añadir cita".
1. Se le pedirá al secretario el nombre y apellidos del paciente y se buscará como se indica en el caso de uso 04.
1. El secretario introduce la fecha y la hora de la nueva cita.
1. El sistema almacena los datos en el historial.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el paciente.

**Flujos alternativos**:

5.a. Si la cita que desea añadir coincide con otra en dicho horario, no podrá almacenarse dicha cita y además se mostrará un mensaje indicando que en ese horario ya hay una cita establecida.
3.a. Si el paciente no existe, se muestra un mensaje de error.