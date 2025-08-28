#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() : std::stack<T> () {}
    MutantStack &operator=(const MutantStack &other)
    {
      this->std::stack<T>::operator=(other);
      return *this;
    }
    MutantStack(const MutantStack &mstack) : std::stack<T>(mstack) {}
    ~MutantStack() {}

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif
