#pragma once
#include "event_con.h"
#include "process.h"
#ifndef ABCapproach_ABCapproach_event_con_start_io_h_
#define ABCapproach_ABCapproach_event_con_start_io_h_
class StartIo : public EventCon {
public:
	void Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool & flag, bool mod, int simulation_time, int initial_time);
	StartIo();
	~StartIo();
private:
	
};
#endif

