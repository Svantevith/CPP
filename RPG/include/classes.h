#pragma once
#include<unordered_map>

#include"profession.h"

using namespace std;

class Mage : public virtual Profession
{
public:
	virtual void assignDefaultStatistics() override
	{
		Profession::assignDefaultStatistics();
		wisdom = 10;
		profession = "Mage";
		setSkills();
	}

	virtual void setSkills() override
	{
		skills["Lava Burst"] = 5 * wisdom * attack;
		skills["Blizzard"] = 5 * wisdom * endurance;
	}
};

class Warrior : public virtual Profession
{
public:
	virtual void assignDefaultStatistics() override
	{
		Profession::assignDefaultStatistics();
		endurance = 10;
		profession = "Warrior";
		skills["Swordspin"] = 5 * strength * attack;
		skills["Blood Thirst"] = 5 * strength * endurance;
	}

	virtual void setSkills() override
	{
		skills["Swordspin"] = 5 * strength * attack;
		skills["Blood Thirst"] = 5 * strength * endurance;
	}

};

class Berserker : public virtual Profession
{
public:
	virtual void assignDefaultStatistics() override
	{
		Profession::assignDefaultStatistics();
		strength = 10;
		profession = "Berserker";
		skills["Shadow Charge"] = 5 * dexterity * attack;
		skills["Lightning"] = 5 * wisdom * strength;
	}

	virtual void setSkills() override
	{
		skills["Shadow Charge"] = 5 * dexterity * attack;
		skills["Lightning"] = 5 * wisdom * strength;
	}
};

class Thief : public virtual Profession
{
public:
	virtual void assignDefaultStatistics() override
	{
		Profession::assignDefaultStatistics();
		dexterity = 10;
		profession = "Thief";
		skills["Backstab"] = 5 * dexterity * attack;
		skills["Poison Cloud"] = 5 * strength * dexterity;
	}

	virtual void setSkills() override
	{
		skills["Backstab"] = 5 * dexterity * attack;
		skills["Poison Cloud"] = 5 * strength * dexterity;
	}
};