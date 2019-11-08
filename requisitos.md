## Extracción de requisitos

#### Partes interesadas:
* Secretario
* Desarrolladores

#### Datos que gestiona el sistema:
* Pacientes
  * Nombre
  * Apellidos
  * Fecha de nacimiento
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
    - Nombre
	- Apellidos
	- Fecha de nacimiento
	- Teléfono
	- Dirección
	- Sexo
2. Eliminar a un paciente
3. Mostrar una lista de los pacientes
4. Buscar a un paciente por nombre y apellidos
5. Mostrar el historial médico de un paciente
    - Enfermedades
	- Operaciones
	- Análisis
	- Alergias
6. Modificar tratamiento actual de un paciente
7. Modificar datos de un paciente
8. Mostrar todas las citas previas de un paciente
    - Fecha
	- Hora
9. Añadir cita a un paciente
	- Fecha
	- Hora
10. Eliminar cita de un paciente
11. Añadir tratamiento a un paciente
12. Modificar cita de un paciente

#### Requisitos no funcionales
* Sistema operativo Linux
* Interfaz CLI (línea de comandos)
* Lenguaje de implementación: C++
* Estabilidad del software
* Rendimiento del software
* Pedir confirmación antes de borrar algún dato
* Evitar borrado de historial médico
