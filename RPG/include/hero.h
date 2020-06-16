#pragma once
#include <string>

class Hero
{
protected:
	std::string name;
	int vitality;
	int strength;
	int dexterity;
	int endurance;
	int wisdom; //wisdom is intelligence
	int charisma;
	
	int level;
	int experience;
	int attack;
	int health;

public:
	virtual void assignDefaultStatistics() = 0;

	virtual int attackInBattle() = 0;

	int defenceInBattle(int& damage);

	void levelUp();

	bool isGameOver();

	virtual void saveToFile() = 0;

	virtual void displayStatistics() = 0;

	virtual void loadFromFile(int number, std::string& filename) = 0;

	std::string getName();
	int getVitality();
	int getStrength();
	int getDexterity();
	int getEndurance();
	int getWisdom();
	int getCharisma();
	
	int getLevel();
	int getExperience();
	int getAttack();
	int getHealth();

	void setName(std::string& x);
	void setVitality(int& x);
	void setStrength(int& x);
	void setDexterity(int& x);
	void setEndurance(int& x);
	void setWisdom(int& x);
	void setCharisma(int& x);

	void setExperience(int& x);
};
