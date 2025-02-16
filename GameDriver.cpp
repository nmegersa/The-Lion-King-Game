#include "Board.cpp"
#include "Player.cpp"
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <stdlib.h>

// randomly displays a random event when called
// returns amount of pride points gained or added
// depending on event and advisor

int randomEvent(Player player)
{
    ifstream file("random_events.txt");
    string event;
    string number;
    string trainingEvents[25];
    string prideLandsEvents[26];
    int statsChangeTraining[25][2];
    int statsChangePrideLands[26][2];

    if(!file){
        cout << "File couldn't be opened" << endl;
        return -1;
    }

    getline(file, event);
    getline(file, event);
    int trainingEventsCount = 0;
    int prideLandsEventsCount = 0;
    for (int i = 0; i < 20; i++)
    {
        getline(file, event, '|');
        getline(file, number, '|');
        if (number == "0")
        {
            trainingEvents[trainingEventsCount] = event;
            getline(file, number, '|');
            statsChangeTraining[trainingEventsCount][0] = stoi(number);
            getline(file, number);
            statsChangeTraining[trainingEventsCount][1] = stoi(number);

            trainingEventsCount++;
        }
        else
        {
            prideLandsEvents[prideLandsEventsCount] = event;
            getline(file, number, '|');
            statsChangePrideLands[prideLandsEventsCount][0] = stoi(number);
            getline(file, number);
            statsChangePrideLands[prideLandsEventsCount][1] = stoi(number);
            prideLandsEventsCount++;
        }
    }
    getline(file, event);
    for (int i = 0; i < 30; i++)
    {
        getline(file, event, '|');
        getline(file, number, '|');
        if (number == "0")
        {
            trainingEvents[trainingEventsCount] = event;
            getline(file, number, '|');
            statsChangeTraining[trainingEventsCount][0] = stoi(number);
            getline(file, number);
            statsChangeTraining[trainingEventsCount][1] = stoi(number);

            trainingEventsCount++;
        }
        else
        {
            prideLandsEvents[prideLandsEventsCount] = event;
            getline(file, number, '|');
            statsChangePrideLands[prideLandsEventsCount][0] = stoi(number);
            getline(file, number);
            statsChangePrideLands[prideLandsEventsCount][1] = stoi(number);
            prideLandsEventsCount++;
        }
    }
    int random;
    if (player.getPath() == 0)
    {
        random = rand () % trainingEventsCount;
        cout << trainingEvents[random] << endl;
        if (random < 10)
        {
            int advisorNum = statsChangeTraining[random][0];
            if (player.getAdvisor() == "Rafiki" && advisorNum == 1)
            {
                cout << "Using Rafiki's invisbility, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else if (player.getAdvisor() == "Nala" && advisorNum == 2)
            {
                cout << "Using Nala's night vision, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else if (player.getAdvisor() == "Sarabi" && advisorNum == 3)
            {
                cout << "Using Sarabi's energy manipulation, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }

            else if (player.getAdvisor() == "Zazu" && advisorNum == 4)
            {
                cout << "Using Zazu's weather control, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else if (player.getAdvisor() == "Sarafina" && advisorNum == 5)
            {
                cout << "Using Sarafina's super speed, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else
            {
                cout << "Sadly, " << player.getLionName() << " has lost " << statsChangeTraining[random][1] << " pride points." << endl;
                return statsChangeTraining[random][1];
            }
        }
        else
        {
            return statsChangeTraining[random][1];
        }
    }
    else
    {
        random = rand() % prideLandsEventsCount;
        cout << prideLandsEvents[random] << endl;
        if (random < 11)
        {
            int advisorNum = statsChangePrideLands[random][0];
            if (player.getAdvisor() == "Rafiki" && advisorNum == 1)
            {
                cout << "Using Rafiki's invisbility, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else if (player.getAdvisor() == "Nala" && advisorNum == 2)
            {
                cout << "Using Nala's night vision, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else if (player.getAdvisor() == "Sarabi" && advisorNum == 3)
            {
                cout << "Using Sarabi's energy manipulation, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }

            else if (player.getAdvisor() == "Zazu" && advisorNum == 4)
            {
                cout << "Using Zazu's weather control, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else if (player.getAdvisor() == "Sarafina" && advisorNum == 5)
            {
                cout << "Using Sarafina's super speed, you have avoided this event and " << player.getLionName() << " loses 0 pride points!" << endl;
                return 0;
            }
            else
            {
                cout << "Sadly, " << player.getLionName() << " has lost " << statsChangePrideLands[random][1] << " pride points." << endl;
                return statsChangePrideLands[random][1];
            }
        }
        else
        {
            return statsChangeTraining[random][1];
        }
    }
}

// reads in file of riddles and chooses one
// will print out riddle and allow user to answer it
// returns true or false depending on answer
// adds/substracts from leadership traits depednign on answer
bool riddle()
{
    srand(time(0));
    ifstream file("riddles.txt");
    string line;
    string riddles[27];
    string riddlesAnswers[27];
    int pos = 0;
    string answer;


    if(!file){
        cout << "File not opened" << endl;
        return false;
    }
    
    
    getline(file, line);
    while (getline(file, line, '|'))
    {
        riddles[pos] = line;
        getline(file, line);
        riddlesAnswers[pos] = line;
        pos++;
    }
    cout << "You landed on a riddle tile!" << endl;
    cout << "Answer the riddle displayed correctly and be rewarded!" << endl;
    cout << endl;
    pos = rand() % 27;
    cout << riddles[pos] << endl;
    cin >> answer;
    if (answer != riddlesAnswers[pos])
    {
        cout << "Incorrect answer!" << endl;
        return false;
    }
    else
    {
        cout << "Correct answer!" << endl;
        return true;
    }
}

// generates random number between 1-6 for a spin
// determines how many tiles a player will move
int spin()
{
    

    return (rand() % 6) + 1;
}

// dsiplays a list of advisors to choose from
// and returns the number of which advisor the player wants
int displayAdvisors(Player player)
{
    char input;
    bool validInput = false;
    while (!validInput)
    {
        system("clear");
        cout << "1. Rafiki - Invisibility (the ability to become unseen)" << endl;
        cout << "2. Nala - Night Vision (the ability to see clearly in darkness)" << endl;
        cout << "3. Sarabi - Energy Manipulation (the ability to shape and control properties of energy)" << endl;
        cout << "4. Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
        cout << "5. Sarafina - Super Speed (the ability run 4x fast than the maximum speed of lions)" << endl;
        cout << endl;
        cout << player.getName() << ", choose your advisor by entering a corresponding number: " << endl;
        cout << endl;
        cin >> input;
        if (input != '1' && input != '2' && input != '3' && input != '4' && input != '5')
        {
            cout << "Error, invalid input! Try again" << endl;
            cout << endl;
        }
        else
        {
            validInput = true;
        }
    }
    return input - '0';
}

// displays menu whre user can look at stats, edit things, etc.
int displayMainMenu(Player player)
{
    int input;
    bool validInput = false;
    while (!validInput)
    {
        cout << "       -----Menu-----" << endl;
        cout << "1. View Character Leadership Traits" << endl;
        cout << "2. View Character Age/Name" << endl;
        cout << "3. View Position On Board" << endl;
        cout << "4. Review Advisor" << endl;
        cout << "5. Spin" << endl;
        cout << endl;
        cout << player.getName() << " please enter a corresponding number to what part of the menu you would like to access: " << endl;
        cout << endl;
        cin >> input;
        if (input != 1 && input != 2 && input != 3 && input != 4 && input != 5)
        {
            cout << "Error, invalid input! Try again" << endl;

            cout << endl;
        }
        else
        {
            validInput = true;
        }
    }
    return input;
}

// depedning on what section of menu was selected
// displays that part of the menu
/*void userMenuChoice(Player player, Board board)
{
    bool validInput = false;
    char input;
    while (!validInput)
    {
        int choice = displayMainMenu(player);
        switch (choice)
        {
        case 1:
            cout << "       ---" << player.getLionName() << "'s Leadership Traits---" << endl;
            cout << "Strength: " << player.getStrength() << endl;
            cout << "Stamina: " << player.getStamina() << endl;
            cout << "Wisdom: " << player.getWisdom() << endl;
            cout << "Pride Points: " << player.getPridePoints() << endl;
            cout << endl;
            break;
        case 2:
            cout << "Character's name: " << player.getLionName() << endl;
            cout << player.getLionName() << "'s age: " << player.getAge() << endl;
            cout << endl;
            break;
        case 3:
            board.displayBoard();
            cout << endl;
            break;
        case 4:
            cout << "Advisor name: " << player.getAdvisor() << endl;
            if (player.getAdvisor() == "Rafiki")
            {
                cout << "Special Ability: Invisibility (the ability to become un-seen)" << endl;
            }
            else if (player.getAdvisor() == "Nala")
            {
                cout << "Special Ability: Night Vision (the ability to see clearly in darkness)" << endl;
            }
            else if (player.getAdvisor() == "Sarabi")
            {
                cout << "Special Ability: Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
            }
            else if (player.getAdvisor() == "Zazu")
            {
                cout << "Special Ability: Weather Control (the ability to influence and manipulate weather patterns)" << endl;
            }
            else
            {
                cout << "Special Ability: Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
            }
            bool valid = false;
            while(!valid){
                cout << "Would you like to change your advisor? (Y or N)" << endl;
                cin >> input;
                if(input != 'Y' && input != 'N'){
                    cout << "Error, try again" << endl;
                }
                else if(input == 'Y'){
                    displayAdvisors(player)
                }
            }
            break;
        case 5:
            validInput = true;
            break;
        }
    }
}
*/

// displays a menu of characters for users to selct from
void displayCharacters(string fileName)
{
    ifstream file(fileName);

    if(!file){
        cout << "File not opened" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
}

// creates an object of player from player's choice of a lion character
// sets all starting stats
Player sortCharacters(string userChoice, string fileName)
{
    ifstream file(fileName);
    Player player;
    string line;

    if(!file){
        cout << "File not opened" << endl;
        return player;
    }
    
    
    getline(file, line);
    while (getline(file, line, '|'))
    {
        if (line == userChoice)
        {

            player.setLionName(userChoice);
            getline(file, line, '|');
            player.setAge(stoi(line));
            getline(file, line, '|');
            player.setStrength(stoi(line));
            getline(file, line, '|');
            player.setStamina(stoi(line));
            getline(file, line, '|');
            player.setWisdom(stoi(line));
            getline(file, line);
            player.setPridePoints(stoi(line));
            break;
        }
        else
        {
            getline(file, line);
        }
    }

    return player;
}

// REMEBER TO USE WHILE LOOPS FOR ERROR HANDLING
// WHEN ASKING FOR USER INPUT/CHOICE
int main()
{
    srand(time(0));
    // intialize variables to store user input/choice
    string playerOneName, playerTwoName;
    fstream charactersFile("characters.txt");
    string input;
    // int choice;
    bool play = true;
    bool validInput;

    // while loop that runs while game is on going
    while (play)
    {
        // ask players for their names
        cout << "--------Welcome to the Lion King Game!--------" << endl;
        cout << "Player one, what is your name?" << endl;
        cin >> playerOneName;

        cout << "Player Two, what is your name?" << endl;
        cin >> playerTwoName;

        // starts off as false until user correctly chooses a character
        validInput = false;

        // loop that handles if player doesn't correctly
        // select a lion character
        system("clear");
        while (!validInput)
        {

            displayCharacters("characters.txt");
            cout << playerOneName << ", what lion would you like to select as your character? (enter the name of any listed above)" << endl;
            cin >> input;
            if (input != "Kyler" && input != "John" && input != "Zuri" && input != "Bo" && input != "Rama")
            {
                cout << "Error! Invalid Input! Try again" << endl;
            }
            else
            {
                validInput = true;
            }
        }

        // intialize player object for first player
        Player playerOne;
        playerOne = sortCharacters(input, "characters.txt");
        playerOne.setName(playerOneName);
        // cout << "Debug: Lion Name is " << playerOne.getLionName() << endl;

        // run while loop again, prompting second player
        // for the character they would like to select

        // set to false to run loop again
        validInput = false;
        system("clear");
        while (!validInput)
        {

            displayCharacters("characters.txt");
            cout << playerTwoName << ", what lion would you like to select as your character? (enter the name of any listed above)" << endl;
            cin >> input;
            if (input != "Kyler" && input != "John" && input != "Zuri" && input != "Bo" && input != "Rama")
            {
                cout << "Error! Invalid Input! Try again" << endl;
            }
            else if (input == playerOne.getLionName())
            {
                cout << "Can't pick same character as player one! Try again" << endl;
            }
            else
            {
                validInput = true;
            }
        }

        // create second player object for second player
        Player playerTwo;
        playerTwo = sortCharacters(input, "characters.txt");
        playerTwo.setName(playerTwoName);

        // prompt user to select 1 for cub training path or 2 for pridelands
        validInput = false;
        system("clear");
        int spaces = 0;
        while (!validInput)
        {

            cout << playerOneName << ", would you like for "
                 << playerOne.getLionName() << " to start their journey in (1) Cub Training or (2) The Pridelands?" << endl;
            cin >> input;
            if (input != "1" && input != "2")
            {
                cout << "Error, invalid input! Try again" << endl;
            }
            else
            {
                if (input == "1")
                {
                    playerOne.setPath(0);
                    playerOne.setAdvisor(displayAdvisors(playerOne));
                }
                else
                {
                    playerOne.setPath(1);
                }
                validInput = true;
            }
        }

        // run loop again asking path for player two
        validInput = false;
        system("clear");
        while (!validInput)
        {

            cout << playerTwoName << ", would you like for " << playerTwo.getLionName()
                 << " to start his journey in (1)Cub Training or (2)The Pridelands?" << endl;
            cin >> input;
            if (input != "1" && input != "2")
            {
                cout << "Error, invalid input! Try again" << endl;
            }
            else
            {
                if (input == "1")
                {
                    playerTwo.setPath(0);
                    playerTwo.setAdvisor(displayAdvisors(playerTwo));
                }
                else
                {
                    playerTwo.setPath(1);
                }
                validInput = true;
            }
        }

        // correctly set stats for both lion characters based off path they're taking
        playerOne.editStats(playerOne.getPath());
        playerTwo.editStats(playerTwo.getPath());

        // create and intialize board
        // set players on boards that correctly correspond
        // with the path they chose
        Board board(2, playerOne.getPath(), playerTwo.getPath());

        // first round starts with player one turn and displaying the board
        // before each turn display menu where user can check stats, etc.
        bool prideRockReached = false;
        bool valid = false;
        string nameInput;
        while (!prideRockReached)
        {
            // displays menu, asks user what part they will select
            // runs until user decides to spin
            int randomEventPoints = 0;
            bool validInput = false;
            char input;
            while (!validInput)
            {
                int choice = displayMainMenu(playerOne);
                switch (choice)
                {
                case 1:
                    cout << "       ---" << playerOne.getLionName() << "'s Leadership Traits---" << endl;
                    cout << "Strength: " << playerOne.getStrength() << endl;
                    cout << "Stamina: " << playerOne.getStamina() << endl;
                    cout << "Wisdom: " << playerOne.getWisdom() << endl;
                    cout << "Pride Points: " << playerOne.getPridePoints() << endl;
                    cout << endl;
                    break;
                case 2:
                    cout << "Character's name: " << playerOne.getLionName() << endl;
                    cout << playerOne.getLionName() << "'s age: " << playerOne.getAge() << endl;
                    cout << endl;
                    valid = false;
                    while (!valid)
                    {
                        cout << playerOne.getName() << ", would you like to change your character's name? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            cout << "What would you like for your character's new name to be?" << endl;
                            cin >> nameInput;
                            playerOne.setLionName(nameInput);
                            cout << endl;
                            cout << playerOne.getName() << ", your lion character's new name is " << playerOne.getLionName() << endl;
                            valid = true;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                    break;
                case 3:
                    board.displayBoard();
                    cout << endl;
                    break;
                case 4:
                    cout << "Advisor name: " << playerOne.getAdvisor() << endl;
                    if (playerOne.getAdvisor() == "Rafiki")
                    {
                        cout << "Special Ability: Invisibility (the ability to become un-seen)" << endl;
                    }
                    else if (playerOne.getAdvisor() == "Nala")
                    {
                        cout << "Special Ability: Night Vision (the ability to see clearly in darkness)" << endl;
                    }
                    else if (playerOne.getAdvisor() == "Sarabi")
                    {
                        cout << "Special Ability: Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                    }
                    else if (playerOne.getAdvisor() == "Zazu")
                    {
                        cout << "Special Ability: Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                    }
                    else
                    {
                        cout << "Special Ability: Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                    }
                    valid = false;
                    while (!valid)
                    {
                        cout << "Would you like to change your advisor? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            playerOne.setAdvisor(displayAdvisors(playerOne));
                            valid = true;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                    break;
                case 5:
                    validInput = true;
                    break;
                }
            }
            // use srand() in the range of 1-6 included for the spinner
            // use movePlayer() in a loop
            // iterting the number of times that the spinner produced
            spaces = 0;
            for (int i = 0; i < spin(); i++)
            {
                board.movePlayer(0, true);

                spaces++;
            }

            // if player lands on a special tile, random, challenge, etc
            // ask for user input if it's riddle
            // otherwise print out the result of the special tile
            switch (board.getTileColor(0, playerOne.getPath()))
            {
            case 'R':
                cout << playerTwo.getLionName() << " has fell into a graveyard! You have lost 100 stamina, wisdom, and strength points!" << endl;
                cout << "Move back 10 spaces!" << endl;
                cout << endl;
                cout << endl;
                playerOne.addStamina(-100);
                playerOne.addStrength(-100);
                playerOne.addWisdom(-100);
                for (int i = 0; i < 10; i++)
                {
                    board.movePlayer(0, false);
                }
                break;
            case 'B':
                cout << "Welcome to the Oasis " << playerOne.getLionName() << "!" << endl;
                cout << "Move 6 more spaces and gain 200 points for all leadership attributes!!!" << endl;
                cout << endl;
                cout << endl;
                playerOne.addStamina(200);
                playerOne.addStrength(200);
                playerOne.addWisdom(200);
                for (int i = 0; i < 6; i++)
                {
                    board.movePlayer(0, true);
                }
                break;
            case 'P':
                cout << playerOne.getLionName() << ", has reached the Land of Enrichment!" << endl;
                cout << "You have gained 300 stamina, strength, and wisdom points!" << endl;
                if (playerOne.getAdvisor() == "")
                {
                    valid = false;
                    while (!valid)
                    {
                        cout << "Would you like to have an advisor? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            playerOne.setAdvisor(displayAdvisors(playerOne));
                            valid = true;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                }
                else
                {
                    valid = false;
                    while (!valid)
                    {
                        cout << "Would you like to switch your advisor or keep it? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            playerOne.setAdvisor(displayAdvisors(playerOne));
                            valid = true;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                }
                break;
            case 'N':
                cout << playerOne.getLionName() << " has ran into a pack of hyenas!" << endl;
                cout << playerOne.getLionName() << " loses 300 stamina points and moves back to position before spin" << endl;
                playerOne.addStamina(-300);
                for (int i = 0; i < spaces; i++)
                {
                    board.movePlayer(0, false);
                }
                break;
            case 'U':
                cout << playerOne.getLionName() << " has approached a challenge!" << endl;
                if (riddle())
                {
                    playerOne.addWisdom(500);
                }
                break;
            case 'G':
                randomEventPoints = randomEvent(playerOne);
                cout << endl;
                cout << playerOne.getLionName() << " has gained/lost " << randomEventPoints << " pride points from this event." << endl;
                playerOne.addPridePoints(randomEventPoints);
                break;
            case 'O':
                cout << playerOne.getLionName() << " has reached pride rock! Congratualtions!" << endl;
                cout << "Continue looking at stats and press 5 to skip and end your turn!" << endl;
                break;
            }

            // check if player has advisor that negates any negatives
            // adjust stats as needed

            // redisplay menu before each turn and respin when user ready
            // repeat this process until both players reach pride rock
            validInput = false;
            while (!validInput)
            {
                int choice = displayMainMenu(playerTwo);
                switch (choice)
                {
                case 1:
                    cout << "       ---" << playerTwo.getLionName() << "'s Leadership Traits---" << endl;
                    cout << "Strength: " << playerTwo.getStrength() << endl;
                    cout << "Stamina: " << playerTwo.getStamina() << endl;
                    cout << "Wisdom: " << playerTwo.getWisdom() << endl;
                    cout << "Pride Points: " << playerTwo.getPridePoints() << endl;
                    cout << endl;
                    break;
                case 2:
                    cout << "Character's name: " << playerTwo.getLionName() << endl;
                    cout << playerTwo.getLionName() << "'s age: " << playerTwo.getAge() << endl;
                    cout << endl;
                    valid = false;
                    while (!valid)
                    {
                        cout << playerTwo.getName() << ", would you like to change your character's name? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            cout << "What would you like for your character's new name to be?" << endl;
                            cin >> nameInput;
                            playerTwo.setLionName(nameInput);
                            cout << endl;
                            cout << playerTwo.getName() << ", your lion character's new name is " << playerTwo.getLionName() << endl;
                            valid = true;
                        }
                        else
                        {
                            valid = true;
                        }
                    }

                    break;
                case 3:
                    board.displayBoard();
                    cout << endl;
                    break;
                case 4:
                    cout << "Advisor name: " << playerTwo.getAdvisor() << endl;
                    if (playerTwo.getAdvisor() == "Rafiki")
                    {
                        cout << "Special Ability: Invisibility (the ability to become un-seen)" << endl;
                    }
                    else if (playerTwo.getAdvisor() == "Nala")
                    {
                        cout << "Special Ability: Night Vision (the ability to see clearly in darkness)" << endl;
                    }
                    else if (playerTwo.getAdvisor() == "Sarabi")
                    {
                        cout << "Special Ability: Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                    }
                    else if (playerTwo.getAdvisor() == "Zazu")
                    {
                        cout << "Special Ability: Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                    }
                    else
                    {
                        cout << "Special Ability: Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                    }
                    valid = false;
                    while (!valid)
                    {
                        cout << "Would you like to display the other advisors? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            playerTwo.setAdvisor(displayAdvisors(playerTwo));
                            valid = true;
                        }
                        else{
                            valid = true;
                        }
                    }
                    break;
                case 5:
                    validInput = true;
                    break;
                }
            }

            spaces = 0;
            for (int i = 0; i < spin(); i++)
            {
                board.movePlayer(1, true);
                spaces++;
            }
            if(board.getPlayerPosition(0) < 51){
                board.movePlayer(0, false);
            }
            

            switch (board.getTileColor(1, playerTwo.getPath()))
            {
            case 'R':
                cout << playerTwo.getLionName() << " has fell into a graveyard! You have lost 100 stamina, wisdom, and strength points!" << endl;
                cout << "Move back 10 spaces!" << endl;
                cout << endl;
                cout << endl;
                playerTwo.addStamina(-100);
                playerTwo.addStrength(-100);
                playerTwo.addWisdom(-100);
                for (int i = 0; i < 10; i++)
                {
                    board.movePlayer(1, false);
                }
                break;
            case 'B':
                cout << "Welcome to the Oasis " << playerTwo.getLionName() << "!" << endl;
                cout << "Move 6 more spaces and gain 200 points for all leadership attributes!!!" << endl;
                cout << endl;
                cout << endl;
                playerTwo.addStamina(200);
                playerTwo.addStrength(200);
                playerTwo.addWisdom(200);
                for (int i = 0; i < 6; i++)
                {
                    board.movePlayer(1, true);
                }
                break;
            case 'P':
                cout << playerTwo.getLionName() << ", has reached the Land of Enrichment!" << endl;
                cout << "You have gained 300 stamina, strength, and wisdom points!" << endl;
                if (playerTwo.getAdvisor() == "")
                {
                    valid = false;
                    while (!valid)
                    {
                        cout << "Would you like to have an advisor? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            playerTwo.setAdvisor(displayAdvisors(playerTwo));
                            valid = true;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                }
                else
                {
                    valid = false;
                    while (!valid)
                    {
                        cout << "Would you like to switch your advisor or keep it? (Y or N)" << endl;
                        cin >> input;
                        if (input != 'Y' && input != 'N')
                        {
                            cout << "Error, try again" << endl;
                        }
                        else if (input == 'Y')
                        {
                            playerTwo.setAdvisor(displayAdvisors(playerTwo));
                            valid = true;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                }
                break;
            case 'N':
                cout << playerTwo.getLionName() << " has ran into a pack of hyenas!" << endl;
                cout << playerTwo.getLionName() << " loses 300 stamina points and moves back to position before spin" << endl;
                playerTwo.addStamina(-300);
                for (int i = 0; i < spaces; i++)
                {
                    board.movePlayer(1, false);
                }
                break;
            case 'U':
                cout << playerTwo.getLionName() << " has approached a challenge!" << endl;
                if (riddle())
                {
                    playerTwo.addWisdom(500);
                }
                break;
            case 'G':
                randomEventPoints = randomEvent(playerTwo);
                cout << endl;
                cout << playerTwo.getLionName() << " has gained/lost " << randomEventPoints << " pride points from this event." << endl;
                playerTwo.addPridePoints(randomEventPoints);
                break;
            case 'O':
                cout << playerTwo.getLionName() << " has reached pride rock! Congratualtions!" << endl;
                cout << "Continue looking at stats and press 5 to skip and end your turn!" << endl;
                cout << endl;
                break;
            }

            if (board.movePlayer(0, true) && board.movePlayer(1, true))
            {

                board.displayBoard();
                cout << "All players have reached Pride Rock!" << endl;
                cout << endl;
                cout << "Enter in any character and enter to continue: " << endl;
                cin >> input;
                cout << endl;
                prideRockReached = true;
            }
        }

        //add pride points for each player depending on how much
        //wisdom strenght and stamina they have
        playerOne.editPridePointsFinal();
        playerTwo.editPridePointsFinal();

        // whoever has most amount of pridepoints wins
        int winner;
        if (playerOne.getPridePoints() > playerTwo.getPridePoints())
        {
            winner = 0;
        }
        else if (playerTwo.getPridePoints() > playerOne.getPridePoints())
        {
            winner = 1;
        }
        else
        {
            winner = 3;
        }
        // print out winner and number of pride points
        system("clear");
        if (winner == 0)
        {

            cout << "The winners of the game with " << playerOne.getPridePoints() << " pride points is " << playerOne.getName() << " and " << playerOne.getLionName() << ". Congrats!" << endl;
        }
        else if (winner == 1)
        {
            cout << "The winners of the game with " << playerTwo.getPridePoints() << " pride points is " << playerTwo.getName() << " and " << playerTwo.getLionName() << ". Congrats!" << endl;
        }
        else
        {
            cout << "The winners of this game is everybody with both lions having the same number of pride points, " << playerOne.getPridePoints() << ". Congrats!" << endl;
        }

        // print out stats of both lions
        cout << endl;
        cout << endl;
        cout << playerOne.getLionName() << " stats: " << endl;
        cout << "Age: " << playerOne.getAge() << endl;
        cout << "Strength: " << playerOne.getStrength() << endl;
        cout << "Stamina: " << playerOne.getStamina() << endl;
        cout << "Wisdom: " << playerOne.getWisdom() << endl;
        cout << "Pride Points: " << playerOne.getPridePoints() << endl;


        cout << endl;
        cout << playerTwo.getLionName() << " stats: " << endl;
        cout << "Age: " << playerTwo.getAge() << endl;
        cout << "Strength: " << playerTwo.getStrength() << endl;
        cout << "Stamina: " << playerTwo.getStamina() << endl;
        cout << "Wisdom: " << playerTwo.getWisdom() << endl;
        cout << "Pride Points: " << playerTwo.getPridePoints() << endl;
        // print out all these game details to another file
        ofstream statsFile("game_stats.txt");
        if(!statsFile){
            cout << "File not opened";
        }
        statsFile << playerOne.getLionName() << " stats: " << endl;
        statsFile << "Age: " << playerOne.getAge() << endl;
        statsFile << "Strength: " << playerOne.getStrength() << endl;
        statsFile << "Stamina: " << playerOne.getStamina() << endl;
        statsFile << "Wisdom: " << playerOne.getWisdom() << endl;
        statsFile << "Pride Points: " << playerOne.getPridePoints() << endl;


        statsFile << endl;
        statsFile << endl;
        statsFile << playerTwo.getLionName() << " stats: " << endl;
        statsFile << "Age: " << playerTwo.getAge() << endl;
        statsFile << "Strength: " << playerTwo.getStrength() << endl;
        statsFile << "Stamina: " << playerTwo.getStamina() << endl;
        statsFile << "Wisdom: " << playerTwo.getWisdom() << endl;
        statsFile << "Pride Points: " << playerTwo.getPridePoints() << endl;

        statsFile.close();

        // give option to play again or exit the game
        cout << endl;
        cout << endl;
        valid = false;
        while (!valid)
        {
            cout << "Would you guys like to play the game again? (Y or N)" << endl;
            cin >> input;
            if (input != "Y" && input != "N")
            {
                cout << "Error, try again" << endl;
            }
            else if (input == "Y")
            {
                valid = true;
                system("clear");
            }
            else
            {
                cout << "Thanks for playing the Lion King Game! Hope to see you guys again soon!" << endl;
                valid = true;
                play = false;
            }
        }
    }
    return 0;
}
