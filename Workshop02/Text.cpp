#include <string>
#include <fstream>
#include "Text.h"

sict::Text::Text()
	: records(nullptr),
	  numOfRecords(0) {}

sict::Text::Text(const std::string file)
{
	//open file
	std::ifstream f(file, std::ios::in);
	//check if file open
	//if file not open assume safe empty state
	if (!f.is_open()) {
		Text();
	}
	//else if file open count records( lines)
	else {
		std::string line;
		size_t lineCount = 0;
		while (getline(f, line)) {
			lineCount++;
		}
	//return to top of file
	f.clear();
	f.seekg(0, std::ios::beg);
	//allocate dyamic memory for the number of records
	numOfRecords = lineCount;
	records = new std::string[numOfRecords];
	//copy records into dynamic memory 
	for (size_t i = 0; i < numOfRecords; i++)
		f >> records[i];
	}
	f.close();
}

sict::Text::Text( Text & src)
{
	*this = src;
}

sict::Text & sict::Text::operator=( Text & src)
{
	if (this != &src) {
		delete[] records;
		numOfRecords = src.numOfRecords;
		records = new std::string[numOfRecords];
		for (unsigned i = 0; i < numOfRecords; i++) {
			records[i] = src.records[i];
		}
	 }
	return *this;
}

sict::Text::Text(Text && src)
{
	*this = std::move(src);
}

sict::Text & sict::Text::operator=(Text && src)
{
	if (this != &src) {
		delete[] records;
		numOfRecords = src.numOfRecords;
		records = src.records;

		src.records = nullptr;
		src.numOfRecords = 0u;
	}
	return *this;
}

sict::Text::~Text()
{
	delete[] records;
	records = nullptr;
}

size_t sict::Text::size() const
{
	return numOfRecords;
}
