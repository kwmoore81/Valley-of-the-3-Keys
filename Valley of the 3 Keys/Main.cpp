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
void printFile()
{


	std::fstream fin;
	fin.open("MyLog.txt", std::ios_base::out | std::ios_base::in);
	char input[128];
	while (fin.getline(input, 128))
	{
		std::cout << input << std::endl;

		system("pause");
		fin.close();
	}
}

void writeFile()
{
	std::fstream fout;
	fout.open("MyLog.txt", std::ios_base::out | std::ios_base::app);
	char input[128];

	if (fout.is_open())
	{
		std::cin.getline(input, 128);	// accepts user input and puts it into a buffer
		fout << input << std::endl;	// write to the file
		fout.flush();	// flush the write buffer, writing everything we haven't
		fout.close();	// close the file stream

	}
}

void clearFile()
{
	std::fstream file;
	file.open("MyLog.txt", std::ios_base::out);
	if (file.is_open())
	{

	}
	file.close();
}