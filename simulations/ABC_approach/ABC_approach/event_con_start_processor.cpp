#include "event_con_start_processor.h"
#include "cpu_scheduler.h"
#include "event_end_processor.h"
#include "fel.h"
#include <iostream>
using namespace std;
StartProcessor::StartProcessor()
{ 
}

StartProcessor::~StartProcessor()
{
}

void StartProcessor::Execute(CpuScheduler * cpus, FutureEventList* fel,  int sim_time, bool & flag, bool mod, int simulation_time, int initial_time)
{
	for (int i = 0; i < cpus->GetCpuNumber(); i++) {
		if (!cpus->GetCpu(i)->IsBusy())
		{
		
			if (cpus->GetCpuQueue()->GetSize() > 0)
			{
				Process *temp;
				cpus->GetCpu(i)->SetBusy();
				temp = cpus->GetCpuQueue()->Take();
				cpus->GetCpu(i)->Service(temp); 
				cpus->GetCpuQueue()->Remove(); 
				
				int service_time;
				if (temp->GetIoct() > 0)
					 service_time = temp->GetIoct() + sim_time;
				else
					service_time = temp->GetCet() + sim_time;
				
				cpus->GetCpu(i)->SetEndTime(service_time);
				Event *  end_of_processor = new EndProcessor(service_time);
				fel->Add(end_of_processor);

				if (sim_time >= initial_time)
				{
					temp->SetFinalTime(sim_time - temp->GetWaitingTime());
					if (service_time < simulation_time) 
					{
						cpus->GetCpu(i)->UpdateBusyTime(service_time - sim_time);
						cpus->GetCpu(i)->UpdateIdleTime(cpus->GetCpu(i)->GetBusyTime());
					}
				
					else
					{
						cpus->GetCpu(i)->UpdateBusyTime(simulation_time - sim_time);
						cpus->GetCpu(i)->UpdateIdleTime(cpus->GetCpu(i)->GetBusyTime());
					}
				}
				
					

				if (mod == 1 && sim_time >= initial_time)
				{
					printf("");
					cin.ignore();
					printf("/////////////////////////////////////// \n");
					printf("obecny czas symulacji to: %i \n", sim_time);
					printf("proces o numerze %i zostal przypisany do procesora numer %i \n", temp->GetId() ,i);
					printf("przewidywany czas zakonczenia pracy na procesorze numer %i to: %i \n", i, service_time);
					printf("\n");
				}
				
				flag = true;
			

				
				
				
				
			}	

		}

		
	}
	
	
}
