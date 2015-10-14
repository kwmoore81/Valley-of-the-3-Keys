#pragma once
int getNumValid(int min, int max);

void mainGame();

void printFile();

void writeFile();

void clearFile();

void splScr();

void backStory();

void printTxt();

void wlkforw();

void wlkbac();

class Player
{
	int health = 100;
	int damage = 30;
};
class Bear
{
	int health = 90;
	int damage = 20;
};
class Wolf
{
	int health = 60;
	int damage = 10;
};
class Bat
{
	int health = 30;
	int damage = 5;
};

Bat blkBat();
Wolf gryWolf();
Bear BrnBear();
Player Adv();

