#ifndef genetic_algo_impl_h
#define genetic_algo_impl_h

#include "genetic_algo_impl.h"
#include "worker.h"


template<typename T>
class JGeneticAlgoMyImpl: public JGeneticAlgoDefaultImpl<T> 
{


	public:
		JGeneticAlgoMyImpl(int initial_fitness,JWorker* w):JGeneticAlgoDefaultImpl<T>(initial_fitness)
		{
			m_helper = w; 
		}

		

	public:
		int get_fitness(const T& f) {
			return m_helper->get_fitness(f);
		}

		JGen make_crossover(const JGen& g0,const JGen& g1) {
			return m_helper->merge(g0,g1);
		}

		JGen make_mutation(JGen& g) {
			return m_helper->add_change(g);
		}

		void post_process() {
			m_helper->set_winner(JGeneticAlgoDefaultImpl<T>::get_winner());
		}

		void create_first_generation() {            
			//assert(0);
			JGeneticAlgoDefaultImpl<T>::set_initial_state(m_helper->get_current_state());
			for(int i=0;i<JGeneticAlgoDefaultImpl<T>::get_population_size();i++) 
				JGeneticAlgoDefaultImpl<T>::add_gen(m_helper->get_new_state()); 
		}


	public:
		JWorker* m_helper;
};

#endif
