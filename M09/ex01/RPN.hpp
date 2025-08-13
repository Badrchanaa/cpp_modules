#ifndef __RPN_H__
# define __RPN_H__

#include <string>

/// @brief inverted Polish mathematical expression calculator
/// @param expression RPN expression string e.g: "1 2 +"
/// @return result of the expression
long   RPN(std::string expression);

#endif