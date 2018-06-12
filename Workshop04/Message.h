/*!--- Program - retrieves messages from data file ---!*
 *!---           and collects in a notification    ---!*/

/*!--- Module - Manage and retrive messages to display ---*/
#pragma once

namespace sict {
	class Message {
		std::string user;
		std::string reply;
		std::string tweet;
	public:
		Message();
		Message(std::ifstream&, char);
		void display(std::ostream&) const;
	};
}
