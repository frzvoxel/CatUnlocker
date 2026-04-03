#include <iostream> // preprocessor directives
#include <Windows.h>
#include <Lmcons.h>

// heading
#include "heading/logo.h"
#include "heading/pages.h"



struct UserStruct
{
	int Choice;
};

void CheckCommand(UserStruct &User); // Prototype

int main() {
	UserStruct User;

	while (true) {
		std::cout << "\033[2J\033[H";

		logo();
		std::cout << "\n[1] Clear temp\n";
		std::cout << "\n[2] Check Winlogon\n";

		std::cout << "\033[31m Command:\033[0m" << " ";

		std::cin >> User.Choice;

		if (std::cin.fail()) {
			std::cin.clear(); 
			std::cin.ignore(10000, '\n'); 
			std::cout << "\033[31m[!] Error: Enter a number!\033[0m\n";
			Sleep(1000); 
			continue;
		}
		CheckCommand(User);
	}
	return 0;
}

void CheckCommand(UserStruct &User) {
	switch (User.Choice) {
	case 1: {
		std::cout << "\033[2J\033[H";
		tmp();
		break;
	}

	case 2: {
		std::cout << "\033[2J\033[H";
		winlogon();
		break;
	}

	default: { 
		std::cout << "i dont know what its";
		break;
	}
	}
}