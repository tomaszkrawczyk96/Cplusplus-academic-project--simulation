#include "simulation.h"
#include "event.h"
#include "event_new_process.h"
#include "event_con_start_processor.h"
#include "fel.h"
#include "event_con.h"
#include "event_con_start_io.h"
#include "cpu_scheduler.h"
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

void Simulation::Simulate(FutureEventList * fel,bool mod, int simulation_time, int initial_time)
{
	// histogramy dla 10 symulacji (ka¿dy osobno)
	/*
	ostringstream text_counter_hist_un;
	text_counter_hist_un << "simulation_hist_un" << cpu_scheduler->GetI() << ".txt";

	ofstream plik_hist_un(text_counter_hist_un.str());
	plik_hist_un << "LICZBA;CZÊSTOTLIWOŒÆ \n";
	plik_hist_un.close();


	ostringstream text_counter_exp_pgt;
	text_counter_exp_pgt << "simulation_exp_pgt" << cpu_scheduler->GetI() << ".txt";

	ofstream plik_hist_exp(text_counter_exp_pgt.str());
	plik_hist_exp << "LICZBA;\n";
	plik_hist_exp.close();
	*/  

	ostringstream text_counter;
	text_counter << "process_waiting_time" << cpu_scheduler->GetI() << ".txt";

	ofstream plik(text_counter.str());
	plik << "ID;CZAS \n";
	plik.close();

	int lp = 0;
	int  lzp = 0;
	EventCon* start_processor = new StartProcessor() ; 
	EventCon* start_io = new StartIo(); 
	Event* new_process = new NewProcess(sim_time);
	fel->Add(new_process);
	do 
	{
		Event* e = fel->GetEvent();
		sim_time = e->GetEventTime();
		e->Execute(cpu_scheduler, fel, sim_time,mod,lp, lzp,plik,text_counter,simulation_time,initial_time);
		fel->Remove();
		bool no_event_trig;
		do
		{
			no_event_trig = false;
			start_processor->Execute(cpu_scheduler, fel, sim_time, no_event_trig,mod,simulation_time,initial_time); 
			start_io->Execute(cpu_scheduler, fel, sim_time, no_event_trig, mod,simulation_time,initial_time); 
		} while (no_event_trig==true);


	} while (sim_time < simulation_time);
	cpu_scheduler->GetCpu(0)->GetProcess()->ResetId();
	char c = '%'; 
	printf("**********************SYMULACJA NR #%i**********************\n", cpu_scheduler->GetI());
	printf("# Liczba utworzonych procesow-------------- %i              \n", lp);
	printf("# Liczba zakonczonych procesow------------- %i              \n", lzp);
	printf("# Czas w kolejce--------------------------- %i [ms]        \n", cpu_scheduler->GetTimeCounter());
	printf("# Sredni czas w kolejce to----------------- %f [ms]        \n",(double)  cpu_scheduler->GetTimeCounter() / (double)  lzp);
	printf("# Sredni czas zycia procesu to------------- %f [ms]        \n", (double)cpu_scheduler->GetTurnaround() / (double)lzp);

	ofstream stats3;
	stats3.open("mean_waiting.txt", ios::app);
	stats3 << (double)cpu_scheduler->GetTimeCounter() / (double)lzp << endl;
	stats3.close();
	
	for (int i = 0; i < 4; i++)
	{
		printf("# Uzycie procesora nr %i to----------------- %f %c		\n", i,(double) cpu_scheduler->GetCpu(i)->GetIdleTime() * 100 / (simulation_time-initial_time),c);
	}
	printf("# Throughput------------------------------- %f [proces/ms]  \n", (double)lzp / ((double)sim_time - (double) initial_time));
	printf("************************************************************\n");
	printf("\n");

	
	// histogramy dla 10 symulacji (ka¿dy osobno)
	/*
	for (int i = 0; i < 50; i++)
	{
		plik_hist_un.open(text_counter_hist_un.str(), ios_base::app);
		plik_hist_un << i +1<< ";" << cpu_scheduler->GetVector(i) << endl;;
		plik_hist_un.close();
	}
	for (int i = 0; i < cpu_scheduler->GetSizePgt(); i++)
	{
		plik_hist_exp.open(text_counter_exp_pgt.str(), ios_base::app);
		plik_hist_exp << cpu_scheduler->GetVectorPgt(i) << ";" << endl;;
		plik_hist_exp.close();
	}
	
	*/


	
}

Simulation::Simulation(CpuScheduler * cpus)
{
	cpu_scheduler = cpus;
	sim_time = 0;
}

Simulation::~Simulation()
{
}
