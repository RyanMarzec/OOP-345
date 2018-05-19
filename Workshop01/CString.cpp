#define _CRT_SECURE_NO_WARNINGS
#include "CString.h"

int SHARE_MAX = sict::MAX_CHAR;

sict::CString::CString(const char * cstr)
{
	if (cstr == '\0') {
		cstring[0] = '\0';
	}
	else {
		strncpy(cstring, cstr, MAX_CHAR);
		cstring[MAX_CHAR] = '\0';
	}
}

void sict::CString::display(std::ostream & os)
{
	for (int i = 0; i < MAX_CHAR; i++) {
		os << cstring[i];
	}
}

std::ostream& sict::operator<<(std::ostream& os, CString& cstr)
{
	static bool runOnce = true;
	if(runOnce) {
		std::cout << "No  Record Contents ..." << std::endl;
		runOnce = false;
	}
	std::cout << counter++
			  << ": ";
	cstr.display(os);
	return os;
}
