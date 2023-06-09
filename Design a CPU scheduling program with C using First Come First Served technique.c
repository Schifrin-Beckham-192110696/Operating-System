#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int burst_time;
  int completion_time;
  int turnaround_time;
} Process;

void schedule(Process *processes, int num_processes) {
  int i;
  processes[0].completion_time = processes[0].burst_time;
  for (i = 1; i < num_processes; i++) {
    processes[i].completion_time = processes[i-1].completion_time + processes[i].burst_time;
    processes[i].turnaround_time = processes[i].completion_time; // Activated at time 0
  }
}

int main() {
  int i, num_processes;
  Process processes[MAX_PROCESSES];
  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);
  for (i = 0; i < num_processes; i++) {
    printf("Enter burst time for process %d: ", i+1);
    scanf("%d", &processes[i].burst_time);
  }
  schedule(processes, num_processes);
  printf("Process\tBurst Time\tCompletion Time\tTurnaround Time\n");
  for (i = 0; i < num_processes; i++) {
    printf("%d\t\t%d\t\t%d\t\t\t%d\n", i+1, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time);
  }

  return 0;
}
