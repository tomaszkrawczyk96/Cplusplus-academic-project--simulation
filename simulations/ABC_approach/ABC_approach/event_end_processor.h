#pragma once
#include "event.h"
#include <sstream>
#include <fstream>
using namespace std;
#ifndef ABCapproach_ABCapproach_event_end_io_h_
#define ABCapproach_ABCapproach_event_end_io_h_
class CpuScheduler;
class Process;
class EndProcessor : public Event {
public:
	void Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool mod, int& lp, int& lzp,ofstream &plik, ostringstream &text_counter, int simulation_time, int initial_time);
	EndProcessor(int etime);                                                                                                    
	~EndProcessor();
private:
	
};
#endif
