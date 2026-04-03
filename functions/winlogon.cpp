#include <iostream>
#include <string>
#include <Windows.h>

#include "../heading/pages.h"
#include "../heading/logo.h"

void winlogon() {
    logo();
    HKEY hkey;

    LSTATUS status = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_ALL_ACCESS, &hkey);

    if (status != ERROR_SUCCESS) {
        std::cout << "\033[31m[-] Error: Run as Administrator! Code: " << status << "\033[0m" << std::endl;
        Sleep(3000);
        return;
    }

    char value[512] = { 0 }; 
    DWORD length = sizeof(value);

    if (RegQueryValueExA(hkey, "Userinit", NULL, NULL, (LPBYTE)value, &length) == ERROR_SUCCESS) {
        std::string currentvalue = value;
        std::cout << "[*] Current Userinit: " << currentvalue << std::endl;

        size_t commaPos = currentvalue.find(',');
        if (commaPos != std::string::npos) {
            std::string cleanVal = currentvalue.substr(0, commaPos + 1);

            if (currentvalue.length() > (commaPos + 1)) { 
                std::cout << "[!] Found extra data! Cleaning..." << std::endl;
                RegSetValueExA(hkey, "Userinit", 0, REG_SZ, (BYTE*)cleanVal.c_str(), (DWORD)cleanVal.length() + 1);
                std::cout << "[+] Fixed to: " << cleanVal << std::endl;
            }
            else {
                std::cout << "[+] Userinit is clean." << std::endl;
            }
        }
    }
    else {
        std::cout << "[-] Could not read value." << std::endl;
    }

    RegCloseKey(hkey);
    Sleep(3000); 
}