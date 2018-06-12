#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Message.h"

/*!--- empty defualt constructor ---!*/
sict::Message::Message() {}

/*!--- Constructor - retrieves record from file object, parses components in ---!*
 *!---               the Message object. char c delimits each record         ---!*/
sict::Message::Message(std::ifstream & in, char c)
{
	std::string line;
	std::string temp;
	getline(in, line, c);
	std::istringstream iss(line);

	iss >> user;
	if ((int)user.find('@') > 0)
	{
		user.clear();
	}
	iss >> reply;
	if ((int)reply.find('@') < 0)
	{
		iss.seekg(0, std::ios::beg);
		iss >> temp;
		getline(iss, tweet);
		reply.clear();
	}
	getline(iss, tweet);
	reply.erase(0, 1);
	tweet.erase(0, 1);
	iss.clear();
}

/*!--- Display - display Message object within the container ---!*/
void sict::Message::display(std::ostream & os) const
{
	if (tweet != "")
	{
		os << "Message" << std::endl
			<< "User   : " << user << std::endl;
		if (reply != "")
		{
			os << "Reply  : " << reply << std::endl;
		}
		os << "Tweet  : " << tweet << std::endl << std::endl;
	}
}
