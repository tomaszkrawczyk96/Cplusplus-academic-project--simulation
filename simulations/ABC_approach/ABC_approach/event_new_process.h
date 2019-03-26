#pragma once
#include "event.h"
#include <cstdlib>
using namespace std;


#ifndef ABCapproach_ABCapproach_event_end_io_h_
#define ABCapproach_ABCapproach_event_end_io_h_
class NewProcess : public Event {
public: 
	void Execute(CpuScheduler * cpus, FutureEventList* fel,  int sim_time, bool mod, int& lp, int& zlp,ofstream &plik, ostringstream &text_counter, int simulation_time, int initial_time);
	NewProcess(int etime);
	~NewProcess();
private:
	
	int PGT; 

};
#endif
