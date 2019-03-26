#pragma once
class Process;
class FutureEventList;
#ifndef ABCapproach_ABCapproach_event_con_h_
#define ABCapproach_ABCapproach_event_con_h_
class CpuScheduler;
using namespace std;
class EventCon {
public:
	virtual void Execute(CpuScheduler * cpus, FutureEventList * fel,  int sim_time, bool &flag , bool mod, int simulation_time, int initial_time) = 0;
	EventCon();
	~EventCon();
protected:
	int event_time;

};
#endif

