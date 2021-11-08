# Sistemas Operativos_Practica3 - 2021-2

## Autores: Andrés Darío Chaves Pérez y Pedro Quintero Longas

El objetivo de esta práctica es escribir un programa en C++ para simular los algoritmos que usa el sistema operativo para manejar los procesos, memoria (remplazo de páginas), y planificación del disco. Debido al cambio de fecha se puede seleccionar dos de las tres opciones anteriormente mencionadas.

### Especificaciones:
1. Ofrezca un menú claro para seleccionar entre los diferentes tipos de algoritmos.
2. Ofrezca un submenú para seleccionar entre los diferentes algoritmos que pertenecen a cada categoría:
   - Procesos: FCFS, SJF(Shortest Job First Scheduling), Priority (Non preemptive, el usuario define las prioridades), Round Robin (RR, el usuario puede entrar el quamtum). El programa debe solicitar el número de procesos (máximo10), solicitar la información para cada proceso (burst time, arrival time) y debe poder seleccionar si desea correr todos los algoritmos o uno en particular.
   - Y como resultado debe imprimir de una manera clara la siguiente información:
      - The waiting time and turnaround time para cada proceso (Tabla de información del proceso).
      - The average waiting time
      - The average turnaround time

   - Memoria: LRU (LeastRecentlyUsed), Optimal, FIFO(First In – First Out). El programa debe solicitar el número de marcos y la cadena de referencia (máx 20 páginas). Y como resultado debe imprimir PARA TODOS LOS ALGORITMOS la cantidad de page fault, asumiendo una paginación por demanda.

   - Planificación del disco: FCFS (First Come, First Served), SSF (Shortest Seek First), Scan (algoritmo del ascensor), C-Scan. El programa debe solicitar la posición inicial y la cola de solicitudes (10 solicitudes). Y como resultado debe imprimir PARA TODOS LOS ALGORITMOS de una manera clara la siguiente información:
     - La cadena con los movimientos realizados
     - La cantidad de movimientos realizados
