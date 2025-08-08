
#include "BitcoinExchange.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>

int main() {
  PriceMap map;
  try {
    parse_db("data.csv", map);
  } catch (const std::runtime_error &err) {
    std::cerr << "Error: " << err.what() << std::endl;
    return 1;
  } catch (const std::exception &err) {
    return 1;
  }

  // std::cout << "Date | Price" << std::endl;
  for (PriceMap::iterator it = map.begin(); it != map.end(); it++) {
    Date date = it->first;
    std::stringstream date_ss;
    std::cout << date.year << '-' << std::setw(2) << std::setfill('0')
              << date.month << '-' << std::setw(2) << std::setfill('0')
              << date.day;
	std::cout << std::fixed << std::setprecision(2);
    std::cout << date_ss.str() << "," << it->second << std::endl;
  }
  return 0;
}
