#pragma once
#include <vector>
#include "generator.h"
#include "kernels.h"

#ifndef ABCapproach_ABCapproach_cpu_queue_h_
#define ABCapproach_ABCapproach_cpu_queue_h_
class Process;
using namespace std;
class CpuQueue {
public:
	Process* Take();
	int GetSize();
	void Add(Process * process);
	void Remove();

	CpuQueue(int i,Kernels * kernel);
	~CpuQueue();
private:
	vector <Process*> ready_queue;
	UniformGenerator* rand_zo; // zero-one generator
	
};
#endif

