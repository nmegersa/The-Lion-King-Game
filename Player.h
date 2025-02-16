#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    int pathType;
    int pridePoints;
    int stamina;
    int wisdom;
    int strength;
    string advisor;
    string lionName;
    int age;

public:
    Player();
    Player(string n, int stam, int wis, int str, int pathType, int num);

    string getName();
    int getPridePoints();
    int getStamina();
    int getWisdom();
    int getStrength();
    void setPridePoints(int points);
    void setStamina(int points);
    void setName(string newName);
    void setWisdom(int points);
    void setStrength(int points);
    void addPridePoints(int points);
    void addStamina(int points);
    void addWisdom(int points);
    void addStrength(int points);
    void setAdvisor(int choice);
    void setLionName(string name);
    int getAge();
    void setAge(int num);
    string getLionName();
    void setPath(int path);
    void editStats(int path);
    int getPath();
    string getAdvisor();
    void editPridePointsFinal();

};