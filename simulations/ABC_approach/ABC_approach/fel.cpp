#include "fel.h"
#include "event.h"
#include <cstdlib>




void FutureEventList::Add(Event * ev)
{
	bool flag = 0;
	if (fel.size() == 0)
	{
		fel.push_back(ev);
	}
	else
	{ 
			int i = 1;
			while ((i <= int(fel.size())) && (ev->GetEventTime() <= fel[fel.size() - i]->GetEventTime()))
						{
						if (ev->GetEventTime() == fel[fel.size() - i]->GetEventTime())
							flag = 1; 

						
								i++;

						}
					if(flag == 0)
					fel.insert(fel.end() - (i - 1), ev);
					else 
					{
						int random = (int) rand_zo->Rand(0, 2);
						
						fel.insert(fel.end() - (i - random-1), ev);
					}
		
		
	}
	

}

Event * FutureEventList::GetEvent()
{
	return fel[0];
}

void FutureEventList::Remove()
{
	fel.erase(fel.begin());
}

FutureEventList::FutureEventList(Kernels* kernel, int i)
{
	rand_zo = new UniformGenerator(kernel->GetKernel(kernel->ZOG, i));
}

FutureEventList::~FutureEventList()
{
}
