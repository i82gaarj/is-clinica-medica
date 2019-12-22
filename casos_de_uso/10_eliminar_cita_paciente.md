## Eliminar la cita de un paciente

**ID**: 10
**Descripción**: Una vez seleccionado el paciente, se elimina una de sus citas.

**Actores principales**: Secretario

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea eliminar una cita a un determinado paciente.
1. El secretario selecciona la opción de eliminar cita en el menú principal.
1. El secretario introduce los datos del paciente y se realiza la búsqueda.
1. Se muestran las citas del paciente.
1. El secretario introduce los datos de la cita que desea eliminar.
1. El sistema elimina la cita.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el nuevo paciente.

**Flujos alternativos**:

4.a. Si el paciente no tiene ninguna cita, se indicará en un mensaje de error.
3.a. Si el paciente no existe, se muesta un mensaje de error.