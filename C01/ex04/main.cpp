#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4 || !argv)
	{
		std::cout << "Invalid arguments.\n";
		return (1);
	}
	std::string	infileName = argv[1];
	std::string	outfileName = infileName + ".replace";

	std::string	willFind = argv[2];
	std::string	willWrite = argv[3];

	if (infileName.empty() || willFind.empty() || willWrite.empty())
	{
			std::cout << "Invalid arguments.\n";
			return (1);
	}

	std::ifstream fileRead(infileName.c_str());
	if (!fileRead.is_open())
	{
			std::cout << "Invalid infile.\n";
			return (1);
	}
	fileRead.close();

	std::ofstream fileWrite(outfileName.c_str());
	bool	firstLine = true;
	if (fileWrite.is_open())
	{
		std::ifstream fileRead(infileName.c_str());
		if (fileRead.is_open())
		{
			std::string	s;
			while (getline(fileRead, s))
			{
					if (!firstLine)
						fileWrite << "\n";
					else
						firstLine = false;
				size_t findIn = 0;
				while ((findIn = s.find(willFind, findIn)) != std::string::npos)
				{
					s.erase(findIn, willFind.length());
					s.insert(findIn, willWrite);
					findIn += willWrite.length();
				}
				fileWrite << s;
			}
			fileRead.close();
		}
		fileWrite.close();
	}
	return (0);
}
