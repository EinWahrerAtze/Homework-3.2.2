#include <iostream>
#include <string>
#include <vector>

#define END_CONDITION (answer[0] != 'x') && (answer[0] != 'X')
#define ADD_CONDITION (answer[0] != 'a' && answer[0] != 'A')

struct Account
{
	int number;
	std::string name;
	double balance;
};

void check_double(double* number)
{
	while (!(std::cin >> *(number)))
	{
		std::cin.clear();

		while (std::cin.get() != '\n')
			continue;
		
		std::cout << "Please enter a value: ";
	}
}

void show_menu(void)
{
	std::cout << "\"A\" to add a new bank account.\n";
	std::cout << "\"E\" to edit a bank account.\n";
	std::cout << "\"S\" to show all the banks accounts.\n";
	std::cout << "\"X\" to exit.\n";
}

void add_account(std::vector<Account>* list)
{
	system("cls");

	Account new_acc{ 0, "0", 0.0 };
	list->push_back(new_acc);

	list->back().number = list->size();

	std::cout << "Account # " << list->back().number << ";\n";
	std::cout << "Enter account name: ";
	getline(std::cin, list->back().name);
	std::cout << "Enter account balance, $: ";
	check_double(&list->back().balance);
}

void show_accounts(std::vector<Account>* list)
{
	system("cls");
	std::cout << "Here are all the accounts created:\n\n";

	for (int i = 0; i < list->size(); ++i)
	{
		std::cout << "Account # " << list->at(i).number << ";\n";
		std::cout << "Account name: " << list->at(i).name << ";\n";
		std::cout << "Account balance: " << list->at(i).balance << ";";
		std::cout << (i == list->size() - 1 ? "\n" : "\n\n");
	}
}

void modify_account(std::vector<Account>* list, int index)
{
	std::system("cls");
	std::cout << "Account # " << list->at(index - 1).number << ";\n";
	std::cout << "Account name: " << list->at(index - 1).name << ";\n";
	std::cout << "Enter a new name: ";
	std::cin.get();
	getline(std::cin, list->at(index - 1).name);
	std::cout << "Account balance: " << list->at(index - 1).balance << "$;\n";
	std::cout << "Enter a new balance, $: ";
	check_double(&list->at(index - 1).balance);
	std::cin.get();
}

int main()
{
	std::cout << "Welcome to the world best bank program!\n";
	std::cout << "Select one of the action to start:\n\n";
		
	show_menu();
	
	std::cout << "\nInput: ";

	std::vector<Account>list;
	std::string answer;
	
	getline(std::cin, answer);

	while (END_CONDITION)
	{
		switch (answer[0])
		{
			case 'a': // add
			case 'A': 
				while (answer[0] != 'x' && answer[0] != 'X')
				{
					
					add_account(&list);
					std::cout << "\nWant to add anoter one?\n";
					std::cout << "Enter \"A\" to add or \"X\" to exit.\n";
					std::cout << "\nInput: ";
					std::cin.get();
					getline(std::cin, answer);

					while (END_CONDITION && ADD_CONDITION)
					{
						std::cin.clear();
						std::cout << "That's not a choice!\n";
						std::cout << "Repeat: ";
						getline(std::cin, answer);
					}
				}
				break;
			case 'e': // edit
			case 'E':
				if (list.size() == 0)
				{
					std::system("cls");
					std::cout << "There are no accounts created to modify!\n";
					break;
				}
				else
				{
					std::system("cls");
					std::cout << "Which account you would like to edit?\n";
					std::cout << "Enter a number between 1 and ";
					std::cout << list.size() << ": ";
					
					int index = 0;
					
					while (!(std::cin >> index) || (index <= 0) || (index > list.size()))
					{
						std::cin.clear();
						
						while (std::cin.get() != '\n')
							continue;

						std::cout << "Please enter a volid account index: ";
					}
										
					modify_account(&list, index);
					break;
				}
			case 's': // show
			case 'S':
				if (list.size() == 0)
				{
					std::system("cls");
					std::cout << "There are no accounts created to show!\n";
					break;
				}
				else
				{
					show_accounts(&list);
					break;
				}
			default:
				std::system("cls");
				std::cout << "That's not a choice!\n";
				break;
		}

		std::cout << std::endl;
		show_menu();
		std::cout << "\nInput: ";
		getline(std::cin, answer);
	}

	std::cout << "Bye!\n";
	return 0;
}