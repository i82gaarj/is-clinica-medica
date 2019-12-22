## Modificar cita de un paciente

**ID**: 12
**Descripción**: Se modifica la última cita asignada.

**Actores principales**: Secretario

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea modificar la cita de un paciente.
1. El secretario introduce el DNI del paciente.
1. El secretario selecciona la opción de "Modificar cita".
1. El secretario introduce la fecha y la hora de la nueva cita.
1. El sistema modifica los datos del historial de citas.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el paciente.

**Flujos alternativos**:

3.a. Si el paciente no existe, se muestra un mensaje de error.
5.a. Si la cita que desea añadir coincide con otra en dicho horario, no podrá almacenarse dicha cita y además se mostrará un mensaje indicando que en ese horario ya hay una cita establecida.