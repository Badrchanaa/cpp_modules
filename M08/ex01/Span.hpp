#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>

class Span {
  public:
    Span(unsigned int N);
    Span(const Span &sp);
    ~Span();
    Span &operator=(Span sp);

    void addNumber(int a);
    int longestSpan();
    int shortestSpan();

    template <typename ForwardIt> void addAll(ForwardIt first, ForwardIt last) {
        unsigned int i = 0;
        while (first != last) {
            addNumber(*first);
            i++;
            first++;
        }
        std::cout << "Added " << i << " elements" << std::endl;
    }

  private:
    int *m_Arr;
    unsigned int m_Size;
    unsigned int m_Capacity;
};
#endif
