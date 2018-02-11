#ifndef worker_h
#define worker_h

#include <string>

template < typename T>
class JWorker 
{
	public:
		virtual int get_fitness(const T&) = 0;
		virtual T get_current_state() = 0;
		virtual T get_new_state() = 0; 
		virtual void set_winner(const T& m) = 0;
		virtual T add_change(const T& m) = 0;
};


class JStringWorker: public JWorker<std::string>
{
	public:
		JStringWorker(const char* src, const char* dst):m_src_name(src),m_dst_name(dst),m_current_name(src) {}
			
	public:
		int get_fitness(const std::string& s) {}
		std::string get_current_state() {} ;
		std::string get_new_state() {} ;
		void set_winner(const std::string& m) {} ;
		std::string add_change(const std::string& m) {};

	private:
		std::string m_src_name;
		std::string m_dst_name;
		std::string m_current_name;
		
		
};


#endif