#pragma once
#ifndef ABCapproach_ABCapproach_process_h_
#define ABCapproach_ABCapproach_process_h_
class Process {
public:
	void ResetId();
	int GetId();
	int GetIot();
	int GetCet();
	int GetIoct();
	int GetIod();
	void Update();
	void UpdateIo(int ioct1);
	void UpdateIot(int iot1);
	void RandIod(int iod1);
	void UpdateCet(int cet1);
	void SetWaitingTime(int time);
	void SetFinalTime(int time);
	int GetWaitingTime();
	int GetFinalTime();
	void SetTurnaroundTime(int time);
	int GetTurnaroundTime();


	
	Process();
	~Process();
private:

	int id; 
	int cet; 
	int iot; 
	int ioct;
	int iod; 
	int waiting_time;
	int final_time;
	static int id_s;
	int turnaround_time;
};
#endif
