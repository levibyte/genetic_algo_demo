#ifndef genetic_algo_impl_h
#define genetic_algo_impl_h

#include "genetic_algo_impl.h"


template<typename T>
class JGeneticAlgoMyImpl: public JGeneticAlgoDefaultImpl<T> 
{


	public:
		JGeneticAlgoMyImpl(int initial_fitness,JManager* logic):JGeneticAlgoDefaultImpl<T>(initial_fitness)
		{
			m_logic = logic; 
		}


	public:
		int get_fitness(const T& f) {
			return m_worker->get_fitness(f);
		}

		JGen make_crossover(const JGen& g0,const JGen& g1) {
			return merge(g0,g1);
		}

		JGen make_mutation(JGen& g) {
			return m_worker->add_change(g);
		}

		void post_process() {
			m_worker->set_winner(JGeneticAlgoDefaultImpl<T>::get_winner());
		}

		void create_first_generation() {            
			//assert(0);
			JGeneticAlgoDefaultImpl<T>::set_initial_state(m_worker->get_current_state());
			for(int i=0;i<JGeneticAlgoDefaultImpl<T>::get_population_size();i++) 
				JGeneticAlgoDefaultImpl<T>::add_gen(m_worker->get_new_state()); 
		}


	public:
		JWorker* m_worker;
};

#endif
