#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#define _win32_winnt 0x0500
#include <Windows.h>
#include <mmsystem.h>
//#include "Header.h"
#include "Main.cpp"

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

	int pos = 1;
	int lftCave = 1;
	int rtCave = 2;
	int potion = 1;
	bool bear = true;
	bool wolf = true;
	bool bat = true;
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
		std::cout << "5. Use healing item." << std::endl;
	
		switch (getNumValid(1, 5))
		{
		case 1: wlkforw(pos, lftCave, rtCave); break;
		case 2: wlkbac(pos, lftCave, rtCave); break;
		case 3: caveMenu(lftCave, potion); break;
		case 4: caveMenu(rtCave, potion); break;
		case 5: usePot(potion); break;
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

//When you find nothing in the cave
void empty()
{

	std::cout << "You don't find anything of interest in this cave " << std::endl;

	system("pause");
	system("cls");
}

//When you use a healing item
void usePot(int &a)
{
	while (a = 100)
	{
		std::cout << "You are already at full health" << std::endl;
		system("pause");
		system("cls");
		break;
		
	}
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

//The Official SFW Battle system.
void battle(Enemy E, Player P)
{
	while (&E.health > 0 || &P.health > 0 )
	{
		E.health = P.damage - E.health;
		std::cout << "You hit the enemy for " << P.damage << "damage" << std::endl;
		P.health = E.damage - P.health;
		std::cout << "The enemy hit you for " << E.damage << "damage" << std::endl;
	}

	if (P.health <= 0)
	{
		std::cout << "You have died before you could see what was behind the Door that doesn't belong. Try again... You know you want to..." << std::endl;
		system("pause");
		system("cls");
		int Main();
		
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
	
	std::cout << "You have found yourself in the den of a wolf!" << std::endl;
	system("pause");
	system("cls");
	battle(Wolf, Adv);
}
//Found a bat after searching
void batCave()
{
	std::cout << "You spot a giant bat swooping down at you from the ceiling!" << std::endl;
	system("pause");
	system("cls");
	battle(Bat, Adv);

}
//Found a bear after searching
void bearCave()
{

	std::cout << "Oh no! You have gotten to close to a mother bear's cub!" << std::endl;
	system("pause");
	system("cls");
	battle(Bear, Adv);

}
//adding a key to you're inventory
void getKey(Key a)
{
	a.haveKey = true;
}

//found the hotdog key after searcing
void hotCave()
{

	std::cout << "In the hand of a skeleton next to a shovel you spot the \n the glint of gold " << std::endl;
	system("pause");
	std::cout << "You pull the item out of the long forgotten soul's hand \n and discover that it is a Key!" << std::endl;
	system("pause");
	std::cout << "Shaped like a Hotdog.... n/  The inscription reads 'From Terry to you.'" << std::endl;
	system("pause");
	std::cout << "You arn't sure what that means but this must be a magic key! \n you swiftly pack it in your bag" << std::endl;
	system("pause");
	system("cls");
	
	getKey(Hotdog);

}

//found the Dino key after searching
void dinoCave()
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
			
		getKey(Dino);
	}

	else
	{
		
		std::cout << "The T-Rex shaped key speaks to you in a growling voice. \n 'Only those who have proven their might may win me and take me to the Door that does not Belong.'" << std::endl;
		system("pause");
		std::cout << "As you reach for the key, out of no where the key opens it's jewel encrusted mouth and bites your hand!" << std::endl;
		system("pause");
		std::cout << "You take 5 Damage..." << std::endl;

		Adv.health = Adv.damage - 5;
		system("pause");
		

	}

}

//found the Tim key after searching
void timCave()
{

	std::cout << "You look around and in the corner you find a chest... a child's toy chest." << std::endl;
	system("pause");
	std::cout << "You open the lid slowly, and at the very bottom the the chest is a small key in the shape of an alpaca." << std::endl;
	system("pause");
	std::cout << "As you bring the key into the light you noticed the name 'Tim' \n etched on the side in what can only be crayon." << std::endl;
	system("pause");
	std::cout << "You carfully place the key in your bag. \n One step closer to your goal!" << std::endl;
	system("pause");
	system("cls");
		getKey(Tim);
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
	system("pause");
	std::cout << "However, in the center of this cave.. Attached to nothing, and standing freely, is a door" << std::endl;
	system("pause");
	std::cout << "This door look like any other door you've seen in your life, but it seems to lead to no where. \n Just free standing in the center of the room." << std::endl;
	system("pause");
	std::cout << "The only real unusual thing about this ordinary door is the three keyholes under the knob" << std::endl;
	
	if (Hotdog.haveKey == true && Dino.haveKey == true && Tim.haveKey == true)
	{
		std::cout << "You place all three keys into the keyholes and turn the knob..." << std::endl;
		system("pause");
		std::cout << "The door slowly creaks open..." << std::endl;
		system("pause");
		system("cls");

		std::cout << "A bright light beams from the open door. You sheild your eyes and walk though." << std::endl;
		system("pause");
		std::cout << "As your eyes get used to the light I find that you're standing in front of a desk with a monitor and keyboard." << std::endl;
		system("pause");
		std::cout << "The words on the screen say, 'Now it's time to tell your story.' \n below that is a single line that reads '#include<string>'." << std::endl;
		system("pause");
		std::cout << "you sit down at the desk and this is what you write: " << std::endl;
		system("pause");
		system("cls");
		main();
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
	while (true)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Search the Cave" << std::endl;
		std::cout << "2. Go Back to the Valley" << std::endl;
		std::cout << "3. Use First Aid/Potion" << std::endl;
		
		switch (getNumValid(1, 3))
		{
		case 1: caveList(a , b); break;
		case 2:  break;
		case 3: usePot(b); break;
		
		}
		std::cout << std::endl;
		system("cls");

	}
}

//The cave switchboard.
void caveList(int &a, int &b)
{
	while (true)
	{

		switch (getNumValid(1, 20))
		{
		case 1: empty(); break;
		case 2: wolfCave(); break;//wolf
		case 3: empty(); break;
		case 4: empty(); break;
		case 5: hotCave(); break;//key
		case 6: empty(); break;
		case 7: empty(); break;
		case 8: potionCave(b); break;//potion
		case 9: batCave(); break;//Bat
		case 10: empty(); break;
		case 11: doorCave(); break;//door
		case 12: potionCave(b); break;//potion
		case 13: empty(); break;
		case 14: empty(); break;
		case 15: dinoCave(); break;//key
		case 16: bearCave(); break;//bear
		case 17: empty(); break;
		case 18:potionCave(b); break;//potion
		case 19: timCave(); break;//key
		case 20: empty(); break;
		}
		std::cout << std::endl;
		system("cls");
	}

}