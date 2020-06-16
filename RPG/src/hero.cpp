#include<iostream>
#include<string>

#include "hero.h"

using namespace std;

int Hero::defenceInBattle(int& damage)
{
	this->health -= damage;
	if (this->isGameOver())
	{
		return 0;
	}
	else
	{
		cout << this->name << "'s remaining health: " << this->health << endl;
	}
	return this->health;
}

bool Hero::isGameOver()
{
	if (this->health <= 0)
	{
		cout << endl << this->name << " was killed..." << endl << endl;
		return true;
	}
	return false;
}

int Hero::getLevel()
{
	return this->level;
}
void Hero::levelUp()
{
	this->level++;
}

int Hero::getExperience()
{
	return this->experience;
}

void Hero::setExperience(int& x)
{
	this->experience = x;
}

int Hero::getAttack()
{
	return this->attack;
}

int Hero::getHealth()
{
	return this->health;
}

std::string Hero::getName()
{
	return this->name;
}
int Hero::getVitality()
{
	return this->vitality;
}
int Hero::getStrength()
{
	return this->strength;
}
int Hero::getDexterity()
{
	return this->dexterity;
}
int Hero::getEndurance()
{
	return this->endurance;
}
int Hero::getWisdom()
{
	return this->wisdom;
}
int Hero::getCharisma()
{
	return this->charisma;
}
void Hero::setName(std::string& x)
{
	this->name = x;
}
void Hero::setVitality(int& x)
{
	this->vitality = x;
}
void Hero::setStrength(int& x)
{
	this->strength = x;
}
void Hero::setDexterity(int& x)
{
	this->dexterity = x;
}
void Hero::setEndurance(int& x)
{
	this->endurance = x;
}
void Hero::setWisdom(int& x)
{
	this->wisdom = x;
}
void Hero::setCharisma(int& x)
{
	this->charisma = x;
}