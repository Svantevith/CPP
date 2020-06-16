#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    string name;
    int score;
public:
    Player(string n, int s)
            : name(n), score(s)
    {

    }
    string getName()
    {
        return this->name;
    }
    int getScore()
    {
        return this->score;
    }
};

class Checker
{
public:
    static int comparator(Player a, Player b)
    {
        if (a.getScore() < b.getScore())
        {
            return -1;
        }
        else if (a.getScore() == b.getScore())
        {
            if (a.getName() < b.getName())
            {
                return 1;
            }
            else if (a.getName() > b.getName())
            {
                return -1;
            }
            else if (a.getName() == b.getName())
            {
                return 0;
            }
        }
        else if (a.getScore() > b.getScore())
        {
            return 1;
        }

        return 0;
    }
};

int main() {
    Player amy("Amy", 100);
    Player david("David", 100);
    Player aleksa("Aleksa", 150);
    Player aakansha("Aakansha", 75);
    Player heraldo("Heraldo", 50);

    cout << Checker::comparator(heraldo, david) << endl;
    return 0;
}