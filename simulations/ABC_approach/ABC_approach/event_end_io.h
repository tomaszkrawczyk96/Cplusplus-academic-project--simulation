#pragma once
#include "event.h"
using namespace std;

#ifndef ABCapproach_ABCapproach_event_end_io_h_
#define ABCapproach_ABCapproach_event_end_io_h_
class EndIo : public Event {
public:
	void Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool mod, int& lp, int& zlp, ofstream &plik,ostringstream &text_counter, int simulation_time, int initial_time);
	EndIo(int etime);
	~EndIo();
private: 
	

};
#endif
