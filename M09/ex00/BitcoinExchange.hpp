#ifndef __BITCOIN_EXCHANGE__
#define __BITCOIN_EXCHANGE__

#include <map>
#include <sstream>

class Date
{
    public:
	Date() : year(0), month(0), day(0) {}
	Date(const Date &date)
	    : year(date.year), month(date.month), day(date.day)
	{
	}
	Date &operator=(const Date &date)
	{
	    this->year = date.year;
	    this->month = date.month;
	    this->day = date.day;
	    return *this;
	}
	bool operator<(const Date &date) const;
	bool operator>(const Date &date) const;
	bool operator==(const Date &date) const;
	bool operator!=(const Date &date) const;
	bool isValid() const
	{
	    return (year > 1960 && year < 3000 && month > 0 && month < 13 &&
	            day > 0 && day < 32);
	}
	int year;
	int month;
	int day;
};

typedef std::map<Date, double> PriceMap;

double parse_line(std::string line, char separator, Date &outDate, double &outValue);
// void parse_csv(std::string filename, void (*fn)(Date, double), char separator=',');
std::istringstream &operator>>(std::istringstream &iss, Date &date);
std::ostream &operator<<(std::ostream &os, const Date &date);

#endif
