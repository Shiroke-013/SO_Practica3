#include <bits/stdc++.h>

using namespace std;

// Structure for every process
struct Process {
  int pid;      // Process ID
  int bt;       // Burst Time
  int art = 0; // Arrival Time
};

void menuProcesos(){

  int answer;
  cout << "¿Qué algoritmo de Procesos quieres ejecutar? Digita el número de la opción:\n";
  cout << "1 - FCFS - First Come First Serve \n";
  cout << "2 - SJF - Shortest Job First Scheduling \n";
  cout << "3 - Priority(Non preemptive) - Tu decides la prioridad de los procesos ;) \n";
  cout << "4 - RR - Round Robin - Debes entrar el tiempo quamtum\n";
  cin >> answer;
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
