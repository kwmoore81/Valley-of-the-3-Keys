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
int pos = 1;
int cave = 0;

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

	backStory();

	std::cout << "You find yourself at the start of the long valley. \n The caves line the valley walls with every step." << std::endl;
	system("pause");

	while (true)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Walk Forward "<< std::endl;
		std::cout << "2. Go Back" << std::endl;
		std::cout << "3. Go into the left cave" << std::endl;
		std::cout << "4. Go into the right cave" << std::endl;
	
		switch (getNumValid(1, 4))
		{
		case 1: wlkforw(); break;
		case 2: wlkbac(); break;
		case 3: splScr(); break;
		case 4: break;
		}
		std::cout << std::endl;
		system("cls");

	}

}
void wlkforw()
{
	if (pos >= 10)
	{
		std::cout << "You have reached the end of the valley" << std::endl;
		system("pause");
	}
	else
		pos++;
}
void wlkbac()
{
	if (pos <= 1)
	{
		std::cout << "You have reached the end of the valley" << std::endl;
		system("pause");
	}
	else
		pos--;
}