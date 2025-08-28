#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <stack>
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
        while (first != last) {
            addNumber(*first);
            first++;
        }
    }

  private:
    int *m_Arr;
    unsigned int m_Size;
    unsigned int m_Capacity;
};
#endif
