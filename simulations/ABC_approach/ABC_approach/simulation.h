#pragma once
class CpuScheduler; 
class FutureEventList;

#ifndef ABCapproach_ABCapproach_simulation_h_
#define ABCapproach_ABCapproach_simulation_h_
class Simulation
{
public:
	void Simulate(FutureEventList * fel, bool mod,int simulation_time,int initial_time);

	Simulation(CpuScheduler *cpus);
	~Simulation();

private:
	CpuScheduler* cpu_scheduler;
	int sim_time;
	bool no_event_trig;
	
};
#endif
