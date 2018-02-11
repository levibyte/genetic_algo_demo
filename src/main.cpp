


#include "genetic_algo.h"
#include "genetic_algo_impl.h"
#include "genetic_algo_my_impl.h"

#include "worker.h"



int main()
{
		
		JStringHelper* helper = new JStringHelper("elen","levon");
		
		JGeneticAlgoImpl* impl = new JGeneticAlgoMyImpl();
		JGeneticAlgo j(impl);
		j.run();
	
}