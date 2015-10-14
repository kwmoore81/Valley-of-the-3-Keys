#pragma once
int getNumValid(int min, int max);

void mainGame();

void randRoom();

void printFile();

void writeFile();

void clearFile();

void splScr();

void backStory();

void printTxt();

void wlkforw(int &a, int &b, int &c);

void wlkbac(int &a, int &b, int &c);

void caveMenu(int &a);

void caveList(int &a);

void empty();

void usePot();

class Player
{
public:
	int health;
	int damage;
};
class Enemy
{
public:
	int health;
	int damage;
};
class Key
{
public:
	bool haveKey = false;
};

Player Adv = { 100 , 30 };
//Enemy Bear = { 90, 20 };
//Enemy Wolf = { 60 , 10 };
//Enemy Bat = { 30 , 5};
//Key Hotdog;
//Key Dino;
//Key Tim;



