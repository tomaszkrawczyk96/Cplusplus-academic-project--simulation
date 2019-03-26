#include "event_con_start_io.h"
#include "cpu_scheduler.h"
#include "event_end_io.h"
#include "fel.h"
#include <iostream>
using namespace std;

StartIo::StartIo()
{
}  

StartIo::~StartIo()
{
}

void StartIo::Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool & flag, bool mod, int simulation_time, int initial_time)
{
	for (int i = 0; i < cpus->GetIoNumber(); i++) {
		if (!cpus->GetIo(i)->IsBusyIo())
		{
			if (cpus->GetIoQueue(i)->GetSize() > 0)
			{
				cpus->GetIo(i)->SetBusyIo();
				Process* temp; 
				int random = cpus->GetIoQueue(i)->RandomPick();
				temp = cpus->GetIoQueue(i)->GetProcess(random);
				cpus->GetIo(i)->Service(temp);
				cpus->GetIoQueue(i)->Remove(random);
				int service_time = temp->GetIot() + sim_time;
				cpus->GetIo(i)->SetEndTime(service_time);
				Event* end_of_io = new EndIo(service_time);
				fel->Add(end_of_io);
				
				if (mod == 1 && sim_time >= initial_time)
				{
					printf("");
					cin.ignore();
					printf("/////////////////////////////////////// \n");
					printf("obecny czas symulacji to: %i \n", sim_time);
					printf("proces o numerze %i zostal przypisany do urzadzenia i/o numer %i \n", temp->GetId(), i);
					printf("przewidywany czas zakonczenia pracy na urzadzeniu i/o numer %i to: %i \n", i, service_time);
					printf("\n");
				}
				flag = true;
				
			}

		}

	}
	
			

	}
