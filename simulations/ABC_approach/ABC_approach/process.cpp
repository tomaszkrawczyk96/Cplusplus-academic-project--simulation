
#include <cstdlib>
#include "process.h" 

using namespace std;

int Process::id_s = 1;

Process::Process() {
	id = id_s++;
	waiting_time = 0;
	final_time = 0; 
	turnaround_time = 0;
}

Process::~Process() {

}

void Process::ResetId()
{
	id_s = 1;
}
int Process::GetId()
{
	return id;
}

int Process::GetIot()
{
	return iot;
}

int Process::GetCet()
{
	return cet;
}

int Process::GetIoct()
{
	return ioct;
}

int Process::GetIod()
{
	return iod;
}

void Process::Update()
{
	cet = cet - ioct;
}

void Process::UpdateIo(int ioct1)
{
	ioct = ioct1;
}

void Process::UpdateIot(int iot1)
{
	iot = iot1;
}

void Process::RandIod(int iod1)
{
	iod = iod1;
}

void Process::UpdateCet(int cet1)
{
	cet = cet1;
}

void Process::SetWaitingTime(int time)
{
	waiting_time = time;
}


void Process::SetFinalTime(int time)
{
	final_time += time;
}
int Process::GetWaitingTime()
{
	return waiting_time;
}
int Process::GetFinalTime()
{
	return final_time;
}
void Process::SetTurnaroundTime(int time)
{
	turnaround_time = time;
}

int Process::GetTurnaroundTime()
{
	return turnaround_time;
}

