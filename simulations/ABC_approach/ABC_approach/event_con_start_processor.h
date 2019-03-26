#pragma once
#include "process.h"
#include "event_con.h"
#ifndef ABCapproach_ABCapproach_event_con_start_processor_h_
#define ABCapproach_ABCapproach_event_con_start_processor_h_
class StartProcessor : public EventCon {
public:
	void Execute(CpuScheduler * cpus, FutureEventList* fel, int sim_time, bool & flag, bool mod ,int simulation_time,  int initial_time);
	StartProcessor();
	~StartProcessor();
private:
	
};
#endif
