

#include "worker.h"
#include "genetic_algo.h"
#include "genetic_algo_impl.h"
#include "genetic_algo_my_impl.h"





int main()
{
		
		JStringWorker* worker = new JStringWorker("elen","levon");
		
		JGeneticAlgoImpl* impl = new JGeneticAlgoMyImpl(worker);
		JGeneticAlgo j(impl);
		j.run();
	
}