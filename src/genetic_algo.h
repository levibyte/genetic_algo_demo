#ifndef genetic_algo_h
#define genetic_algo_h

#include "genetic_algo_impl.h" 
    
template<typename T>    
class JGeneticAlgo {
    public:  
        JGeneticAlgo(JGeneticAlgoImpl<T>* i):m_impl(i) {}
        
        void run() {
			//std::cout << 
			//std::cout << "creating initial generation" << std::endl;
			//std::cout << m_impl << std::endl;
			m_impl->create_first_generation();
			//std::cout << "calc fitness..." << std::endl;
			m_impl->calc_fitnesses();
			//std::cout << std::endl;
			//std::cout << std::endl;
            //*
			int gen_num=0;
			while ( ! m_impl->is_done(gen_num) ) {
				std::cout << std::endl;
				std::cout << "new generation " << gen_num << std::endl;
				m_impl->make_new_generation();

				std::cout << std::endl;
				std::cout << "calc fitenss... " << std::endl;
				m_impl->calc_fitnesses();
				gen_num++;
			}
			/**/  
             // m_impl->post_process();
        }
        
     private:  
        JGeneticAlgoImpl<T>* m_impl;
};



#endif