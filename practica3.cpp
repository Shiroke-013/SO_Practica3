#include <bits/stdc++.h>

using namespace std;

//Structure for every process.
struct Process {
  int pid;      // Process ID
  int bt;       // Burst Time
  int art;      // Arrival Time
  int wt;       // Waiting Time
  int tat;      // Turnaround Time
  int pri = 0;  // Priority
};

void standardSort(Process procArr[], int nProcesses){
  //Organices the array in the order of process arrival
  Process aux;
  for (int i=0; i < nProcesses; i++){
    for (int j=i+1; j < nProcesses; j++){
      if (procArr[i].art > procArr[j].art){
	aux = procArr[i];
	procArr[i] = procArr[j];
	procArr[j] = aux;
      }
    }
  }
}

//Prints the information of each process.
void printAll(Process procArr[], int nProcesses, float avgWT, float avgTaT){
  cout << "Processes " << "   Burst time " << "   Arrival time" << "   Priority" << "   Waiting time " << "   Turn around time\n";
  for (int i = 1; i <= nProcesses; i++){
    cout << procArr[i-1].pid << "\t\t" << procArr[i-1].bt << "\t\t" << procArr[i-1].art << "\t\t" << procArr[i-1].pri << "\t\t" << procArr[i-1].wt << "\t\t" << procArr[i-1].tat << "\n";
  }
  cout << "Average Waiting time: " << avgWT/nProcesses << "\n";
  cout << "Average Turnaround time: " << avgTaT/nProcesses << "\n";
}

//Gets the number of Processes that are going to be created.
int getNumberOfProcesses(){
  int nProcesses = -1;
  while (nProcesses < 0 || nProcesses > 10){
    cout << "Por favor ingrese el número de Procesos (Este debe de estar en un rango del 1-10): ";
  cin >> nProcesses;
  }
  return nProcesses;
}

//Gets the information of each process.
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

    cout << "\n\n";
}

//Executes Shortest Job First Serve Algorithm.
void sJF(Process procArr[], int nProcesses){

  Process procArrAux[nProcesses];
  for (int i = 0; i < nProcesses; i++){
    procArrAux[i] = procArr[i];
  }
  
  cout << " \n\n SJF running.... \n";

  //Organices the array in the order of process arrival and burst time
  Process aux;
  for (int i=0; i < nProcesses; i++){
    for (int j=i+1; j < nProcesses; j++){
      if (procArrAux[i].art >= procArrAux[j].art && procArrAux[i].bt > procArrAux[j].bt){
	aux = procArrAux[i];
	procArrAux[i] = procArrAux[j];
	procArrAux[j] = aux;
      }
    }
  }
  
  int total_wt = 0, total_tat = 0;
  //Calculates Waiting Time and Turnaround Time of every Process
  int complete = 0;
  for (int time = 0; complete != nProcesses; time++){
    if((procArrAux[complete].bt + total_wt) == time){
      procArrAux[complete].wt = total_wt;
      procArrAux[complete].tat = total_wt + procArrAux[complete].bt;
      total_wt = total_wt + procArrAux[complete].bt;
      complete++;
      // When a process is complete, this loops check if another process arrives with smallest burst time.
      for (int i = complete; i < nProcesses; i++){
	for (int j = i+1; j < nProcesses; j++){
	  if (procArrAux[i].bt > procArrAux[j].bt && procArrAux[j].art <= time){
	    aux = procArrAux[i];
	    procArrAux[i] = procArrAux[j];
	    procArrAux[j] = aux;
	  }
	}
      }
    }
  }

  //Calculates Total Waiting Time and Total Turnaround Time
  float avgWT = 0, avgTaT = 0; 
  for(int i = 0; i < nProcesses; i++){
    avgWT = avgWT + procArrAux[i].wt;
    avgTaT = avgTaT + procArrAux[i].tat;
  }
  
  printAll(procArrAux, nProcesses, avgWT, avgTaT);
  
}

