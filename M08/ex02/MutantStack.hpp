#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {

public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  MutantStack<T>() : std::stack<T>() {}
  MutantStack &operator=(const MutantStack &other) {
    this->std::stack<T>::operator=(other);
    return *this;
  }
  MutantStack<T>(const MutantStack<T> &mstack) : std::stack<T>(mstack) {}
  ~MutantStack<T>() {}

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};

#endif
