#pragma once
#include <vector>

#include "hero.h"

class Monster : public Hero
{
public:
	Monster();
	virtual void assignDefaultStatistics() override;

	virtual int attackInBattle() override;

	virtual void displayStatistics() override;

	static std::vector<Monster> oldMonsters();
	
	static std::vector<Monster> newMonsters();

	virtual void loadFromFile(int monsterNumber, std::string& monstersFilename);

	virtual void saveToFile() override;

	static void saveAllMonsters(std::vector<Monster>& monsters);
};