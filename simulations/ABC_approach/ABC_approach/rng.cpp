#include "rng.h"
#include "kernels.h"
#include "generator.h"

RNG::RNG()
{
   tpw = nullptr;
   tpd = nullptr;
   tpg = nullptr;
   tpio = nullptr;
   tpo = nullptr;
   zog = nullptr;
   rqg = nullptr;
   
}

RNG::~RNG()
{
   delete tpw;
   delete tpd;
   delete tpg;
   delete tpio;
   delete tpo;
   delete zog;
   delete rqg;
   
}

void RNG::Initialize(Kernels *kernels, int set_idx, double lambda)
{
   tpw = new UniformGenerator(kernels->GetKernel(Kernels::TPW, set_idx));
   tpd = new UniformGenerator(kernels->GetKernel(Kernels::TPD, set_idx));
   tpio = new UniformGenerator(kernels->GetKernel(Kernels::TPIO, set_idx));
   tpo = new UniformGenerator(kernels->GetKernel(Kernels::TPO, set_idx));
   tpg = new ExpGenerator(lambda, new UniformGenerator(kernels->GetKernel(Kernels::TPG, set_idx)));
   zog = new UniformGenerator(kernels->GetKernel(Kernels::ZOG, set_idx));
   rqg = new UniformGenerator(kernels->GetKernel(Kernels::ZOG, set_idx));

   
}