#pragma once
#ifndef ABCapproach_ABCapproach_io_queue_h_
#define ABCapproach_ABCapproach_io_queue_h_
#include <vector>
#include "generator.h"
#include "kernels.h"
using namespace std;
class Process;
class IoQueue {
public:
	int RandomPick();
	void Add(Process * process);
	void Remove(int random);
	Process* GetProcess( int random);
	void Zamien(Process* temp, int random);
	int GetSize();

	IoQueue(int i , Kernels * kernel);
	~IoQueue();
private:
	vector <Process*> io_queue;
	UniformGenerator* rand_rq; // used to get random process to the io device
};

#endif
