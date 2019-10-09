## Extracción de requisitos

#### Partes interesadas:
* Secretario
* Pacientes

#### Datos que gestiona el sistema:
* Pacientes
  * Nombre
  * Apellidos
  * Teléfono
  * Dirección
  * Sexo
* Historial médico
  * Enfermedades
    * Crónica
    * Temporal
  * Operaciones
  * Análisis
    * Sangre
	* Orina
	* Medular
  * Alergias
* Historial de citas
  * Fecha
  * Hora
* Historial de medicación
  * Medicamentos tomados con anterioridad
  * Receta en vigor

#### Requisitos funcionales (ordenados por prioridad)
1. Añadir nuevo paciente
  * Nombre
  * Apellidos
  * Teléfono
  * Dirección
  * Sexo
1. Eliminar a un paciente
1. Mostrar una lista de los pacientes
1. Buscar a un paciente por nombre y apellidos
1. Mostrar el historial de medicación de un paciente
  * Anterioridad
  * Actual
1. Mostrar el historial médico de un paciente
  * Enfermedades
  * Operaciones
  * Análisis
  * Alergias
1. Modificar datos de un paciente
1. Mostrar todas las citas previas de un paciente
  * Fecha
  * Hora
1. Añadir cita a un paciente
  * Fecha
  * Hora
1. Eliminar cita de un paciente

#### Requisitos no funcionales
* Sistema operativo Linux
* MS2
* Interfaz CLI (máquina de comandos)
* Lenguaje de implementación: C++
* Gran espacio de almacenamiento
