#ifndef	MUTANT_STACK
#define MUTANT_STACK

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack<T>& other);

		MutantStack& operator = (const MutantStack<T>& other);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void);
		iterator end(void);
};

#include "MutantStack.tpp"
#endif // MUTANT_STACK
