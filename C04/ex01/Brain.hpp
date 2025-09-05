#ifndef __BRAIN__
#define __BRAIN__

#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
};

#endif //__BRAIN__