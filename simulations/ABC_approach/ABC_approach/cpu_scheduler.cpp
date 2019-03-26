#include "cpu_scheduler.h"



CpuScheduler::CpuScheduler(Kernels * kernel,int i, double lambda) : number_p(4), number_io(5) {

	 
	cet_hist.resize(50, 0);



	for	(int p = 0; p < number_p; p++) {
		processors.push_back(new Cpu());
	
	}
	
	for (int d = 0; d < number_io; d++)
	{
		IoDevice *io_device = new IoDevice();
		io_devices.push_back(io_device);


		 io_queue.push_back(new IoQueue(i,kernel));
	}
		
	cpu_queue = new CpuQueue(i,kernel);
	
	 rand_cet = new UniformGenerator(kernel->GetKernel(kernel->TPW, i)); 
	 rand_ioct = new UniformGenerator(kernel->GetKernel(kernel->TPIO, i));
	 rand_iot = new UniformGenerator(kernel->GetKernel(kernel->TPO, i));
	 rand_iod = new UniformGenerator(kernel->GetKernel(kernel->TPD, i));
	 rand_pgt = new UniformGenerator(kernel->GetKernel(kernel->TPG, i));
	 exp_pgt = new ExpGenerator(lambda, rand_pgt);

	 sim_counter = i;
	 time_counter = 0;
	 turnaround_counter = 0;

}



CpuScheduler::~CpuScheduler()
{
}

void CpuScheduler::SetTimeCounter(int time)
{
	time_counter += time;
}

long int CpuScheduler::GetTimeCounter()
{
	return time_counter;
}

int CpuScheduler::GetVector(int i)
{
	return cet_hist[i];
}

Cpu * CpuScheduler::GetCpu(int i)
{
	return processors[i];
}

IoDevice * CpuScheduler::GetIo(int i)
{
	return io_devices[i];
}

int CpuScheduler::GetCpuNumber()
{
	return number_p;
}

int CpuScheduler::GetIoNumber()
{
	return number_io;
}

CpuQueue * CpuScheduler::GetCpuQueue()
{
	return cpu_queue;
}

IoQueue * CpuScheduler::GetIoQueue(int i)
{
	return io_queue[i];
}

int CpuScheduler::SetGetPgt()
{
	int x = (int) exp_pgt->Rand();
		return x;
	
}
void CpuScheduler::SetGetCet(Process * process)
{
	int x = (int)rand_cet->Rand(1, 51);
	process->UpdateCet(x);
	
}
void CpuScheduler::UpdateIoct(Process * process)
{
	int x =  process->GetCet();
	int y = (int) rand_ioct->Rand(0, x);
	process->UpdateIo(y);
}
void CpuScheduler::UpdateIot(Process * process)
{
	int w;
	if (process->GetIoct() > 0)
	{
		w = (int)rand_iot->Rand(1,11);
	}
	else
	{
		w = 0;
	}
		process->UpdateIot(w);
}
void CpuScheduler::UpdateIod(Process * process)
{
	int x = (int) rand_iod->Rand(0, number_io);
	process->RandIod(x);
}
int CpuScheduler::GetI()
{
	return sim_counter;
}
void CpuScheduler::UpdateHistUn(int x)
{
	cet_hist[x - 1] += 1;
}
void CpuScheduler::UpdateHistPgt(int x)
{
	pgt_hist.push_back(x);
}
int CpuScheduler::GetSizePgt()
{
	return pgt_hist.size();
}
int CpuScheduler::GetVectorPgt(int x)
{
	return pgt_hist[x];

}
void CpuScheduler::SetTurnaround(int x)
{
	turnaround_counter += x;
}
int CpuScheduler::GetTurnaround()
{
	return turnaround_counter;
}