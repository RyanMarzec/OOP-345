#pragma once
#include <iostream>

namespace sict {

	const int MAX_CHAR = 14;
	static int counter = 10;

	class CString {
		char cstring[MAX_CHAR + 1];
	public:
		CString(const char*);
		void display(std::ostream&);
	};
	std::ostream& operator<<(std::ostream&, CString&);
}