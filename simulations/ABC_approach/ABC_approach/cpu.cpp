#include "cpu.h"


using namespace std;

Cpu::Cpu() {
	busy = 0;
	busy_time = 0;
	idle_time = 0;
}

Cpu::~Cpu()
{
}

void Cpu::SetEndTime(int service_time)
	{
		end_time = service_time;
	}
int Cpu::GetEndTime()
{
	return end_time;
}

void Cpu::UpdateIdleTime(int time)
{
	idle_time += time;
}

void Cpu::UpdateBusyTime(int time)
{
	busy_time = time;
}

int Cpu::GetIdleTime()
{
	return idle_time;
}

int Cpu::GetBusyTime()
{
	return busy_time;
	
}


bool Cpu::IsBusy()
{
	return busy;
}

void Cpu::SetBusy()
{
	busy = true;
}

void Cpu::ResetBusy()
{
	busy = false;
	current = nullptr;
	end_time = -1;
}

void Cpu::Service(Process * temp)
{
	current = temp;
}

Process* Cpu::GetProcess()
{
	return current;

}
void Cpu::NullProc()
{
	end_time = -1;
}