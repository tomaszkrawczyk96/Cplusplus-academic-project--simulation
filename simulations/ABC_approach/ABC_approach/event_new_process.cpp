#include "event_new_process.h"
#include "cpu_scheduler.h"
#include "process.h"
#include "fel.h"
#include <iostream>
#include <cstdlib>
using namespace std;
NewProcess::NewProcess(int etime) : Event(etime)
{
	
	
}

NewProcess::~NewProcess()
{
}

void NewProcess::Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool mod,int& lp, int& lzp, ofstream &plik,ostringstream &text_counter, int simulation_time, int initial_time)
{
	

	Process *process = new Process();
	
	cpus->SetGetCet(process);
	cpus->UpdateIoct(process);
	cpus->UpdateIot(process);
	PGT = cpus->SetGetPgt();
	cpus->GetCpuQueue()->Add(process); 
	process->SetTurnaroundTime(sim_time); // czas zycia procesu
	if ( sim_time >= initial_time)
	{
		


		lp++;
		process->SetWaitingTime(sim_time); //czas w kolejce
		
	}
	Event *  new_process = new NewProcess(PGT + sim_time); 
	fel->Add(new_process);
	if (mod == 1 && sim_time >=initial_time)
	{
		printf("");
		cin.ignore();
		printf("/////////////////////////////////////// \n");
		printf("obecny czas symulacji to: %i \n", sim_time);
		printf("czas przyjscia nowego procesu(numer %i) to: %i \n", process->GetId() + 1, PGT + sim_time);
		printf("\n");
	}
	
	
}


	