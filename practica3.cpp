#include <bits/stdc++.h>

using namespace std;

// Structure for every process
struct Process {
  int pid;      // Process ID
  int bt;       // Burst Time
  int art = 0;  // Arrival Time
  int wt;
  int tat;
};

void printAll(Process procArr[], int nProcesses){
  cout << "Processes " << "   Burst time " << "   Arrival time" << "   Waiting time " << "   Turn around time\n";
  for (int i = 1; i <= nProcesses; i++){
    cout << procArr[i-1].pid << "\t\t" << procArr[i-1].bt << "\t\t" << procArr[i-1].art << "\t\t" << procArr[i-1].wt << "\t\t" << procArr[i-1].tat << "\n";
  }
}

int getNumberOfProcesses(){
  int nProcesses = -1;
  while (nProcesses < 0 || nProcesses > 10){
    cout << "Por favor ingrese el número de Procesos (Este debe de estar en un rango del 1-10): ";
  cin >> nProcesses;
  }
  return nProcesses;
}

void processesStruc(Process procArr[], int np){

    cout << "La estructura de cada proceso es la siguiente: \n";
    cout << "ID del proceso(No lo asigna el usuario), Tiempo de ejecución, Tiempo de llegada: \n";
    
    int burstT;
    int arrivalT;
    for (int i = 1; i <= np; i++){
      cout << "Por favor ingresa la información del Proceso: " << i << "\n";
      cout << "Burst Time: ";
      cin >> burstT;
      cout << "Arrival Time: ";
      cin >> arrivalT;
      procArr[i-1].pid = i;
      procArr[i-1].bt =  burstT;
      procArr[i-1].art = arrivalT;
    }
}

/*void waitingTimeSFJ(Process procArr[], int np, int wt[]){
  int runningT = 0;
  int completeP = 0;
  for (int time = 0; completeP != np; time++){
    
  }
  
}*/

void sJF(){
  
  int nProcesses = getNumberOfProcesses();
  
  Process procArr[nProcesses];
  processesStruc(procArr, nProcesses);

  int wt[nProcesses], tat[nProcesses], total_wt = 0, total_tat = 0;

  //waitingTimeSJF(procArr, nProcesses, wt);
  
  for (int i = 1; i <= nProcesses; i++){
      cout << procArr[i-1].pid << "\n";
      cout << procArr[i-1].bt << "\n";
      cout << procArr[i-1].art << "\n";
    }
}

void firstCFS(){

  int nProcesses = getNumberOfProcesses();
  Process procArr[nProcesses];
  processesStruc(procArr, nProcesses);

  cout << "FCFS running.... \n";

  int wt[nProcesses], tat[nProcesses], total_wt = 0, total_tat = 0;
  
  Process aux;
  for (int i=0; i < nProcesses; i++){
    for (int j=i+1; j < nProcesses; j++){
      //cout << "I: " << i << " and J: " << j << "\n";
      //cout << "Arrival Times: "<< procArr[i].art << "-------" << procArr[j].art << "\n";
      if (procArr[i].art > procArr[j].art){
	aux = procArr[i];
	//cout << "Aux Variable: " << aux.pid << "\n";
	procArr[i] = procArr[j];
	procArr[j] = aux;
      }
    }
  }

  int complete = 0;
  for (int time = 0; complete != nProcesses; time++){
    if((procArr[complete].bt + total_wt) == time){
      procArr[complete].wt = total_wt;
      procArr[complete].tat = total_wt + procArr[complete].bt;
      total_wt = total_wt + procArr[complete].bt;
      complete++;
    }
  }
  
  printAll(procArr, nProcesses);
  
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
      firstCFS();
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
