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
		void setIdea(int index, const std::string& idea);
		void displayIdeas() const;
};

#endif //__BRAIN__