#include "event_end_processor.h"
#include "process.h"
#include "cpu_scheduler.h"
#include "fel.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


EndProcessor::EndProcessor(int etime) : Event(etime)
{
	
}

EndProcessor::~EndProcessor()
{
}

void EndProcessor::Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool mod, int& lp, int& lzp, ofstream &plik, ostringstream &text_counter, int simulation_time, int initial_time)
{
	
	for (int i = 0; i < cpus->GetCpuNumber(); i++)
	{
		if (cpus->GetCpu(i)->GetEndTime() == sim_time)
		{
		cpus->UpdateIod(cpus->GetCpu(i)->GetProcess());

	
		
			int number = cpus->GetCpu(i)->GetProcess()->GetIod(); 
			cpus->GetCpu(i)->GetProcess()->Update();
			
			if (mod == 1 && sim_time >=initial_time)
			{
				printf("");
				cin.ignore();
				printf("/////////////////////////////////////// \n");
				printf("obecny czas symulacji to: %i \n", sim_time);
				printf("procesor o numerze %i zakonczyl prace z procesem o numerze %i \n", i, cpus->GetCpu(i)->GetProcess()->GetId());
				printf("\n");
			}


			if (cpus->GetCpu(i)->GetProcess()->GetIoct() == 0)
			{
				cpus->GetCpu(i)->GetProcess()->SetTurnaroundTime(sim_time - cpus->GetCpu(i)->GetProcess()->GetTurnaroundTime());
				if (sim_time >= initial_time)
				{

				

					/* // do spisywania turnaround dla kazdego procesu osobno
					plik.open(text_counter.str(), ios_base::app);
					plik << cpus->GetCpu(i)->GetProcess()->GetId() << ";" << cpus->GetCpu(i)->GetProcess()->GetTurnaroundTime() << endl;
					plik.close();
					*/
					cpus->SetTimeCounter(cpus->GetCpu(i)->GetProcess()->GetFinalTime());

					/* // do spisywania waiting time dla kazdego procesu osobno
					plik.open(text_counter.str(), ios_base::app);
					plik << cpus->GetCpu(i)->GetProcess()->GetId() << ";" << cpus->GetCpu(i)->GetProcess()->GetFinalTime() << endl;
					plik.close();
					*/
					
					cpus->SetTurnaround(cpus->GetCpu(i)->GetProcess()->GetTurnaroundTime());


					/* // wypisywanie turnaround dla 10000 procesów
					if (cpus->GetCpu(i)->GetProcess()->GetId() >= 1000 && cpus->GetCpu(i)->GetProcess()->GetId() < 2000)
					{
						ofstream stats; 
						stats.open("turnaround_matlab.txt", ios::app);
						stats << cpus->GetCpu(i)->GetProcess()->GetId() <<";" << cpus->GetCpu(i)->GetProcess()->GetTurnaroundTime() << endl;
						stats.close();
						
					}
					*/

					lzp++;
				}
			
				
				delete cpus->GetCpu(i)->GetProcess();
				
				
			}
			else
			{
				cpus->GetIoQueue(number)->Add(cpus->GetCpu(i)->GetProcess());
			}
			
			cpus->GetCpu(i)->ResetBusy();
		
		}
	}
	
	
	
}
