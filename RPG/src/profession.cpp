#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <ctime>

#include "hero.h"
#include "profession.h"

using namespace std;

void Profession::assignDefaultStatistics()
{
    name = "Hero";
    vitality = 100;
    strength = 5;
    dexterity = 5;
    endurance = 5;
    wisdom = 5;
    charisma = 5;
    profession = "This Hero has not chosen his destiny yet.";

    level = 1;
    experience = 0;
    attack = level * (strength + dexterity);
    health = level * vitality * endurance;
}

int Profession::attackInBattle()
{
    auto skill_it = skills.begin();

    int damage = 0;
    int dice = rand() % 2;
    if (dice != 0)
    {
        skill_it = --skills.end();
    }
    cout << this->name << " uses " << skill_it->first << "!" << endl;

    dice = rand() % 6 + 1;
    double bonus = 0;
    if (dice == 1)
    {
        bonus = 0;
    }
    else if (dice == 2)
    {
        bonus = 1.1;
    }
    else if (dice == 3)
    {
        bonus = 1.2;
    }
    else if (dice == 4)
    {
        bonus = 1.3;
    }
    else if (dice == 5)
    {
        bonus = 1.4;
    }
    else
    {
        bonus = 1.5;
    }

    damage = bonus * skill_it->second;

    if (damage > 0)
    {
        cout << this->name << " gives " << damage << " damage!" << endl;
    }
    else
    {
        cout << this->name << " misses!" << endl;
    }
    return damage;
    return 0;
}

void Profession::isLevelUp()
{
    int prev_exp = 0;

    while (experience >= toLevelUp)
    {
        toLevelUp = prev_exp + level * 5;
        if (experience >= toLevelUp)
        {
            level++;
            cout << endl << "LEVEL UP!" << endl;
            cout << name << "'s level has increased to " << level << endl << endl;
            if (experience == toLevelUp)
            {
                experience = 0;
                break;
            }
            else if (experience > toLevelUp)
            {
                experience -= toLevelUp;
                prev_exp = toLevelUp;
            }

        }
        else if (experience < toLevelUp)
        {
            break;
        }
    }
}

void Profession::newHero()
{
    assignDefaultStatistics();
    cout << "You've chosen " << this->profession << " as your profession." << endl;
    cout << "Enter name for your character: ";
    cin >> name;
    this->saveToFile();
}

void Profession::displayStatistics()
{
    cout << "Hero & Statistics:" << endl << endl;
    cout << "\tName: " << name << endl;
    cout << "\tVitality: " << vitality << endl;
    cout << "\tStrength: " << strength << endl;
    cout << "\tDexterity: " << dexterity << endl;
    cout << "\tEndurance: " << endurance << endl;
    cout << "\tInteligence: " << wisdom << endl;
    cout << "\tCharisma: " << charisma << endl;
    cout << "\tProfession: " << profession << endl;
    cout << "\tLevel: " << level << endl;
    cout << "\tExperience: " << experience << endl;
    cout << endl;
}

void Profession::saveToFile()
{
    fstream heroesFile; //always keep the fstream with the file.open() and file.close() together in the same function !!!
    string filename = name;
    filename.append(".txt");
    heroesFile.open(filename, ios::out);

    heroesFile << "Hero & Statistics: " << endl << endl
        << "Name: " << name << endl
        << "Vitality: " << vitality << endl
        << "Strength: " << strength << endl
        << "Dexterity: " << dexterity << endl
        << "Endurance: " << endurance << endl
        << "Inteligence: " << wisdom << endl
        << "Charisma: " << charisma << endl
        << "Profession: " << profession << endl
        << "Level: " << level << endl
        << "Experience: " << experience << endl;

    heroesFile.close();
}

void Profession::loadFromFile(int heroNumber, string& heroFilename)
{
    {
        fstream heroesFile; // always in the same function that the file.open() and file.close() is !!!!
        heroesFile.open(heroFilename, ios::in);

        if (heroesFile.good() == false)
        {
            cout << "Unable to load the file. Try again later." << endl;
            heroesFile.close();
            system("pause");
        }
        else
        {
            if (heroesFile.is_open())
            {
                string line;
                int currentLine = 1;
                int hero = (heroNumber - 1) * 13 + 3;

                while (getline(heroesFile, line))
                {
                    if (currentLine > 13 * hero - 1)
                    {
                        break;
                    }
                    else if (currentLine >= hero)
                    {
                        if (currentLine == hero)
                        {
                            string name = line.substr(6, line.size());
                            //cout << name << endl;
                            this->name = name;
                        }
                        else if (currentLine == hero + 1)
                        {
                            int vitality = stoi(line.substr(10, line.size()));
                            //cout << vitality << endl;
                            this->vitality = vitality;
                        }
                        else if (currentLine == hero + 2)
                        {
                            int strength = stoi(line.substr(10, line.size()));
                            //cout << strength << endl;
                            this->strength = strength;
                        }
                        else if (currentLine == hero + 3)
                        {
                            int dexterity = stoi(line.substr(11, line.size()));
                            //cout << dexterity << endl;
                            this->dexterity = dexterity;
                        }
                        else if (currentLine == hero + 4)
                        {
                            int endurance = stoi(line.substr(11, line.size()));
                            //cout << endurance << endl;
                            this->endurance = endurance;
                        }
                        else if (currentLine == hero + 5)
                        {
                            int intelligence = stoi(line.substr(13, line.size()));
                            //cout << intelligence << endl;
                            this->wisdom = intelligence;
                        }
                        else if (currentLine == hero + 6)
                        {
                            int charisma = stoi(line.substr(10, line.size()));
                            //cout << charisma << endl;
                            this->charisma = charisma;
                        }
                        else if(currentLine == hero + 7)
                        {
                            string profession = line.substr(12, line.size());
                            //cout << profession << endl;
                            this->profession = profession;
                        }
                        else if (currentLine == hero + 8)
                        {
                            int level = stoi(line.substr(7, line.size()));
                            //cout << charisma << endl;
                            this->level = level;
                        }
                        else if (currentLine == hero + 9)
                        {
                            int experience = stoi(line.substr(12, line.size()));
                            //cout << charisma << endl;
                            this->experience = experience;
                        }
                    }
                    currentLine++;
                }

                heroesFile.close();
            }
        }
        this->health = level * vitality * endurance;
        this->attack = level * (strength + dexterity);
    }
}

string Profession::checkForProfession(string &filename)
{
    fstream heroesFile; // always in the same function that the file.open() and file.close() is !!!!
    heroesFile.open(filename, ios::in);
    string profession;

    if (heroesFile.good() == false)
    {
        cout << "Unable to load the file. Try again later." << endl;
        heroesFile.close();
    }
    else
    {
        if (heroesFile.is_open())
        {
            string line;
            for (int currentLine = 1; getline(heroesFile, line) && currentLine <= 10; currentLine++)
            {
                if (currentLine == 10)
                {
                    profession = line.substr(12, line.size());
                    break;
                }
            }
        }
    }
    return profession;
}

void Profession::increaseLevel()
{
    this->level++;
}

int Profession::get_toLevelUp()
{
    return this->toLevelUp;
}

void Profession::set_toLevelUp()
{
    this->toLevelUp = this->level * 5;
}

std::string Profession::getProfession()
{
    return this->profession;
}

void Profession::setProfession(std::string& x)
{
    this->profession = x;
}
