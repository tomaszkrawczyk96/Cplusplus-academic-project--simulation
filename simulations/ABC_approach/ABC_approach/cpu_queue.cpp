#include "cpu_queue.h"
#include "process.h"

using namespace std;

Process* CpuQueue::Take()
{
	return ready_queue[0];

}
int CpuQueue::GetSize()
{
	return ready_queue.size();
}
void CpuQueue::Add(Process * process)
{
	bool flag = 0;
	if (ready_queue.size() == 0)
	{
		ready_queue.push_back(process);
	}
	else
	{
		int i = 1;
		while ((i <= int(ready_queue.size())) && process->GetCet() <= ready_queue[ready_queue.size() - i]->GetCet())
		{
			if (process->GetCet() == ready_queue[ready_queue.size() - i]->GetCet())
				flag = 1;
			
				i++;
		}
		if ( flag == 0)
			ready_queue.insert(ready_queue.end() - (i - 1), process);
		else
		{
			int random = (int) rand_zo->Rand(0, 2);
			ready_queue.insert(ready_queue.end() - (i - random-1), process);
		}

		
	}
	
}
void CpuQueue::Remove()
{
	ready_queue.erase(ready_queue.begin());

}
CpuQueue::CpuQueue(int i, Kernels * kernel)
{
	rand_zo = new UniformGenerator(kernel->GetKernel(kernel->ZOG, i));
}

CpuQueue::~CpuQueue()
{
}