//Executes First Come First Serve Algorithm.
void firstCFS(Process procArr[], int nProcesses){

  cout << "\n\n FCFS running.... \n";

  int total_wt = 0, total_tat = 0;

  standardSort(procArr, nProcesses);

  //Calculates Waiting Time and Turnaround Time of every Process
  int complete = 0;
  for (int time = 0; complete != nProcesses; time++){
    if((procArr[complete].bt + total_wt) == time){
      procArr[complete].wt = total_wt;
      procArr[complete].tat = total_wt + procArr[complete].bt;
      total_wt = total_wt + procArr[complete].bt;
      complete++;
    }
  }

  //Calculates Total Waiting Time and Total Turnaround Time
  float avgWT = 0, avgTaT = 0; 
  for(int i = 0; i < nProcesses; i++){
    avgWT = avgWT + procArr[i].wt;
    avgTaT = avgTaT + procArr[i].tat;
  }

  printAll(procArr, nProcesses, avgWT, avgTaT);
  
}

void priority(Process procArr[], int nProcesses){

  Process procArrAux[nProcesses];
  for (int i = 0; i < nProcesses; i++){
    procArrAux[i] = procArr[i];
  }
  
  cout << "\n\n Priority running.... \n";
  int priority = 0;
  cout << "A continuación ingresarás la prioridad de cada proceso, recuerda que esta entre más cerca esté del 0 más prioridad tendrá \n";
  for (int i = 0; i < nProcesses; i++){
    cout << "Ingresa la prioridad del proceso " << i+1 << ": ";
    cin >> priority;
    if(priority < 0 || priority > 139){
      cout << "Por favor ingresa un valor que se encuentre entre 0-139\n";
      i--;
    } else {
      procArrAux[i].pri = priority;
    }
  }

  //Organices the array in the order of process arrival
  Process aux;
  for (int i=0; i < nProcesses; i++){
    for (int j=i+1; j < nProcesses; j++){
      if (procArrAux[i].art >= procArrAux[j].art && procArrAux[i].pri > procArrAux[j].pri){
	aux = procArrAux[i];
	procArrAux[i] = procArrAux[j];
	procArrAux[j] = aux;
      }
    }
  }

  //Calculates Waiting Time and Turnaround Time OBof every Process
  int total_wt = 0, total_tat = 0, complete = 0;
  for (int time = 0; complete != nProcesses; time++){
    if((procArrAux[complete].bt + total_wt) == time){
      procArrAux[complete].wt = total_wt;
      procArrAux[complete].tat = total_wt + procArrAux[complete].bt;
      total_wt = total_wt + procArrAux[complete].bt;
      complete++;
      // When a process is complete, this loops check if another process arrives with higher priority arrives in the correct time.
      for (int i = complete; i < nProcesses; i++){
	for (int j = i+1; j < nProcesses; j++){
	  if (procArrAux[i].pri > procArrAux[j].pri && procArrAux[j].art <= time){
	    aux = procArrAux[i];
	    procArrAux[i] = procArrAux[j];
	    procArrAux[j] = aux;
	  }
	}
      }
    }
  }

  //Calculates Total Waiting Time and Total Turnaround Time
  float avgWT = 0, avgTaT = 0; 
  for(int i = 0; i < nProcesses; i++){
    avgWT = avgWT + procArrAux[i].wt;
    avgTaT = avgTaT + procArrAux[i].tat;
  }

  printAll(procArrAux, nProcesses, avgWT, avgTaT);
}

