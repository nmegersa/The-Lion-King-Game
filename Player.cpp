#include "Player.h"


//default constructor
Player::Player(){
    name = "";
    pridePoints = 20000;
    stamina = 100;
    strength = 100;
    wisdom = 100;
    pathType = 0;
}

//paramterized consturctor which intializes name, stamina, wisdom, strength
//also sets pridepoints to certain number and stores what path player has chosen
Player::Player(string n, int stam, int wis, int str, int path, int num){
    name = n;
    age = num;

    //sets stats if player chooses cub training path
    if(path == 0){
        pridePoints = 15000;
        stamina = stam + 500;
        wisdom = wis + 1000;
        strength = str + 500;
    }
    //sets stats if player chooses pride lands path
    else{
        pridePoints = 25000;
        stamina = stam + 200;
        wisdom = wis + 200;
        strength = str + 200;
    }
}

// returns name of player
string Player::getName()
{
    return name;
}
// returns number of pride points of a player
int Player::getPridePoints()
{
    return pridePoints;
}

// returns amount of stamina of a player
int Player::getStamina()
{
    return stamina;
}
// returns amount of wisdom of a player
int Player::getWisdom()
{
    return wisdom;
}

// returns amount of strength of a player
int Player::getStrength()
{
    return strength;
}

// sets player's pride points to a speific number
void Player::setPridePoints(int points)
{
    pridePoints = points;
}

// sets player's stamina to a certain number
void Player::setStamina(int points)
{
    stamina = points;

    // ensures stamina doesn't go below 100
    if (stamina < 100)
    {
        stamina = 100;
    }
}

// sets player name
void Player::setName(string newName)
{
    name = newName;
}

// sets player's wisdom to specific number
void Player::setWisdom(int points)
{
    wisdom = points;

    // ensures wisdom doesn't go below 100
    if (wisdom < 100)
    {
        wisdom = 100;
    }
}

// sets player's strength to a specific number
void Player::setStrength(int points)
{
    strength = points;

    // ensures strength doesn't go below 100
    if (strength < 100)
    {
        strength = 100;
    }
}

// used to add pridePoints or uses negative numbers to subtract pridePoints
void Player::addPridePoints(int points)
{
    pridePoints += points;
}

// used to add or subtract player's stamina
void Player::addStamina(int points)
{
    stamina += points;

    // ensures stamina doesn't go below 100
    if (stamina < 100)
    {
        stamina = 100;
    }
}

// adds or subtracts player'swisdom
void Player::addWisdom(int points)
{
    wisdom += points;

    // ensures wisdom doesn't go below 100
    if (wisdom < 100)
    {
        wisdom = 100;
    }
}

// adds or subtracts player strength
void Player::addStrength(int points)
{
    strength += points;

    // ensures strength doesn't go below 100
    if (strength < 100)
    {
        strength = 100;
    }
}

//sets a player's advisor by using a players choice from 1-5
//and assigning an advisor with the corresponding number
void Player::setAdvisor(int choice){
    if(choice == 1){
        advisor = "Rafiki";
    }
    else if(choice == 2){
        advisor = "Nala";
    }
    else if (choice == 3){
        advisor = "Sarabi";
    }
    else if(choice == 4){
        advisor = "Zazu";
    }
    else{
        advisor = "Sarafina";
    }
}

//sets name of lion that player chose
void Player::setLionName(string name){
    lionName = name;
}

string Player::getLionName(){
    return lionName;
}

//returns age of lion
int Player::getAge(){
    return age;
}


//sets age of lion
void Player::setAge(int num){
    age = num;
}

void Player::setPath(int path){
    pathType = path;
}

void Player::editStats(int path){
    if(path == 0){
        pridePoints -= 15000;
        wisdom += 1000;
        strength += 500;
        stamina += 500;
        
    }
    else{
        pridePoints += 5000;
        wisdom += 200;
        strength += 200;
        stamina += 200;
    }
}


int Player::getPath(){
    return pathType;
}

//returns name of advisor for player
string Player::getAdvisor(){
    return advisor;
}

void Player::editPridePointsFinal(){
    int total = 0;
    total = wisdom / 100;
    pridePoints += total;
    total = strength / 100;
    pridePoints += total;
    total = stamina / 100;
    pridePoints += total;
}