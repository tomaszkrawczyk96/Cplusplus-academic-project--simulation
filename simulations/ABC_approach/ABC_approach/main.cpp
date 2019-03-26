#include <iostream>
#include "cpu_scheduler.h"
#include <vector>
#include "fel.h"
#include "simulation.h"
#include "kernels.h"
#include "generator.h"


using namespace std;

void main()
{
	remove("mean_waiting.txt");
	remove("uniform.txt");
	remove("exponential.txt");
	Kernels * kernel = new Kernels();
	//kernel->GenerateKernels("seed.txt"); // generowanie seed'ów 
	kernel->ReadKernels("seed.txt");
	
	int simulation_time;
	int initial_time = 0;
	double lambda;
	bool mod;
	bool initial_phase;
	printf("Podaj czas symulacji: \n");
	cin >> simulation_time;
	printf("Podaj wartosc lambdy: \n");
	cin >> lambda;
	printf("Wybierz tryb dzialania: 0 - continuous | 1 - step by step \n");
	cin >> mod;
	printf("Ustaw initial phase : 0 - nie | 1 - tak \n");
	cin >> initial_phase;
	if (initial_phase == true)
	{
		initial_time = 1150;
	}
	for (int i = 0; i < 10; i++)
	{
	
	 
	CpuScheduler* a = new CpuScheduler(kernel,i,lambda);
	FutureEventList* b = new FutureEventList(kernel,i);
	Simulation* sim = new Simulation(a);
	sim->Simulate(b,mod,simulation_time,initial_time);
	delete a;
	}
	


	
	
	system("pause");
	
}