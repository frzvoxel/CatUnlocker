// Made by Voxel and Nowotx (devxtx-hue)

#include <iostream> 
#include <Windows.h>
#include <Lmcons.h>

// Project headers
#include "heading/logo.h"
#include "heading/pages.h"

// Data structure to store user input
struct UserStruct
{
	unsigned short Choice; // Selected menu item
};

// Prototype for the command handler
void CheckCommand(UserStruct& User);

int main() {
	UserStruct User; // Local structure instance

	// Main application loop
	while (true) {
		// Clear screen and reset cursor position (ANSI escape codes)
		std::cout << "\033[2J\033[H";

		logo(); // Render animated startup logo

		// Output available menu options
		std::cout << "\n[1] Clear temp\n";
		std::cout << "\n[2] Check Winlogon\n";
		std::cout << "\n[3] Overwrite Hosts\n";
		std::cout << "\n[4] Panic Kill All\n";


		std::cout << "\n[5] Components Page\n";

		std::cout << "\n\033[31m Command:\033[0m" << " ";

		// Wait for user input
		std::cin >> User.Choice;

		// Input validation: Check if input is a valid number
		if (std::cin.fail()) {
			std::cin.clear(); // Clear the error flag from cin
			std::cin.ignore(10000, '\n'); // Purge the input buffer
			std::cout << "\033[31m[!] Error: Enter a number!\033[0m\n";
			Sleep(1000); // Give user time to read the error
			continue; // Skip to the next iteration
		}

		CheckCommand(User); // Execute the selected function
	}
	return 0; // Standard exit code
}

// Logic for switching between application functions
void CheckCommand(UserStruct& User) {
	switch (User.Choice) {
	case 1: {
		std::cout << "\033[2J\033[H"; // Clear screen before execution
		tmp(); // Clean temporary files
		break;
	}

	case 2: {
		std::cout << "\033[2J\033[H";
		winlogon(); // Check registry persistence (Userinit)
		break;
	}

	case 3: {
		std::cout << "\033[2J\033[H";
		host(); // Reset and clean the hosts file
		break;
	}

	case 4: {
		std::cout << "\033[2J\033[H";
		killprocess(); // "Panic Mode": Terminate non-system processes
		break;
	}

	case 5: {
		std::cout << "\033[2J\033[H";
		components_page();
		break;
	}

	default: {
		// Fallback for undefined command numbers
		std::cout << "\033[33m[?] Unknown command. Try again.\033[0m" << std::endl;
		Sleep(1000);
		break;
	}
	}
}