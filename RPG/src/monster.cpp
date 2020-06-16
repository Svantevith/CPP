#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <memory>

#include "monster.h"

using namespace std;

Monster::Monster()
{
    assignDefaultStatistics();
}

void Monster::assignDefaultStatistics()
{
    //srand(time(NULL));
    vector<string> monsterNameArray = { "Poisonous Spider", "Black Bear", "Wild Boar", "Infected Dog", "Undead Miner", "Cursed Knight", "Priest of the fallen order", "Haunted Farmer", "Homeless Cutler" };
    name = monsterNameArray[rand() % 9];
    
    level = rand() % 5 + 1;

    vector<int*> attributes = { &vitality, &strength, &dexterity, &endurance, &wisdom, &charisma };
    for (auto attr = attributes.begin(); attr != attributes.end(); attr++)
    {
        if (attr == attributes.begin())
        {
            **attr = rand() % (101) + 50;
        }
        else
        {
            **attr = rand() % 10 + 1;
        }
    }
    experience = 10 * charisma * level;
    health = level * vitality * endurance;
    attack = level * (strength + dexterity);
}

int Monster::attackInBattle()
{
    cout << this->name << " attacks!" << endl;
    int damage = 0;
    int dice = rand() % 6 + 1;
    int bonus = 0;
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

    damage = this->attack * bonus;

    if (damage > 0)
    {
        cout << this->name << " gives " << damage << " damage!" << endl;
    }
    else
    {
        cout << this->name << " misses!" << endl;
    }
    return damage;
}

void Monster::displayStatistics()
{
    cout << "Monster & Statistics:" << endl << endl;
    cout << "\tName: " << name << endl;
    cout << "\tVitality: " << vitality << endl;
    cout << "\tStrength: " << strength << endl;
    cout << "\tDexterity: " << dexterity << endl;
    cout << "\tEndurance: " << endurance << endl;
    cout << "\tInteligence: " << wisdom << endl;
    cout << "\tCharisma: " << charisma << endl;
    cout << "\tLevel: " << level << endl;
    cout << "\tExperience: " << experience << endl;
    cout << endl;
}

vector<Monster> Monster::oldMonsters()
{
    vector<Monster> monsters;
    string filename = "ListOfMonsters.txt";

    for (int i = 0; i < 5; i++)
    {
        auto ptr = make_unique<Monster>();
        ptr->loadFromFile(i + 1, filename);
        monsters.push_back(*ptr);
    }
    return monsters;
}

vector<Monster> Monster::newMonsters()
{
    vector<Monster> monsters;

    fstream monstersFile; // always in the same function that the file.open() and file.close() is !!!!
    string filename = "ListOfMonsters.txt";
    monstersFile.open(filename, ios::out | ios::trunc);
    monstersFile.close();
    //srand(time(NULL)); //srand umieszczamy tu, poniewa� je�li pojawi si� w assignDefaultStatistics, to b�dzie wczytany 5x, a wi�c nie zadzia�a poprawnie
    for (int i = 0; i < 5; i++)
    {
        auto ptr = make_unique<Monster>();
        ptr->assignDefaultStatistics();
        ptr->saveToFile();
        monsters.push_back(*ptr);
    }
    return monsters;
}

void Monster::loadFromFile(int monsterNumber, string& monstersFilename)
{
    fstream monstersFile; // always in the same function that the file.open() and file.close() is !!!!
    monstersFile.open(monstersFilename, ios::in | ios::out);
    if (monstersFile.is_open())
    {
        string line;
        int currentLine = 1;
        int monster = (monsterNumber - 1) * 12 + 3;

        while (getline(monstersFile, line))
        {
            if (currentLine > 12 * monsterNumber - 1 )
            {
                break;
            }
            else if (currentLine >= monster)
            {
                if (currentLine == monster)
                {
                    string n = line.substr(6, line.size());
                    //cout << name << endl;
                    this->name = n;
                }
                else if (currentLine == monster + 1)
                {
                    int vit= stoi(line.substr(10, line.size()));
                    //cout << vitality << endl;
                    this->vitality = vit;
                }
                else if (currentLine == monster + 2)
                {
                    int str = stoi(line.substr(10, line.size()));
                    //cout << strength << endl;
                    this->strength = str;
                }
                else if (currentLine == monster + 3)
                {
                    int dex = stoi(line.substr(11, line.size()));
                    //cout << dexterity << endl;
                    this->dexterity = dex;
                }
                else if (currentLine == monster + 4)
                {
                    int end = stoi(line.substr(11, line.size()));
                    //cout << endurance << endl;
                    this->endurance = end;
                }
                else if (currentLine == monster + 5)
                {
                    int wis = stoi(line.substr(13, line.size()));
                    //cout << intelligence << endl;
                    this->wisdom = wis;
                }
                else if (currentLine == monster + 6)
                {
                    int cha = stoi(line.substr(10, line.size()));
                    //cout << charisma << endl;
                    this->charisma = cha;
                }
                else if (currentLine == monster + 7)
                {
                    int lvl = stoi(line.substr(7, line.size()));
                    //cout << charisma << endl;
                    this->level = lvl;
                }
                else if (currentLine == monster + 8)
                {
                    int experience = stoi(line.substr(12, line.size()));
                    //cout << charisma << endl;
                    this->experience = experience;
                }
            }
            currentLine++;
        }
        monstersFile.close();
    }
    health = level * vitality * endurance;
    attack = level * (strength + dexterity);
}

void Monster::saveToFile()
{
    fstream monstersFile; //always keep the fstream with the file.open() and file.close() together in the same function !!!

    string filename = "ListOfMonsters";
    filename.append(".txt");

    monstersFile.open(filename, ios::out | ios::app);
    monstersFile << "Monster & Statistics: " << endl << endl
        << "Name: " << name << endl
        << "Vitality: " << vitality << endl
        << "Strength: " << strength << endl
        << "Dexterity: " << dexterity << endl
        << "Endurance: " << endurance << endl
        << "Inteligence: " << wisdom << endl
        << "Charisma: " << charisma << endl
        << "Level: " << level << endl
        << "Experience: " << experience << endl
        << endl;
    monstersFile.close();
}

void Monster::saveAllMonsters(vector<Monster>& monsters)
{
    for (auto& monster : monsters)
    {
        monster.saveToFile();
    }
}