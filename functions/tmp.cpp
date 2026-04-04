#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <filesystem>
#include <string>

#include <Windows.h>

#include "../heading/pages.h"
#include "../heading/logo.h"

namespace filesystem = std::filesystem;

void tmp() {
	logo();
	std::cout << "\033[32m[!] Trying to clear temp \033[0m";

	const char* tempPathEnv = std::getenv("TEMP");

	std::filesystem::path path = tempPathEnv;

	try {
		if (filesystem::exists(path) && filesystem::is_directory(path)) {
			for (const auto& entry : filesystem::directory_iterator(path)) {
				try {
					filesystem::remove_all(entry.path());
				}
				catch (...) {
					continue;
				}
			}
			std::cout << "\n\033[32m [!]Temp cleared \033[0m";
			Sleep(5000);

			return;
		}
	}
	catch (const filesystem::filesystem_error& err) {
		std::cerr << "\n[!] Error " << err.what() << std::endl;

		Sleep(5000);

		return;
	}														
													
}