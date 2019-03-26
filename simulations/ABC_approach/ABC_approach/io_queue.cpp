#include "io_queue.h"
#include <vector>

IoQueue::IoQueue(int i , Kernels * kernel)
{
	rand_rq = new UniformGenerator(kernel->GetKernel(kernel->RQG, i));
}

IoQueue::~IoQueue()
{
}

int IoQueue::RandomPick()
{
	int random_pick = (int) rand_rq->Rand(0, io_queue.size());
	return random_pick;
}

void IoQueue::Add(Process * process)
{
	io_queue.push_back(process);
}
void IoQueue::Remove(int random)
{
	
	io_queue.erase(io_queue.begin() + random);
}

Process * IoQueue::GetProcess(int random)
{
	return io_queue[random];
}
void IoQueue::Zamien(Process * temp,int random)
{
	int max = io_queue.size() - 1;
	io_queue.at(random) = io_queue.at(max);
	io_queue.at(max) = temp;
}

int IoQueue::GetSize()
{
	return io_queue.size();
}