void roundRobin(Process procArr[], int nProcesses){
  
  cout << "\n\n Round Robin running.... \n";
  
  int quantum = 0;
  while(quantum == 0){
    cout << "Ingresa por favor el tiempo quantum para este algoritmo: ";
    cin >> quantum;
    if(quantum <= 0){
      cout << "Por favor ingresa un valor que sea mayor a 0";
      quantum = 0;
    }
  }

  standardSort(procArr, nProcesses);

  //Copies the burst time of each process into an array
  int completeP[10] = {0};
  int btp[nProcesses];
  for (int i = 0; i < nProcesses; i++){
    btp[i] = procArr[i].bt;
  }
  
  int total_wt = 0, total_tat = 0, complete = 0, completeAux = 0, count = 0;
  //Calculates Turnaround Time of every Process
  for (int time = 0; complete != nProcesses; time++){
    if (completeP[completeAux] == 1){
      completeAux++;
      time--;
    } else {

      if (btp[completeAux] <= quantum && completeP[completeAux] == 0){
	completeP[completeAux] = 1;
	time = time + (btp[completeAux]-1);
	procArr[completeAux].tat = time;
	count = 0;
	btp[completeAux] = 0;
	completeAux++;
	complete++;
	/* We need to check every time the quantum time ends if the next processes already arrived*/
	if (procArr[completeAux].art > time && completeAux < nProcesses){
	  completeAux = completeAux - completeAux;
	}
      } else if(count == quantum){
	count = 0;
        procArr[completeAux].tat = time;
	btp[completeAux] = btp[completeAux] - quantum;;
	if (btp[completeAux] == 0){
	  complete++;
	}
	completeAux++;
	/* We need to check every time the quantum time ends if the next processes already arrived*/
	if(procArr[completeAux].art > time && completeAux < nProcesses){
	  completeAux = completeAux - completeAux;
	}
      }
      
      /* If the completeAux equals the number of Precceses it means that we already are at the last position of the array and we need to startover*/
      if (completeAux == nProcesses){
	completeAux = 0;
      }
      count++;
    }
  }
  
  // Calculates Waiting Time for each Process.
  for(int i = 0; i < nProcesses; i++){
    procArr[i].wt = procArr[i].tat - procArr[i].bt;
  }
  
  //Calculates Total Waiting Time and Total Turnaround Time
  float avgWT = 0, avgTaT = 0; 
  for(int i = 0; i < nProcesses; i++){
    avgWT = avgWT + procArr[i].wt;
    avgTaT = avgTaT + procArr[i].tat;
  }
  printAll(procArr, nProcesses, avgWT, avgTaT);
  
}

void processMenu(){
  int answer = 0;
  while (answer == 0){
    
    cout << "¿Qué algoritmo de Procesos quieres ejecutar? Digita el número de la opción:\n";
    cout << "1 - FCFS - First Come First Serve \n";
    cout << "2 - SJF - Shortest Job First Scheduling \n";
    cout << "3 - Priority(Non preemptive) - Tu decides la prioridad de los procesos ;) \n";
    cout << "4 - RR - Round Robin - Tu decides el tiempo quamtum ;) \n";
    cout << "5 - Todos los algoritmos en el orden establecido\n";
    cin >> answer; // User answer after asking for options

    if (answer == 1 || answer == 2 || answer == 3 || answer == 4 || answer == 5){
    } else {
      answer = 0;
      cout << "Seleccione una opción válida. >:/ \n\n";
    }
  }

  int nProcesses = getNumberOfProcesses();
  Process procArr[nProcesses];
  processesStruc(procArr, nProcesses);
    
    if (answer ==  1){
      firstCFS(procArr, nProcesses);
    } else if (answer == 2){
      sJF(procArr, nProcesses);
    } else if (answer == 3){
      priority(procArr, nProcesses);
    } else if (answer == 4){
      roundRobin(procArr, nProcesses);
    } else if (answer == 5){
      firstCFS(procArr, nProcesses);
      sJF(procArr, nProcesses);
      priority(procArr, nProcesses);
      roundRobin(procArr, nProcesses);
      cout << "Se han ejecutado todos los algoritmos XD... \n";
    } else {}
}

int main(){

  int at = 0;
  while (at == 0){
    cout << "¿Qué tipo de algoritmo quieres usar? Digita el número de la opción:\n";
    cout << "1 - Algoritmos de Procesos\n";
    cout << "2 - Algortimos de Memoria\n";
    cout << "3 - Algoritmos de Planificación de Disco\n";
    cout << "4 - Salir del programa\n";
    cin >> at; // at: Algorithm Type

    if (at ==  1){
      processMenu();
    } else if (at == 2){
      cout << "En proceso... \n";
    } else if (at == 3){
      at = 0;
      cout << "Lo lamentamos esta opción no está disponible \n\n\n";
    } else if (at == 4){
      exit(0);
    } else {
      at = 0;
      cout << "Seleccione una opción válida. >:/ \n";
    }
  }

  return 0;
}
