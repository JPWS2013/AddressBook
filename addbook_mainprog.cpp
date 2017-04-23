#include <iostream>
#include <vector>
#include <string>
#include "build/AddBookConfig.h"
#include "AddBook.hpp"
#include <typeinfo>

class Collection
{
	std::vector<AddressBook> coll_vec;

	void ShowNumBooks()
	{
		std::cout << "This collection contains " << coll_vec.size() << " address book(s)" << std::endl;
	}

	void ListBooks()
	{
		for (int i=0; i<coll_vec.size(); i++)
		{
			std::cout << (i+1) << ". " << coll_vec[i].GetName() << std::endl;
		}
		
	}

	void CreateBook()
	{
		// AddressBook newbook(name);
		std::string book_name;
		std::cout << "Please enter a name for your new address book: ";
		std::cin >> book_name;
		std::cout << std::endl;
		coll_vec.emplace_back(book_name); 
		ShowNumBooks();
	}

	void RemoveBook()
	{
		int book_choice=-1;

		std::cout << "Enter the number corresponding to the name of the address book you would like to delete: " << std::endl;

		ListBooks();

		std::cin >> book_choice;

		coll_vec.erase(coll_vec.begin()+(book_choice-1));
		
	}

	void AddEntry()
	{
		int book_num;

		if (coll_vec.size() >= 1)
		{
			std::cout << "Please select an address book to add an entry to: " << std::endl;

			ListBooks();

			std::cin >> book_num;
		}

		else
		{
			book_num = 0;
		}

		coll_vec[book_num].AddEntry();
	}	
public:
	Collection()
	{
		// std::cout << "Collection: " << coll_name << std::endl;
		// ShowNumBooks();
	}

	int GetOption()
	{
		int option;

		std::cout << std::endl;
		std::cout << "Please select from one of the following options:" << std::endl<<std::endl;
		std::cout << "0. Exit Program" << std::endl <<
					 "1. Show addressbooks in this collection" << std::endl <<
					 "2. Create a new address book" << std::endl <<
					 "3. Remove an Address Book" << std::endl <<
					 "4. Edit an Addressbook" << std::endl << std::endl;

		std::cout << "What would you like to do?  ";
		std::cin >> option;

		return option;
	}

	void PerformAction(int option)
	{
		switch(option)
		{
			case 1:
				ListBooks();
				break;
			case 2:
				CreateBook();
				break;
			case 3:
				RemoveBook();
				break;
			case 4:
				AddEntry();
				break;
		}
	}

	int CheckEmpty()
	{
		if (coll_vec.size() == 0)
		{
			std::cout << "This collection does not contain any addressbooks!" << std::endl;
			return 1;
		}
		else
			return 0;
	}
	


};

int main()
{
	std::cout << "-----------------------------------" << std::endl <<"AddressBook Program" << std::endl << "Version " << AddBook_VERSION_MAJOR << "." << AddBook_VERSION_MINOR << std::endl << "-----------------------------------" << std::endl; 

	std::cout << std::endl << std::endl;

	Collection coll;
	int option=-1;

	while (option)
	{
		// std::cout << "Showing menu" <<std::endl;
		option = coll.GetOption();

		if (!coll.CheckEmpty() || (option ==2))
		// std::cout << "Performing the action requetsed" << std::endl;
			coll.PerformAction(option);
	}


	// coll.CreateBook("TestBook1");

	return 0;
}