#include <bits/stdc++.h>

using namespace std;

// Structure for every process
struct Process {
  int pid;      // Process ID
  int bt;       // Burst Time
  int art = 0;  // Arrival Time
};

void processesStruc(int np){
  //cout << "\n ";
    cout << "La estructura de cada proceso es la siguiente: \n";
    cout << "ID del proceso(No lo asigna el usuario), Tiempo de ejecución, Tiempo de llegada: \n";

    Process procArr[np];
    int burstT;
    int arrivalT;
    for (int i = 1; i <= np; i++){
      cout << "Por favor ingresa la información del Proceso: " << i << "\n";
      cout << "Burst Time: ";
      cin >> burstT;
      cout << "Arrival Time: ";
      cin >> arrivalT;
      //procArr[i-1].pid = i;
      //procArr[i-1].bt =  burstT;
      //procArr[i-1].art = arrivalT;
      //cout << procArr[i-1].pid << "\n";
      //cout << procArr[i-1].bt << "\n";
      //cout << procArr[i-1].art << "\n";
    }
    //cout << sizeof(procArr) << " and " << sizeof(procArr[0]) << "\n";
}

void sJF(){
  int nProcesses = -1;
  while (nProcesses < 0 || nProcesses > 10){
    cout << "Por favor ingrese el número de Procesos (Este debe de estar en un rango del 1-10): ";
  cin >> nProcesses;
  }
  processesStruc(nProcesses);
}

void menuProcesos(){
  int answer = 0;
  while (answer == 0){
    
    cout << "¿Qué algoritmo de Procesos quieres ejecutar? Digita el número de la opción:\n";
    cout << "1 - FCFS - First Come First Serve \n";
    cout << "2 - SJF - Shortest Job First Scheduling \n";
    cout << "3 - Priority(Non preemptive) - Tu decides la prioridad de los procesos ;) \n";
    cout << "4 - RR - Round Robin - Debes entrar el tiempo quamtum\n";
    cout << "5 - Todos los algoritmos en el orden establecido\n";
    cin >> answer; // User answer after asking for options
    
    if (answer ==  1){
    } else if (answer == 2){
      sJF();
    } else if (answer == 3){
    } else if (answer == 4){
    } else if (answer == 5){
    } else {
      answer = 0;
      cout << "Seleccione una opción válida. >:/ \n";
    }
  }
}

//int * menuMemoria(){}

int main(){

  int at;
  cout << "¿Qué tipo de algoritmo quieres usar? Digita el número de la opción:\n";
  cout << "1 - Algoritmos de Procesos\n";
  cout << "2 - Algortimos de Memoria\n";
  cout << "3 - Algoritmos de Planificación de Disco\n";
  cin >> at; // at: Algorithm Type

  if (at ==  1){
    menuProcesos();
  } else if (at == 2){
    cout << "En proceso... \n";
  } else {
    cout << "Lo lamentamos, esta opción no está disponible. :( \n";
  }

  return 0;
}
