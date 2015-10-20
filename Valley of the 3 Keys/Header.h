#pragma once
int getNumValid(int min, int max);

void mainGame();

void splScr();

void backStory();

void credits();

void printTxt();

void wlkforw(int &a, int &b, int &c);

void wlkbac(int &a, int &b, int &c);

void caveMenu(int &a, int &b);

void caveList(int &a, int &b);

void status(int p);

void empty();

void usePot(int &a);

void wolfCave();

void batCave();

void bearCave();

void hotCave();

void dinoCave();

void timCave();

void getKey(class Key);

void potionCave(int &b);

void doorCave();

void otherSide();

void battle(class Enemy E, class Player &Adv);


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




