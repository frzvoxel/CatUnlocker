// just logo
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

#include "../heading/logo.h"


using namespace std; // namespace


void logo() {
	string logo = R"(
 #####               #     #                                                 
#     #   ##   ##### #     # #    # #       ####   ####  #    # ###### #####
#        #  #    #   #     # ##   # #      #    # #    # #   #  #      #    #
#       #    #   #   #     # # #  # #      #    # #      ####   #####  #    #
#       ######   #   #     # #  # # #      #    # #      #  #   #      #####
#     # #    #   #   #     # #   ## #      #    # #    # #   #  #      #   #
 #####  #    #   #    #####  #    # ######  ####   ####  #    # ###### #    #
)";

	for (char symbols : logo) {
		cout << "\033[31m" << symbols << "\033[0m" << flush;

		this_thread::sleep_for(chrono::milliseconds(1));
	}

	cout << std::endl;
	Beep(1000, 300);
}