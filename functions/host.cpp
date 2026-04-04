#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <Windows.h>

#include "../heading/pages.h"
#include "../heading/logo.h"

void host() {
	logo();

	std::string hostpath = "C:\\Windows\\System32\\drivers\\etc\\hosts";

	std::string defaulthost = R"(	
	# Copyright (c) 1993-2009 Microsoft Corp.
	#
	# This is a sample HOSTS file...

	127.0.0.1       localhost
	::1             localhost
)";

	std::ofstream file(hostpath, std::ios::trunc);

	try {
		if (file.is_open()) {
			file << defaulthost;

			std::cout << "[*] file hosts overwritten!";


			Sleep(5000);

			return;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "[!] Error" << e.what() << std::endl;

		Sleep(5000);

		return;
	}
}