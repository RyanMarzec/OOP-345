#pragma once

#include <iostream>

namespace sict {

	class Text {
		std::string * records;
		size_t numOfRecords;
	public:
		Text();
		Text(const std::string);
		Text(Text &);
		Text& operator=(Text &);
		Text(Text &&);
		Text& operator=(Text &&);
		~Text();
		size_t size() const;
	};
}