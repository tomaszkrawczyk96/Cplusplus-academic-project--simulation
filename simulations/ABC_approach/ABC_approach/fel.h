#pragma once
#include <vector>
#include "generator.h"
#include "kernels.h"
#ifndef ABCapproach_ABCapproach_fel_h_
#define ABCapproach_ABCapproach_fel_h_
class Event;
using namespace std;
class FutureEventList {
public:
	void Add(Event* ev);
	Event* GetEvent();
	void Remove();
	FutureEventList(Kernels* kernel, int i );
	~FutureEventList();
private:
	vector <Event *> fel;
	UniformGenerator* rand_zo;

};
#endif
