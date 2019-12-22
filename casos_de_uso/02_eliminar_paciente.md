## Eliminar a un paciente

**ID**: 02
**Descripción**: Se introduce el DNI del paciente a eliminar y el sistema lo elimina.

**Actores principales**: Secretario

**Precondiciones**:
* El paciente debe existir en el sistema

**Flujo principal**:
1. El secretario desea eliminar a un paciente de la lista.
1. El secretario comienza seleccionando la opción del menú principal que corresponde a "Eliminar paciente".
1. El secretario introduce el DNI del paciente.
1. El sistema elimina al paciente de la lista.

**Postcondiciones**:
* Ninguna

**Flujos alternativos**:

* 4.a. Si el paciente no existe, se muestra un mensaje de error.
* 4.b. Si el paciente existe en el sistema pero no ha podido ser eliminado por alguna otra causa, se muestra un mensaje de error.