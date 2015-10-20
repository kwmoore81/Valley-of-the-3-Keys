#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#define _win32_winnt 0x0500
#include <Windows.h>
#include <mmsystem.h>
#include "Header.h"




int main()

{
	

	//Changes the console window size. Credit: Kevin Hunter
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 400, TRUE);

	//Menu System
	while (true)
	{
		//splash screen
		splScr();

		std::cout << "Main Menu" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2. Back Story" << std::endl;
		std::cout << "3. Back to Title Screen" << std::endl;
		std::cout << "4. Credits" << std::endl;
		std::cout << "5. Exit Game" << std::endl;
		switch (getNumValid(1, 5))
		{
		case 1: mainGame(); break;
		case 2: backStory(); break;
		case 3: splScr(); break;
		case 4: credits(); break;
		case 5: return 0;
		}
		std::cout << std::endl;
		system("cls");

	}

}
