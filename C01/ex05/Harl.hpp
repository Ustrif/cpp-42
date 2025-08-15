#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif //__HARL_HPP__