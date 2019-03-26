#pragma once
#include <vector>
#include "cpu.h"
#include "io_device.h"
#include "io_queue.h"
#include "cpu_queue.h"
#include "event.h"
#include "kernels.h"
#include "generator.h"
#include "process.h"
#include <sstream>
#include <fstream>

#ifndef ABCapproach_ABCapproach_cpu_scheduler_h_
#define ABCapproach_ABCapproach_cpu_scheduler_h_
using namespace std;




class CpuScheduler {
public:
	Cpu* GetCpu(int i);
	IoDevice* GetIo(int i);
	int GetCpuNumber();
	int GetIoNumber();
	CpuQueue* GetCpuQueue();
	IoQueue* GetIoQueue(int i);
	void UpdateIoct(Process * process);
	void UpdateIot(Process * process);
	void UpdateIod(Process * process);
	int GetI();
	void UpdateHistUn(int x);
	void UpdateHistPgt(int x);
	int GetSizePgt();
	int GetVectorPgt(int x);
	void SetTurnaround(int x);
	int GetTurnaround();
	int SetGetPgt();
	void SetGetCet(Process * process);
	void SetTimeCounter(int time);
	long int GetTimeCounter();
	int GetVector(int i);

	CpuScheduler(Kernels * kernel, int i,double lambda);
	~CpuScheduler();
private:
	UniformGenerator* rand_cet;
	UniformGenerator* rand_ioct;
	UniformGenerator* rand_iot;
	UniformGenerator* rand_iod;
	UniformGenerator* rand_pgt;
	ExpGenerator* exp_pgt;
	const int number_p; 
	const int number_io;
	vector <Cpu*> processors; 
	vector <IoDevice*> io_devices; 
	CpuQueue *cpu_queue; 
	vector<IoQueue*> io_queue; 
	int sim_counter;
	long int time_counter;
	vector <int> cet_hist;
	vector <int> pgt_hist;
	long int turnaround_counter;

};
#endif
