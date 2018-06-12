#include <string>
#include <fstream>
#include <iostream>

#include "Notifications.h"

/*!--- Defualt constructor ---!*/
sict::Notifications::Notifications()
	: message(nullptr),
	  messageCount(0)
{}

/*!--- Constructor ---!*/
sict::Notifications::Notifications(std::ifstream & is)
	: message(nullptr),
	  messageCount(0)
{
	std::string line;
	while (getline(is, line))
	{
		messageCount++;
	}
	is.clear();
	is.seekg(0, std::ios::beg);	
	if (message == nullptr)
	{
		message = new Message[messageCount];
	}
	for (int i = 0; i < messageCount; i++)
	{
		message[i] = Message(is, DELIMITER);
	}
}

/*!--- Move constructor ---!*/
sict::Notifications::Notifications(Notifications && src)
{
	*this = std::move(src);
}

/*!--- Move assignment operator ---!*/
sict::Notifications && sict::Notifications::operator=(Notifications && src)
{
	if (this != &src)
	{
		delete[] message;
		messageCount = src.messageCount;
		message = src.message;

		src.messageCount = 0;
		src.message = nullptr;
	}
	return std::move(*this);
}

/*!--- Deconstructor ---!*/
sict::Notifications::~Notifications()
{
	delete[] message;
	message = nullptr;
}

/*!--- Display - insert the Message object to the output stream ---!*/
void sict::Notifications::display(std::ostream & os) const
{
	for (int i = 0; i < messageCount; i++)
	{
		message[i].display(os);
	}
}
