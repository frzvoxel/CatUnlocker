#include <windows.h>
#include <tlhelp32.h> 
#include <vector>
#include <string>
#include <iostream>

#include "../heading/pages.h"

bool IsSystemProcess(std::string name) {
	std::vector<std::string> whitelist = {
		"System", "idle", "explorer.exe", "lsass.exe",
		"csrss.exe", "smss.exe", "wininit.exe", "services.exe",
		"winlogon.exe", "svchost.exe", "CatUnlocker.exe"
	};

	for (const auto& sys : whitelist) {
		if (_stricmp(name.c_str(), sys.c_str()) == 0) return true;
	}
	return false;
}

void killprocess() {
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hsnap == INVALID_HANDLE_VALUE) return;

    PROCESSENTRY32 pe;

	pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hsnap, &pe)) {
        do {
            std::string procName = pe.szExeFile;

            if (!IsSystemProcess(procName)) {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID);
                if (hProcess != NULL) {
                    std::cout << "[!] Killing: " << procName << std::endl;
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                }
            }
        } while (Process32Next(hsnap, &pe));
    }
    CloseHandle(hsnap);
    std::cout << "\n[+] Cleanup finished!" << std::endl;
}