#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

bool Date::operator<(const Date &date) const
{
  if (year != date.year)
    return year < date.year;
  if (month != date.month)
    return month < date.month;
  return day < date.day;
}

bool Date::operator>(const Date &date) const { return date < *this; }

bool Date::operator==(const Date &date) const
{
  return (year == date.year && month == date.month && day == date.day);
}

bool Date::operator!=(const Date &date) const { return !(*this == date); }

std::ostream &operator<<(std::ostream &os, const Date &date)
{
  os << date.year << '-' << std::setw(2) << std::setfill('0') << date.month << '-' << std::setw(2)
     << std::setfill('0') << date.day;
  return os;
}

std::istringstream &operator>>(std::istringstream &iss, Date &date)
{
  char sep = 0;
  std::string error;

  // std::istringstream::sentry ss(iss);
  iss >> date.year;
  if (!iss || date.year < 1960 || date.year > 3000)
  {
    iss.setstate(std::ios::failbit);
    return iss;
  }
  if (!(iss >> sep) || sep != '-')
  {
    iss.setstate(std::ios::failbit);
    return iss;
  }
  iss >> date.month;
  if (!iss || date.month < 1 || date.month > 12)
  {
    iss.setstate(std::ios::failbit);
    return iss;
  }
  if (!(iss >> sep) || sep != '-')
  {
    iss.setstate(std::ios::failbit);
    return iss;
  }
  iss >> date.day;
  if (!iss || date.day < 1 || date.day > 31)
  {
    iss.setstate(std::ios::failbit);
    return iss;
  }
  return iss;
}

double parse_line(std::string line, char separator, Date &outDate, double &outValue)
{
  std::istringstream iss(line);
  char c = 0;
  Date date;
  double value;

  iss >> date;
  if (!iss)
  {
    std::cerr << "Error: bad input => " << line << std::endl;
    return false;
  }
  if (!(iss >> c) || c != separator)
  {
    std::cerr << "Error: bad input => " << line << std::endl;
    return false;
  }
  if (!(iss >> value))
  {
    std::cerr << "Error: bad input => " << line << std::endl;
    return false;
  }
  outDate = date;
  outValue = value;
  return true;
}

