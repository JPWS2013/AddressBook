#ifndef _AddBook_hpp
#define _AddBook_hpp

#include "Contact.hpp"

class AddressBook
{
	std::string book_name;
	std::vector<Contact> contacts;

public:
	AddressBook(std::string name): 
	
	book_name(name)
	
	{
		std::cout << "You've initialized an addressbook named " << book_name << "!" << std::endl;
	}

	std::string GetName()
	{
		return book_name;
	}

	void AddEntry()
	{
		std::string options;
		std::string first;
		std::string last;
		std::string email;

		std::cout << "Enter a first name: ";
		std::cin >> first;
		std::cout << std::endl;

		std::cout << "Enter a last name: ";
		std::cin >> last;
		std::cout << std::endl; 

		Contact contact(first, last);

		std::cout << "Would you like to enter a phone number or email address? (Separate each option with a comma) ";
		std::cin >> options;
		std::cout << std::endl;

		if (options.find("email") != std::string::npos)
		{
			contact.AddEmail(email);
		}

		if (options.find("phone") != std::string::npos)
		{
			int num_phones=0;
			std::cout << "How many phone numbers would you like to enter?";
			std::cin >> num_phones;
			
		}

	}
};

#endif