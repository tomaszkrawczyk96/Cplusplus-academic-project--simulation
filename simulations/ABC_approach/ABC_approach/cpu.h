#pragma once

#ifndef ABCapproach_ABCapproach_cpu_h_
#define ABCapproach_ABCapproach_cpu_h_
class Process;
class Cpu {
public:
	
	void UpdateIdleTime(int time);
	void UpdateBusyTime(int time);
	int GetIdleTime();
	int GetBusyTime();
	bool IsBusy();
	void SetBusy();
	void ResetBusy();
	void Service(Process * temp);
	Process* GetProcess();
	void NullProc();
	void SetEndTime(int service_time);
	int GetEndTime();

	Cpu();
	~Cpu();

	
private:
	bool busy;
	Process  * current;
	int end_time;
	int busy_time;
	int idle_time;
	
};
#endif