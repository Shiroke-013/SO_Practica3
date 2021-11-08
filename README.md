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

## Algoritmos de Programación de Procesos

### First Come First Serve (FCFS)
Este algortimo se ejecuta de la siguiente manera, el trabajo que llegó primero a la cola lista se asigna a la CPU y luego el trabajo que llegó en segundo lugar y así sucesivamente. Podemos decir que la cola lista actúa como una cola FIFO (primero en entrar, primero en salir), por lo que los trabajos / procesos que llegan se colocan al final de la cola. Este algoritmo está implementado de una manera *"Non-Preemptive"* lo que significa que cuando un proceso obtiene la CPU este no la libera hasta terminar.

1. Para la implementación de este algoritmo se utiliza una estructura (objeto) llamada *"Process"* que simula los componentes de un proceso y se tiene en cuenta el tiempo de llegada y el tiempo de ejecución, los cuales son escogidos por el usuario a la hora de ejecutar el algoritmo. El número de procesos y los tiempos mencionados son escogidos por el usuario.
2. Después de llenar la información de los procesos estos se organizan en un arreglo según su orden de llegada.
3. Como consecuente se simula el paso del tiempo con un *"for()"* y se va calculando el tiempo que espera cada proceso para ser empezado a ejecutar y el tiempo que se demora en ejecutarse completamente.
4. Finalmente se imprime la información de cada proceso y se hace el calculo del tiempo de espera promedio y del tiempo que se demoran en ejecutarse los procesos.

### Shortest Job First (SJF)
El trabajo más corto primero es un algoritmo de programación en el que se selecciona el proceso con el menor tiempo de ejecución para su ejecución a continuación. El trabajo más corto primero puede ser *"Preemptive"* o *"Non-Preemptive"*. Debido a su naturaleza simple, el trabajo más corto primero se considera óptimo. También reduce el tiempo medio de espera de otros procesos en espera de ejecución.

Este algoritmo también es conocido como *"Shortest Job Next"* (SJN) y *"Shortest Process Next"* (SPN).


### Priority
La programación de prioridades es un método de programación de procesos en función de la prioridad. En este método, el programador elige las tareas para trabajar según la prioridad, que es diferente de otros tipos de programación, por ejemplo, un simple round robin.

La programación de prioridades implica la asignación de prioridades a cada proceso, y los procesos con prioridades más altas se llevan a cabo primero, mientras que las tareas con prioridades iguales se llevan a cabo por orden de llegada (FCFS) o por turnos (RR).

La programación de prioridades puede ser cualquiera de las siguientes:

   - *"Preemptive"* (Preventivo): este tipo de programación puede adelantarse a la unidad central de procesamiento (CPU) en el caso de que la prioridad del proceso recién llegado sea mayor que la de los procesos existentes.
   - *"Non-Preemptive"* (No preventivo): este tipo de algoritmo de programación simplemente coloca el nuevo proceso en la parte superior de la cola lista.

1. Como se aclaró en las especificaciones este algoritmo está implementado de manera *"Non-Preemptive"* por lo cual es bastante parecido a FCFS, se utiliza la estructura de *"Process"* y se le pide al usuario que escoja el tiempo de llegada, el tiempo de ejecución y la prioridad de cada proceso.
2. Después, estos procesos se organizan de acuerdo a su prioridad en un arreglo siendo la prioridad más cercana a 0 la que se atiende primero.
3. Como consecuente se simula el paso del tiempo con un *"for()"* y se va calculando el tiempo que espera cada proceso para ser empezado a ejecutar y el tiempo que se demora en ejecutarse completamente.
4. Finalmente se imprime la información de cada proceso y se hace el calculo del tiempo de espera promedio y del tiempo que se demoran en ejecutarse los procesos.


### Round Robin (RR)
Round Robin (RR) es un algoritmo de programación de trabajos que se considera muy justo, ya que utiliza intervalos de tiempo que se asignan a cada proceso en la cola o línea. Luego, a cada proceso se le permite usar la CPU durante un período de tiempo determinado, y si no termina dentro del tiempo asignado, se reemplaza y luego se mueve al final de la línea para que el siguiente proceso en línea pueda usar la CPU durante la misma cantidad de tiempo.



## Referencias
- https://www.techopedia.com/definition/23455/first-come-first-served-fcfs
- https://www.techopedia.com/definition/22053/shortest-job-first-sjf
- https://www.techopedia.com/definition/21478/priority-scheduling
- https://www.techopedia.com/definition/9236/round-robin-scheduling-rrs
