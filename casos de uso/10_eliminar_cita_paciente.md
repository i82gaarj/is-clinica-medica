## Añadir nuevo paciente

**ID**: 10
**Descripción**: Una vez seleccionado el paciente, el sistema muestra las citas del mismo y al seleccionar la cita que se desea eliminar, el sistema lo ejecuta 

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea eliminar una cita a un determinado paciente.
1. El secretario selecciona la opción de eliminar cita en el menú principal.
1. El secretario introduce los datos del paciente para realizar la búsqueda como en el caso de uso 04.
1. Se muestra la útima cita asignada al paciente y se muestra un mensaje preguntando si desea eliminarla.
1. El secretario confirma la eliminación de la cita.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el nuevo paciente.

**Flujos alternativos**:

5.a. Si el paciente no tiene ninguna cita, se indicará en un mensaje de error.