# Sistemas Operativos_Practica3 - 2021-2

## Autores: Andrés Darío Chaves Pérez y Pedro Quintero Longas

El objetivo de esta práctica es escribir un programa en C++ para simular los algoritmos que usa el sistema operativo para manejar los procesos, memoria (remplazo de páginas), y planificación del disco. Debido al cambio de fecha se puede seleccionar dos de las tres opciones anteriormente mencionadas.

### Especificaciones:
1. Ofrezca un menú claro para seleccionar entre los diferentes tipos de algoritmos.
2. Ofrezca un submenú para seleccionar entre los diferentes algoritmos que pertenecen a cada categoría:
   - **Procesos:** FCFS, SJF(Shortest Job First Scheduling), Priority (Non preemptive, el usuario define las prioridades), Round Robin (RR, el usuario puede entrar el quamtum). El programa debe solicitar el número de procesos (máximo10), solicitar la información para cada proceso (burst time, arrival time) y debe poder seleccionar si desea correr todos los algoritmos o uno en particular.
   - Y como resultado debe imprimir de una manera clara la siguiente información:
      - The waiting time and turnaround time para cada proceso (Tabla de información del proceso).
      - The average waiting time
      - The average turnaround time

   - **Memoria:** LRU (LeastRecentlyUsed), Optimal, FIFO(First In – First Out). El programa debe solicitar el número de marcos y la cadena de referencia (máx 20 páginas). Y como resultado debe imprimir PARA TODOS LOS ALGORITMOS la cantidad de page fault, asumiendo una paginación por demanda.

   - **Planificación del disco:** FCFS (First Come, First Served), SSF (Shortest Seek First), Scan (algoritmo del ascensor), C-Scan. El programa debe solicitar la posición inicial y la cola de solicitudes (10 solicitudes). Y como resultado debe imprimir PARA TODOS LOS ALGORITMOS de una manera clara la siguiente información:
     - La cadena con los movimientos realizados
     - La cantidad de movimientos realizados

## Algoritmos de Procesos

### First Come First Serve (FCFS)
Este algortimo se ejecuta de la siguiente manera, el trabajo que llegó primero a la cola lista se asigna a la CPU y luego el trabajo que llegó en segundo lugar y así sucesivamente. Podemos decir que la cola lista actúa como una cola FIFO (primero en entrar, primero en salir), por lo que los trabajos / procesos que llegan se colocan al final de la cola. Este algoritmo está implementado de una manera *"Non-Preemptive"* lo que significa que cuando un proceso obtiene la CPU este no la libera hasta terminar.

- Para la implementación de este algoritmo se utiliza una estructura (objeto) que simula los componentes de un proceso y se tiene en cuenta el tiempo de llegada y el tiempo de ejecución, los cuales son escogidos por el usuario a la hora de ejecutar el algoritmo.
- Después de llenar la información de los procesos estos se organizan en un arreglo según su orden de llegada.
- Como consecuente se simula el paso del tiempo con un *"for()"* y se va calculando el tiempo que espera cada proceso para ser empezado a ejecutar y el tiempo que se demora en ejecutarse completamente.
- Finalmente se imprime la información de cada proceso y se hace el calculo del tiempo de espera promedio y del tiempo que se demoran en ejecutarse los procesos.

### Shortest Job First Serve (SJFS)
