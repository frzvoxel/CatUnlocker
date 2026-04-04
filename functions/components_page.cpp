#include <iostream>
#include <Windows.h>
#include <limits>

#include "../heading/pages.h"
#include "../heading/logo.h"

struct DismFeature {
	const char* DisplayName;
	const char* SysName;
};


static const DismFeature features[] = {
	{"", ""}, // 0
	{"DirectPlay", "/Enable-Feature /FeatureName:DirectPlay"},
	{"NET Framework 3.5", "/Enable-Feature /FeatureName:NetFx3"},
	{"Hyper-V", "/Enable-Feature /FeatureName:Microsoft-Hyper-V"},
	{"WSL 2", "/Enable-Feature /FeatureName:Microsoft-Windows-Subsystem-Linux"},
	{"Virtual Machine Platform", "/Enable-Feature /FeatureName:VirtualMachinePlatform"},
	{"Cleanup Updates", "/Cleanup-Image /StartComponentCleanup"},
	{"Scan Health", "/Cleanup-Image /ScanHealth"},
	{"Restore Health", "/Cleanup-Image /RestoreHealth"},
	{ "TelnetClient", "/Enable-Feature /FeatureName:TelnetClient" },
	{ "TFTP", "/Enable-Feature /FeatureName:TFTP" },
	{ "LegacyComponents", "/Enable-Feature /FeatureName:LegacyComponents" }
};

static const int totalFeatures = sizeof(features) / sizeof(features[0]);

struct UserStruct
{
	unsigned short Choice;
};

	
int Installer(UserStruct& User);
void Check(UserStruct& User);


void components_page() {
	logo();
	for (int i = 1; i < totalFeatures; i++) {
		std::cout << "[" << i << "] Enable " << features[i].DisplayName << std::endl;
	}
	std::cout << "\n\033[31m Command:\033[0m ";
	UserStruct User = { 0 };
	Check(User);
}	

void RunDism(const char* Command) {
	std::string CommandCMD = "dism /online ";

	CommandCMD += Command;

	CommandCMD += " /All /NoRestart";
	int res = system(CommandCMD.c_str());

	if (res != 0) std::cout << "\033[31m[!] Critical Error Try again or Run Of admin\033[0m" << std::endl;

	if (res == 0) std::cout << "\033[32m[*] Success!\033[0m" << std::endl;

	Sleep(5000);
}

void Check(UserStruct& User) {	
	int Result = Installer(User);

	if (Result >= 1 && Result < totalFeatures) {
		RunDism(features[Result].SysName);
	}
	else if (Result != 0) {
		std::cout << "\033[33m[?] Invalid selection (Max is " << totalFeatures << ")\033[0m" << std::endl;
		Sleep(1000);
	}
}


int Installer(UserStruct &User) {
	std::cin >> User.Choice;

	if (std::cin.fail()) {
		std::cin.clear(); 
		std::cin.ignore(10000, '\n'); 
		std::cout << "\033[31m	[!] Error: Enter a number!\033[0m\n";
		Sleep(1000); 

		return 0;
	}

	return User.Choice;
}