#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testMutantStack() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void testList() {
  std::list<int> mstack;
  mstack.push_back(5);
  mstack.push_back(17);
  std::cout << mstack.back() << std::endl;
  mstack.pop_back();
  std::cout << mstack.size() << std::endl;
  mstack.push_back(3);
  mstack.push_back(5);
  mstack.push_back(737);
  //[...]
  mstack.push_back(0);
  std::list<int>::iterator it = mstack.begin();
  std::list<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::list<int> s(mstack);
}

int main() { 

	std::cout << "######### TEST MUTANT STACK #########" << std::endl;
	testMutantStack();
	std::cout << "######### TEST STD LIST #########" << std::endl;
	testList();
  std::cout << " ######## TEST MUTANT STACK 2 ######## " << std::endl;
  {
    MutantStack<double> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(40);
    std::cout << "MutantStack begin: " << *mstack.begin() << std::endl;
    MutantStack<double>::iterator it = mstack.end();
    it--;
    std::cout << "MutantStack last: " << *it << std::endl;
    std::cout << "MutantStack top: " << mstack.top() << std::endl;
  }
	return 0; }

