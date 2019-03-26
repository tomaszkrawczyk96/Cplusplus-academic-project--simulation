#include "process.h"
#include "cpu_scheduler.h"
#include "event_end_io.h"
#include "fel.h"
#include <iostream>
using namespace std;

EndIo::EndIo(int etime) : Event(etime)
{
}

EndIo::~EndIo()
{
}

void EndIo::Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool mod, int& lp, int& zlp, ofstream &plik, ostringstream &text_counter, int simulation_time, int initial_time)
{
	
	for (int i = 0; i < cpus->GetIoNumber(); i++)
	{
		if (cpus->GetIo(i)->GetEndTime() == sim_time)
		{
			 cpus->UpdateIoct(cpus->GetIo(i)->GetProcess());
			 cpus->UpdateIot(cpus->GetIo(i)->GetProcess());
			cpus->GetCpuQueue()->Add(cpus->GetIo(i)->GetProcess());
			if (sim_time >= initial_time)
			{
				cpus->GetIo(i)->GetProcess()->SetWaitingTime(sim_time);
			}
			

			if (mod == 1 && sim_time >= initial_time)
			{
				printf("");
				cin.ignore();
				printf("/////////////////////////////////////// \n");
				printf("obecny czas symulacji to: %i \n", sim_time);
				printf("urzadzenie i/o o numerze %i zakonczyl prace z procesem o numerze %i \n", i, cpus->GetIo(i)->GetProcess()->GetId());
				printf("\n");
			}

			cpus->GetIo(i)->ResetBusyIo();
		}
	}

	

}
