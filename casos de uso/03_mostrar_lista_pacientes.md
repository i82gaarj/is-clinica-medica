## Mostrar una lista de todos los pacientes

**ID**: 03
**Descripción**: Se selecciona la opción de “Mostrar la lista de los pacientes” y el sistema imprime por pantalla los datos de los mismos.

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en el sistema.

**Flujo principal**:
1. El secretario desea visualizar la lista de todos los pacientes del sistema.
1. El secretario comienza seleccionando la opción del menú principal que corresponde a "Ver todos los pacientes".
1. El sistema imprime por pantalla la lista con todos los pacientes y sus datos principales.

**Postcondiciones**:
* Ninguna

**Flujos alternativos**:

* 3.a. Si no hay ningún paciente en la lista, el sistema imprimirá por pantalla un mensaje en el que indique que dicha lista está vacía.
* 3.b. Si ocurre algún error al leer la lista de los pacientes, se mostrará un mensaje de error.