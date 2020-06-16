#include <iostream>
#include <ctime>
#include <memory>

#include "hero.h"
#include "monster.h"
#include "classes.h"

using namespace std;

template<class H, class E>
void battle(unique_ptr<H>& pHero, unique_ptr<E>& pEnemy);

template<class F, class S>
void battleTurn(unique_ptr<F>& first_attacker, unique_ptr<S>& second_attacker);

template<class H, class E>
void loadGame(string& heroFilename);

template<class H, class E>
void newGame();

template<class H, class E>
void Game(unique_ptr<H>& pHero);

int main()
{
	srand(time(NULL));

	cout << "Would you like to load previous state?" << endl;
	int userInput = 0;
	while (true)
	{
		cout << "1. Yes" << endl << "2. No" << endl;
		cin >> userInput;
		if (!(userInput == 1 || userInput == 2))
		{
			cout << "Your input should be either 1 or 2" << endl;
			continue;
		}
		break;
	}

	if (userInput == 1)
	{
		cout << endl << "Next character will be loaded now..." << endl << endl;
		
		cout << "Enter the name of character, you would like to load: ";	
		string heroFilename = "";
		cin >> heroFilename;
		heroFilename.append(".txt");

		string profession = Profession::checkForProfession(heroFilename);
		
		if (profession == "Mage")
		{
			loadGame<Mage, Monster>(heroFilename);
		}
		else if (profession == "Warrior")
		{
			loadGame<Warrior, Monster>(heroFilename);
		}
		else if (profession == "Berserker")
		{
			loadGame<Berserker, Monster>(heroFilename);
		}
		else if (profession == "Thief")
		{
			loadGame<Thief, Monster>(heroFilename);
		}
	}
	else if (userInput == 2)
	{
		cout << "Choose the profession: " << endl;
		cout << "1. Mage" << endl << "2. Warrior" << endl << "3. Berserker" << endl << "4. Thief" << endl;
		
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			newGame<Mage, Monster>();
			break;
		}
		case 2:
		{
			newGame<Warrior, Monster>();
			break;
		}
		case 3:
		{
			newGame<Berserker, Monster>();
			break;
		}
		case 4:
		{
			newGame<Thief, Monster>();
			break;
		}
		default:
		{
			cout << "Please choose one of the existing professions." << endl;
			break;
		}
		}
	}

return 0;
}




template<class H, class E>
void battle(unique_ptr<H> &rHero, unique_ptr<E> &rEnemy)
{
	cout << "Oh no, " << rHero->getName() << " got in the way of " << rEnemy->getName() << "!" << endl;
	cout << rHero->getName() << "'s health: " << rHero->getHealth() << " HP" << endl;
	cout << rEnemy->getName() << "'s health: " << rEnemy->getHealth() << " HP" << endl;

	if (rHero->getCharisma() < rEnemy->getCharisma())
	{
		cout << rHero->getName() << " is more agrresive and is well known by his brutal attitude against monsters..." << endl;
		battleTurn<H, E>(rHero, rEnemy);
	}
	else
	{
		cout << rEnemy->getName() << " is thinking about making a slaughter on " << rHero->getName() << "..." << endl;
		battleTurn<E, H>(rEnemy, rHero);
	}
}

template<class F, class S>
void battleTurn(unique_ptr<F> &first_attacker, unique_ptr<S> &second_attacker)
{
	int damage_first = 0;
	int damage_second = 0;

	while (first_attacker->getHealth() > 0 && second_attacker->getHealth() > 0)
	{
		damage_first = first_attacker->attackInBattle();
		if (second_attacker->defenceInBattle(damage_first) > 0)
		{
			damage_second = second_attacker->attackInBattle();
			if (first_attacker->defenceInBattle(damage_second) <= 0)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}

template<class H, class E>
void loadGame(string &heroFilename)
{
	H hero;
	auto pHero = make_unique<H>(hero);
	pHero->loadFromFile(1, heroFilename);
	pHero->setSkills();
	pHero->displayStatistics();
	Game<H, E>(pHero);
}

template<class H, class E>
void newGame()
{
	H hero;
	auto pHero = make_unique<H>(hero);
	pHero->newHero();
	pHero->displayStatistics();
	Game<H, E>(pHero);
}

template<class H, class E>
void Game(unique_ptr<H> &pHero)
{
	vector<E> monsters = E::newMonsters();
	for (auto& monster : monsters)
	{
		monster.displayStatistics();
	}

	auto iMonster = monsters.begin() + rand() % monsters.size();
	unique_ptr<E> pEnemy = make_unique<E>(*iMonster);

	battle<H, E>(pHero, pEnemy);
	if (pHero->getHealth() > 0)
	{
		cout << pHero->getName() << " has obtained " << pEnemy->getExperience() << " experience" << endl;
		int gathered_exp = pEnemy->getExperience();
		pHero->setExperience(gathered_exp);
		pHero->isLevelUp();
	}
	else
	{
		cout << "Game Over" << endl;
		return;
	}
	pHero->saveToFile();
	E::saveAllMonsters(monsters);
	cout << "All of your progress was successfully saved. Press any key to exit" << endl;
}
