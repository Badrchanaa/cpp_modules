#include "BitcoinExchange.hpp"
#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

void print_map(PriceMap &map)
{
  for (PriceMap::iterator it = map.begin(); it != map.end(); it++)
  {
    Date date = it->first;
    std::stringstream date_ss;
    std::cout << date;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << date_ss.str() << "," << it->second << std::endl;
  }
}

std::string prepareCsv(std::ifstream &ifs, const std::string &filename)
{
  ifs.open(filename.c_str());
  if (!ifs.is_open())
  {
    throw std::runtime_error("file not found");
    return std::string("");
  }
  std::string header;
  std::getline(ifs, header);
  return header;
}

void processDB(PriceMap &dataMap, const std::string& filename)
{
  Date date;
  double value;

  std::ifstream file;
  prepareCsv(file, filename);
  std::string line;
  while (std::getline(file, line))
  {
    if (parse_line(line, ',', date, value))
      dataMap[date] = value;
  }
}

double calculatePrice(const PriceMap &dataMap, const Date &date, double value)
{
  PriceMap::const_iterator it = dataMap.lower_bound(date);
  if (it != dataMap.begin() && it->first != date)
    it--;
  return value * it->second;
}

void processInput(PriceMap &dataMap, const std::string& filename)
{
  Date date;
  double value;

  std::ifstream file;
  prepareCsv(file, filename);
  std::string line;
  while (std::getline(file, line))
  {
    if (parse_line(line, '|', date, value))
    {
      if (value < 0)
	std::cerr << "Error: not a positive number." << std::endl;
      else if (value > INT_MAX)
	std::cerr << "Error: too large a number." << std::endl;
      else
	std::cout << date << " => " << calculatePrice(dataMap, date, value) << std::endl;
    }
  }
}

int main(int ac, char **av)
{
  if (ac == 1)
  {
    std::cout << "No input file received." << std::endl;
    std::cout << "Usage: ./btc <input_filename>" << std::endl;
    return 1;
  }
  PriceMap databaseMap;
  try
  {
    processDB(databaseMap, "data.csv");
    if (databaseMap.empty())
    {
      std::cerr << "No valid database rows." << std::endl;
      return 1;
    }
    processInput(databaseMap, av[1]);
  }
  catch (const std::runtime_error &err)
  {
    std::cerr << "Error: " << err.what() << std::endl;
    return 1;
  }
  catch (const std::exception &err)
  {
    return 1;
  }
  return 0;
}
