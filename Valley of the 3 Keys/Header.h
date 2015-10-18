#pragma once
int getNumValid(int min, int max);

int main();

void mainGame();

void randRoom();

void splScr();

void backStory();

void printTxt();

void wlkforw(int &a, int &b, int &c);

void wlkbac(int &a, int &b, int &c);

void caveMenu(int &a, int &b);

void caveList(int &a, int &b);

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

void battle(class Enemy , class Player);


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
Enemy Bear = { 90, 20 };
Enemy Wolf = { 60 , 10 };
Enemy Bat = { 30 , 5 };
Key Hotdog;
Key Dino;
Key Tim;


