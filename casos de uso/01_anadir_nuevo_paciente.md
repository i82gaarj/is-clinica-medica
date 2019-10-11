## Añadir nuevo paciente

**ID**: 01
**Descripción**: Se introducen los datos del nuevo paciente y el sistema los muestra y los guarda.

**Actores principales**: Secretario
**Actores secundarios**: Paciente

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El secretario desea introducir los datos correspondientes a un nuevo paciente.
1. El secretario comienza seleccionando la opción del menú principal que corresponde a "Añadir paciente".
1. El secretario introduce los datos correspondientes al nuevo paciente.
1. El sistema muestra por pantalla los datos introducidos para comprobar que son correctos.

**Postcondiciones**:

* Se muestra al secretario si desea hacer alguna operación más con el nuevo paciente.

**Flujos alternativos**:

4.a. Si falta algún dato del paciente por añadir, se mostrará por pantalla un mensaje de error y no podrá añadirse.
4.b. Si el paciente que desea añadir ya está en la lista, el sistema indicará que dicho paciente ya ha sido agregado con anterioridad.