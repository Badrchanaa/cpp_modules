#include <iostream>
#include <fstream>

/*
	replaces each occurence of oldStr in ifile (input file) by 
	newStr in ofile (output file)
*/

int	sed(std::ifstream &ifile, std::ofstream &ofile, std::string &oldStr, std::string &newStr)
{
	std::string		line;
	std::string		fileContent;
	size_t			pos;
	size_t			index;

	while(std::getline(ifile, line))
		fileContent += line + "\n";
	index = 0;
	if (oldStr.empty() || oldStr == newStr)
		pos = std::string::npos;
	else
		pos = fileContent.find(oldStr, index);
	while (pos != std::string::npos)
	{
		index = pos + newStr.length();
		fileContent.erase(pos, oldStr.length());
		fileContent.insert(pos, newStr);
		pos = fileContent.find(oldStr, index);
	}
	ofile << fileContent << std::endl;
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac < 4)
	{
		std::cout << "invalid arguments" << std::endl;
		return 0;
	}
	std::ifstream ifile;
	std::ofstream ofile;
	std::string oldStr(av[2]);
	std::string newStr(av[3]);
	ifile.open(av[1]);
	if (!ifile)
	{
		std::cout << "Cannot open input file" << std::endl;
		return 0;
	}
	std::string newName = av[1];
	newName += ".replace";
	ofile.open(newName.c_str());
	if (!ofile)
	{
		std::cout << "Cannot open output file" << std::endl;
		return 0;
	}
	sed(ifile, ofile, oldStr, newStr);
	ifile.close();
	ofile.close();
	return (0);
}
