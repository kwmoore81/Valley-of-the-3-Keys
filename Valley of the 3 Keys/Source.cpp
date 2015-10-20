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

Player Adv = { 100 , 30 };
Enemy Bear = { 90, 20 };
Enemy Wolf = { 60 , 10 };
Enemy Bat = { 30 , 5 };
Key Hotdog;
Key Dino;
Key Tim;
bool bearAlive = true;
bool wolfAlive = true;
bool batAlive = true;
bool pot8 = true;
bool pot12 = true;
bool pot18 = true;
bool playerAlive = true;

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

void credits()
{
	std::cout << std::endl;
	std::cout << "Game Design - Kevin Moore \n \n Programming - Kevin Moore \n \n Special Thanks to Tim." << std::endl;
	std::cout << std::endl;
	system("pause");
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
	std::cout << "Please give your adventurer a name." << std::endl;
	writeFile();

	Adv.health = 100;
	Bear.health = 90;
	Wolf.health = 60;
	Bat.health = 30;
	Hotdog.haveKey = false;
	Dino.haveKey = false;
	Tim.haveKey = false;

	int pos = 1;
	int lftCave = 1;
	int rtCave = 2;
	int potion = 1;
	bearAlive = true;
	wolfAlive = true;
	batAlive = true;
	
	backStory();

	std::cout << "You find yourself at the start of the long valley. \n The caves line the valley walls with every step." << std::endl;
	system("pause");

	//Game Play Menu
	while (playerAlive)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Walk Forward " << std::endl;
		std::cout << "2. Go Back" << std::endl;
		std::cout << "3. Go into cave #" << lftCave << std::endl;
		std::cout << "4. Go into cave #" << rtCave << std::endl;
		std::cout << "5. Use healing item." << std::endl;
		std::cout << "6. Player Status." << std::endl;
		
		switch (getNumValid(1, 6))
		{
			
		case 1: wlkforw(pos, lftCave, rtCave); break;
		case 2: wlkbac(pos, lftCave, rtCave); break;
		case 3: caveMenu(lftCave, potion); break;
		case 4: caveMenu(rtCave, potion); break;
		case 5: usePot(potion); break;
		case 6: status(potion); break;
		}
		std::cout << std::endl;
		system("cls");

	}


	// RESET OUR FILE GLOBALS HERE FOR THE NEXT GAME
	playerAlive = true;
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

	//Show you the status of the player.

	void status(int p)
	{
		int key = 0;
		if (Hotdog.haveKey == true) { key++; }
		if (Dino.haveKey == true) { key++; }
		if (Tim.haveKey == true) { key++; }
		std::cout << std::endl;
		std::cout << "Player Health: " << Adv.health << std::endl;
		std::cout << "Weapon: Sharp Dagger - 30 Damage" << std::endl;
		std::cout << "Lockpick: Trusty Lockpick" << std::endl;
		std::cout << "Healing Items: " << p << std::endl;
		std::cout << "Keys: " << key << std::endl;
		system("pause");
		system("cls");

	}
	//When you find nothing in the cave
	void empty()
	{

		std::cout << "You don't find anything of interest in this cave." << std::endl;

		system("pause");
		system("cls");
	}

	//When you use a healing item
	void usePot(int &a)
	{
		while (Adv.health == 100)
		{
			std::cout << "You are already at full health." << std::endl;
			system("pause");
			system("cls");
			break;

		}
		if (Adv.health < 100)
		{
			if (a > 0)
			{
				Adv.health = 100;
				std::cout << "Your health has been restored to full!" << std::endl;

				--a;
				system("pause");
				system("cls");
			}

			else
			{
				std::cout << "You are out of all healing items" << std::endl;
				system("pause");
				system("cls");
			}
		}
	}

	//The Official SFW Battle system.
	void battle(Enemy E, Player &Adv)
	{
		while (E.health > 0 || Adv.health > 0)
		{
			Adv.health -= E.damage;
			std::cout << "The enemy hit you for " << E.damage << "damage." << std::endl;
			E.health -= Adv.damage;
			std::cout << "You hit the enemy for " << Adv.damage << "damage." << std::endl;


			if (E.health <= 0 || Adv.health <= 0) { break; }
		}

		if (Adv.health <= 0)
		{
			std::cout << "You have died before you could see what was behind the Door that doesn't belong. Try again... You know you want to..." << std::endl;
			system("pause");
			system("cls");
			;
			playerAlive = false;
		}

		else
		{
			
			std::cout << "You have defeated your foe!" << std::endl;
			system("pause");
			system("cls");

		}

		system("cls");
	}

	//Found a wolf after searching
	void wolfCave()
	{
		if (wolfAlive == true)
		{

			std::cout << "You have found yourself in the den of a wolf!" << std::endl;
			system("pause");
			system("cls");
			battle(Wolf, Adv);
			wolfAlive = false;
		}

		else
		{
			std::cout << "All that's left is the body of the wolf you defeated" << std::endl;
			system("pause");
			system("cls");
		}
	}
	//Found a bat after searching
	void batCave()
	{
		if (batAlive == true)
		{
			std::cout << "You spot a giant bat swooping down at you from the ceiling!" << std::endl;
			system("pause");
			system("cls");
			battle(Bat, Adv);
			batAlive = false;
		}

		else
		{
			std::cout << "All you can see is the shredded carcuss of the bat you took down." << std::endl;
			system("pause");
			system("cls");
		}
	}
	//Found a bear after searching
	void bearCave()
	{
		if (bearAlive == true)
		{
			std::cout << "Oh no! You've gotten to close to a mother bear's cub!" << std::endl;
			system("pause");
			system("cls");
			battle(Bear, Adv);
			bearAlive = false;
		}

		else 
		{
			std::cout << "You watch as the poor bear cub mourns the death of its mother." << std::endl;
			system("pause");
			system("cls");
		}
	}

	void hotCave()
	{
		if (Hotdog.haveKey == false)
		{
			std::cout << "In the hand of a skeleton next to a shovel you spot the \n the glint of gold " << std::endl;
			system("pause"); system("cls");
			std::cout << "You pull the item out of the long forgotten soul's hand \n and discover that it is a Key!" << std::endl;
			system("pause"); system("cls");
			std::cout << "Shaped like a Hotdog.... \n  The inscription reads 'From Terry to you.'" << std::endl;
			system("pause"); system("cls");
			std::cout << "You arn't sure what that means, but this must be a magic key! \n You swiftly pack it in your bag" << std::endl;
			system("pause");
			system("cls");

			Hotdog.haveKey = true;
		}

		else
		{

			std::cout << "The poor soul that died getting this first key is all that remains here." << std::endl;
			system("pause");
			system("cls");

		}
	}

	//found the Dino key after searching
	void dinoCave()
	{
		if (Dino.haveKey == false)
		{

			std::cout << "You see a very large and strangly intimidating key sitting atop a pedestal." << std::endl;
			system("pause");
			std::cout << "The Tyrannosaurus Rex shaped key begins to stir and SPEAK!." << std::endl;
			system("pause");
			system("cls");

			if (Hotdog.haveKey == true && Tim.haveKey == true)
			{

				std::cout << "The T-Rex shaped key speaks to you in a growling voice. \n 'You have proven your worth by taming my brother keys.' \n 'Now take us to the Door that does not Belong.'" << std::endl;
				system("pause");

				Dino.haveKey = true;

			}

			else
			{

				std::cout << "The T-Rex shaped key speaks to you in a growling voice. \n 'Only those who have proven their might may win me and take me to the Door that does not Belong.'" << std::endl;
				system("pause");
				std::cout << "As you reach for the key, out of nowhere the key opens it's jewel encrusted \n mouth and bites your hand!" << std::endl;
				system("pause");
				std::cout << "You take 5 Damage..." << std::endl;

				Adv.health-= 5;
				system("pause");

			}
		}

		else
		{

			std::cout << "All that remains is the empty pedestal." << std::endl;
			system("pause");
			system("cls");
		}

	}

	//found the Tim key after searching
	void timCave()
	{
		if (Tim.haveKey == false)
		{
			std::cout << "You look around, and in the corner you find a chest... A child's toy chest." << std::endl;
			system("pause"); system("cls");
			std::cout << "You use your trusty lockpick and open the lid slowly, \nand at the very bottom the the chest is a small key in the shape of an alpaca." << std::endl;
			system("pause"); system("cls");
			std::cout << "As you bring the key into the light, you noticed the name 'Tim' \n etched on the side in what can only be crayon." << std::endl;
			system("pause"); system("cls");
			std::cout << "You carfully place the key in your bag. \n One step closer to your goal!" << std::endl;
			system("pause"); system("cls");
			Tim.haveKey = true;
		}

		else 
		{  
		
			std::cout << "All that remains is a empty toy box." << std::endl;
			system("pause");
			system("cls");
		}
	}

	//found a potion after searching
	void potionCave(int &b)
	{
			std::cout << "You have found an rare elixir of healing! \n You smile at your good fortune and put it in your bag." << std::endl;
			system("pause");
			++b;
			system("cls");		
	}

	//found the door after searching
	void doorCave()
	{
		std::cout << "You step into a cave that looks much like \n the many other's you've seen on your quest thus far." << std::endl;
		system("pause"); system("cls");
		std::cout << "However, in the center of this cave.. Attached to nothing, and standing freely, is a door" << std::endl;
		system("pause"); system("cls");
		std::cout << "This door looks like any other door you've seen in your life, but it seems \n to lead to nowhere. \n Just free standing in the center of the room." << std::endl;
		system("pause"); system("cls");
		std::cout << "The only real unusual thing about this ordinary door is the three keyholes under the knob." << std::endl;
		system("pause"); system("cls");

		if (Hotdog.haveKey == true && Dino.haveKey == true && Tim.haveKey == true)
		{
			std::cout << "You place all three keys into the keyholes and turn the knob..." << std::endl;
			system("pause"); system("cls");
			std::cout << "The door slowly creaks open..." << std::endl;
			system("pause"); system("cls");

			std::cout << "A bright light beams from the open door. You shield your eyes and walk though." << std::endl;
			system("pause"); system("cls");
			std::cout << "As your eyes get used to the light, you find that you're standing in front of a\ndesk with a monitor and keyboard." << std::endl;
			system("pause"); system("cls");
			std::cout << "The words on the screen say, 'Now it's time to tell your story', "; printFile(); 
			system("cls");
			std::cout <<"\n Below that is a single line that reads: \n\n#include <string> \n" << std::endl;
			system("pause"); system("cls");
			std::cout << "You sit down at the desk and this is what you write... " << std::endl;
			system("pause");
			system("cls");
			
			playerAlive = false;
		}

		else
		{
			std::cout << "You turn the knob with all your strength, but it's no use..." << std::endl;
			system("pause");
			system("cls");
		}
	}

	//The Menu while you are in a cave.
	void caveMenu(int &a, int &b)
	{
		bool inCave = true;
		while (inCave && playerAlive)
		{
			std::cout << "What do you want to do?" << std::endl;
			std::cout << std::endl;
			std::cout << "1. Search the Cave" << std::endl;
			std::cout << "2. Go Back to the Valley" << std::endl;
			std::cout << "3. Use First Aid/Potion" << std::endl;
			std::cout << "4. Player Status." << std::endl;

			switch (getNumValid(1, 4))
			{
			case 1: caveList(a, b); break;
			case 2:  inCave = false; break;
			case 3: usePot(b); break;
			case 4: status(b); break;

			}
			std::cout << std::endl;
			system("cls");

		}
	}

	//The cave switchboard.
	void caveList(int &a, int &b)
	{

		// switchhhhhhh<3

		if (a == 1) { empty(); }
		else if (a == 2) { wolfCave(); }
		else if (a == 3) { empty(); }
		else if (a == 4) { empty(); }
		else if (a == 5) { hotCave(); }
		else if (a == 6) { empty(); }
		else if (a == 7) { empty(); }
		else if (a == 8)
		{
			if (pot8) 
			{
				pot8 = false;
				potionCave(b);
			}
			else
			{
				empty();
			}
		}
		else if (a == 9) { batCave(); }
		else if (a == 10) { empty(); }
		else if (a == 11) { doorCave(); }
		else if (a == 12)
		{
			if (pot12)
			{
				pot12 = false;
				potionCave(b);
			}
			else
			{
				empty();
			}
		}
		else if (a == 13) { empty(); }
		else if (a == 14) { empty(); }
		else if (a == 15) { dinoCave(); }
		else if (a == 16) { bearCave(); }
		else if (a == 17) { empty(); }
		else if (a == 18)
		{
			if (pot18)
			{
				pot18 = false;
				potionCave(b);
			}
			else
			{
				empty();
			}
		}
		else if (a == 19) { timCave(); }
		else if (a == 20) { empty(); }

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