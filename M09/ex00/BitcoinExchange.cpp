#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

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

std::istringstream &operator>>(std::istringstream &iss, Date &date)
{
    char sep = 0;
    std::string error;

    // std::istringstream::sentry ss(iss);
    iss >> date.year;
    if (!iss || date.year < 1960 || date.year > 3000)
    {
	iss.setstate(std::ios::failbit);
	std::cerr << "Invalid date year: " << date.year << std::endl;
	return iss;
    }
    if (!(iss >> sep) || sep != '-')
    {
	iss.setstate(std::ios::failbit);
	std::cerr << "Invalid date separator" << std::endl;
	return iss;
    }
    iss >> date.month;
    if (!iss || date.month < 1 || date.month > 12)
    {
	iss.setstate(std::ios::failbit);
	std::cerr << "Invalid date month" << std::endl;
	return iss;
    }
    if (!(iss >> sep) || sep != '-')
    {
	iss.setstate(std::ios::failbit);
	std::cerr << "Invalid date separator" << std::endl;
	return iss;
    }
    iss >> date.day;
    if (!iss || date.day < 1 || date.day > 31)
    {
	iss.setstate(std::ios::failbit);
	std::cerr << "Invalid date day" << std::endl;
	return iss;
    }
    return iss;
}

std::pair<Date, double> parse_db_line(std::string line)
{
    std::istringstream iss(line);
    char csvSeparator = 0;
    Date date;
    double value;

    iss >> date;
    if (!iss)
	throw std::exception();
    if (!(iss >> csvSeparator) || csvSeparator != ',')
	throw std::runtime_error("Invalid database column separator");
    if (!(iss >> value))
    {
	throw std::runtime_error("Invalid price value");
    }
    return std::pair<Date, double>(date, value);
}

void parse_db(std::string db_filename, PriceMap &map)
{
    std::ifstream dbfile;
    dbfile.open(db_filename.c_str());
    if (!dbfile.is_open())
    {
	std::cerr << "Db file not found" << std::endl;
	return;
    }
    std::string header;
    std::getline(dbfile, header);
    std::cout << header << std::endl;
    std::string line;
    while (std::getline(dbfile, line))
    {
	std::pair<Date, double> record = parse_db_line(line);
	map[record.first] = record.second;
    }
}
