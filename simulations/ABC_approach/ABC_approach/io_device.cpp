#include "io_device.h"
IoDevice::IoDevice()
{

}

IoDevice::~IoDevice()
{
}
Process* IoDevice::GetProcess()
{
	return current;
}
void IoDevice::SetEndTime(int service_time)
{
	end_time = service_time;
}

int IoDevice::GetEndTime()
{
	return end_time;
}

bool IoDevice::IsBusyIo()
{
	return busy;
}

void IoDevice::SetBusyIo()
{
	busy = true;
}

void IoDevice::ResetBusyIo()
{
	busy = false;
	current = nullptr;
	end_time = -1;
}

void IoDevice::Service(Process * temp)
{
	current = temp;
}
