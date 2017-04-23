#ifndef _Contact_hpp
#define _Contact_hpp

class Phone
{
	std::string type;
	std::string number;

public:
	Phone(std::string input_type, std::string input_number)
	{
		type=input_type;
		number=input_number;
		std::cout << "Adding a phone number!" << std::endl;
	}

};

class Contact
{
	std::string first;
	std::string last;
	std::string email;
	std::vector<Phone> phone_nums;

public:
	Contact(std::string input_first, std::string input_last)
	{
		first=input_first;
		last=input_last;
	}

	void AddEmail(std::string input_email)
	{
		std::cout << "Enter an email address: ";
		std::cin >> email;
		// email = input_email;
		std::cout << std::endl; 
	}

	void AddPhone(int num_phones)
	{
		for (int i=0; i<num_phones; i++)
		{
			std::string type, number;

			std::cout << "What type of phone number is this (e.g. home, work)?: ";
			std::cin >> type;
			std::cout << std::endl;

			std::cout << "Enter a phone number address: ";
			std::cin >> number;
			std::cout << std::endl; 

			phone_nums.emplace_back(type, number);
		}

	}

};

#endif