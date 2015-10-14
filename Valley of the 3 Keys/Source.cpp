#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#define _win32_winnt 0x0500
#include <Windows.h>
#include <mmsystem.h>
#include "Header.h"

char fileName[64] = { '\0' };



int getNumValid(int min, int max)
{
	int select;
	do
	{
		std::cout << "Enter a Valid Number (" << min << "," << max << "): ";
		std::cin >> select;

		std::cin.clear();
		std::cin.ignore(80, '\n');

		if (std::cin.fail() || select < min || select > max)
		{
			std::cout << "invalid entry." << std::endl;
		}
		else break;
	} while (true);
	return select;
}

//Splash Screen with help from http://www.network-science.de/ascii/
void splScr()
{
		strcpy_s(fileName, "Splash.txt");
		printTxt();
		system("CLS");
} 


//text for the backstory
void backStory()
{
	strcpy_s(fileName, "Back Story.txt");
	printTxt();
	system("cls");
}

//prints an entire txt file to the console.
void printTxt()
{
	system("cls");
	std::string line_;
	std::ifstream file_(fileName);
	if (file_.is_open())
	{
		while (std::getline(file_, line_))
		{
			std::cout << line_ << '\n';

		}
		file_.close();
		system("pause");

	}
	else
		std::cout << "file error" << std::endl;

}



void mainGame()
{

	/*int roomArray[20];

	for (int i = 0; i < 20; ++i)
	{
		roomArray[i] = 0;
		for (int i = 0; i < 20; ++i)
		{
			roomArray[i] = rand() % 20 +1;
			std::cout << roomArray[i] << std::endl;
		}
	}*/
	
	
	int pos = 1;
	int lftCave = 1;
	int rtCave = 2;
	int potion = 1;
	backStory();

	std::cout << "You find yourself at the start of the long valley. \n The caves line the valley walls with every step." << std::endl;
	system("pause");

	//Game Play Menu
	while (true)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Walk Forward "<< std::endl;
		std::cout << "2. Go Back" << std::endl;
		std::cout << "3. Go into cave #" << lftCave << std::endl;
		std::cout << "4. Go into cave #" << rtCave << std::endl;
	
		switch (getNumValid(1, 4))
		{
		case 1: wlkforw(pos, lftCave, rtCave); break;
		case 2: wlkbac(pos, lftCave, rtCave); break;
		case 3: caveMenu(lftCave, potion); break;
		case 4: caveMenu(rtCave, potion); break;
		}
		std::cout << std::endl;
		system("cls");

	}

}
//Handles Walking Forward
void wlkforw(int &a, int &b, int &c)
{
	if (a >= 10)
	{
		std::cout << "You have reached the end of the valley" << std::endl;
		system("pause");
	}
	else
	{
		a++;
		b = b + 2;
		c = c + 2;
	}
	
}
//Handles Walking Backward
void wlkbac(int &a, int &b, int &c)
{
	if (a <= 1)
	{
		std::cout << "You have reached the end of the valley" << std::endl;
		system("pause");
	}
	else
	{
		a--;
		b = b - 2;
		c = c - 2;
	}
}


void empty()
{

	std::cout << "You don't find anything of interest in this cave " << std::endl;

	system("pause");
	system("cls");
}

void usePot(int &a)
{
	if (a = 100)
	{
	
	}
	if (a > 0)
	{
		Adv.health = 100;
		std::cout << "Your health has been restored to full!" << std::endl;

		--a;
	}

	else
	{
		std::cout << "You are out of all healing items" << std::endl;
	}
}

void caveMenu(int &a,  int &b)
{
	while (true)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Search the Cave" << std::endl;
		std::cout << "2. Go Back to the Vally" << std::endl;
		std::cout << "3. Use First Aid/Potion" << std::endl;
		//std::cout << "4. Go into cave #" << rtCave << std::endl;

		switch (getNumValid(1, 4))
		{
		case 1: caveList(a); break;
		case 2:  break;
		case 3: usePot(b); break;
		//case 4: caveMenu(rtCave); break;
		}
		std::cout << std::endl;
		system("cls");

	}
}

void caveList(int &a)
{
	while (true)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Walk Forward " << std::endl;
		std::cout << "2. Go Back" << std::endl;
		std::cout << "3. Go into cave #" << lftCave << std::endl;
		std::cout << "4. Go into cave #" << rtCave << std::endl;

		switch (getNumValid(1, 20))
		{
		case 1: empty(); break;
		case 2: wlkbac(pos, lftCave, rtCave); break;//wolf
		case 3: empty(); break;
		case 4: empty(); break;
		case 5: wlkforw(pos, lftCave, rtCave); break;//key
		case 6: empty(); break;
		case 7: empty(); break;
		case 8: caveMenu(rtCave); break;//potion
		case 9: wlkforw(pos, lftCave, rtCave); break;//Bat
		case 10: empty(); break;
		case 11: caveMenu(lftCave); break;//door
		case 12: caveMenu(rtCave); break;//potion
		case 13: empty(); break;
		case 14: empty(); break;
		case 15: caveMenu(lftCave); break;//key
		case 16: caveMenu(rtCave); break;//bear
		case 17: empty(); break;
		case 18: wlkbac(pos, lftCave, rtCave); break;//potion
		case 19: caveMenu(lftCave); break;//key
		case 20: empty(); break;
		}
		std::cout << std::endl;
		system("cls");

}