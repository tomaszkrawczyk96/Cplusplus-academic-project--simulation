#pragma once
#ifndef ABCapproach_ABCapproach_io_device_h_
#define ABCapproach_ABCapproach_io_device_h_
class Process;
class IoDevice {
public:
	bool IsBusyIo();
	void SetBusyIo();
	void ResetBusyIo();
	void Service(Process* temp);
	void SetEndTime(int service_time);
	int GetEndTime();
	Process* GetProcess();

	IoDevice();
	~IoDevice();
	
private:
	bool busy;
	Process * current;
	int end_time;
};
#endif