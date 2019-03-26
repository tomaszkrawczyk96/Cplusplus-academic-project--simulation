#pragma once
class Process;
class FutureEventList;
#include <sstream>
#include <fstream>
#ifndef ABCapproach_ABCapproach_event_h_
#define ABCapproach_ABCapproach_event_h_
class CpuScheduler; 
using namespace std;
class Event {
public:
	virtual void Execute(CpuScheduler * cpu, FutureEventList* fel, int sim_time, bool mod, int& lp,int& lzp, ofstream &plik, ostringstream &text_counter, int simulation_time,int initial_time) = 0;
	int GetEventTime();
	Event(int etime);
	~Event();
protected:
	int event_time;

};
#endif
