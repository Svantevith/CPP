#pragma once
#include <string>
#include <unordered_map>

#include "hero.h"

using namespace std;

class Profession : public Hero
{
protected:
	string profession;
	int toLevelUp;
	std::unordered_map<string, int> skills;

public:

	unordered_map<string, int> getSkills()
	{
		return this->skills;
	}

	virtual void setSkills() = 0;

	void isLevelUp();

	virtual void assignDefaultStatistics() override;

	virtual int attackInBattle() override;

	void newHero();

	virtual void displayStatistics() override;

	virtual void saveToFile() override;

	virtual void loadFromFile(int heroNumber, std::string& heroFilename) override;

	static std::string checkForProfession(std::string &filename);

	void increaseLevel();

	std::string getProfession();
	int get_toLevelUp();

	void setProfession(std::string& x);
	void set_toLevelUp();
	
};