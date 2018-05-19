#include <iostream>
#include "CString.h"
#include "Process.h"

void sict::process(const char * c)
{
	sict::CString str(c);
	std::cout << str << std::endl;
}
