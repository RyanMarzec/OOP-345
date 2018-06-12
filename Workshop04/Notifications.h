/*!--- Program - retrieves messages from data file ---!*
 *!---           and collects in a notification    ---!*/

/*!--- Module - Holds and managess the messages ---*/
#pragma once

#include <iostream>
#include "Message.h"
namespace sict {
	const int MAX_MSG = 10;
	const char DELIMITER = '\n';

	class Notifications {
		Message* message;
		int messageCount;
	public:
		Notifications();
		Notifications(std::ifstream&);
		Notifications(Notifications&) = delete;
		Notifications& operator=(Notifications&) = delete;
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		~Notifications();
		void display(std::ostream&) const;
	};
}