#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#define _win32_winnt 0x0500
#include <Windows.h>
#include <mmsystem.h>
#include "Header.h"



//Player Adv;
//Enemy Bear;
//Enemy Wolf;
//Enemy Bat;


int main()

{
	Adv.health = 100;
	//Adv.damage = 30;
	Bear.health = 90;
	//Bear.damage = 20;
	Wolf.health = 60;
	//Wolf.damage = 10;
	Bat.health = 30;
	//Bat.damage = 5;
	Hotdog.haveKey = false;
	Dino.haveKey = false;
	Tim.haveKey = false;

	//Changes the console window size. Credit: Kevin Hunter
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 400, TRUE);

	splScr();

	//Menu System
	while (true)
	{
		std::cout << "Main Menu" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2 .Instructions & Credits" << std::endl;
		std::cout << "3. Back to Title Screen" << std::endl;
		std::cout << "4. Exit Game" << std::endl;
		switch (getNumValid(1, 4))
		{
		case 1: mainGame(); break;
		case 2: backStory(); break;
		case 3: splScr(); break;
		case 4: return 0;
		}
		std::cout << std::endl;
		system("cls");

	}

}
