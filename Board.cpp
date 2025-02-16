#include "Board.h"
#include <iostream>

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

void Board::initializeBoard()
{
    srand(time(0));
    // Seed random number generator in your main function once
    initializeTiles(0);
    initializeTiles(1);
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <string>

using namespace std;
void Board::initializeTiles(int path)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        }
        else if (i == 0)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 -
                                                                       green_count))
        {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            // randomly assigns tile colors for cub training path
            int color_choice;

            ////Oasis chance - 11%
            // Counseling tile - 22%
            // Challenge tile - 33%
            // Graveyard tile - 11%
            // Hyenas tile - 22%
            if (path == 1)
            {

                color_choice = rand() % 9;
                switch (color_choice)
                {
                case 0:
                    temp.color = 'B'; // Blue
                    break;
                case 1:
                    temp.color = 'P'; // Pink
                    break;
                case 2:
                    temp.color = 'N'; // Brown
                    break;
                case 3:
                    temp.color = 'R'; // Red
                    break;
                case 4:
                    temp.color = 'U'; // Purple
                    break;
                case 5:
                    temp.color = 'U'; // purple
                    break;
                case 6:
                    temp.color = 'U'; // purple
                    break;
                case 7:
                    temp.color = 'N'; // brown
                    break;
                case 8:
                    temp.color = 'P'; // pink
                    break;
                }
            }
            // randomly assigns tile colors for pridelands path
            else
            {
                color_choice = rand() % 10;
                // Oasis chance - 10%
                // Counseling tile - 20%
                // Challenge tile - 40%
                // Graveyard tile - 10%
                // Hyenas tile - 20%
                switch (color_choice)
                {
                case 0:
                    temp.color = 'B'; // Blue
                    break;
                case 1:
                    temp.color = 'P'; // Pink
                    break;
                case 2:
                    temp.color = 'N'; // Brown
                    break;
                case 3:
                    temp.color = 'R'; // Red
                    break;
                case 4:
                    temp.color = 'U'; // Purple
                    break;
                case 5:
                    temp.color = 'B'; // brown
                    break;
                case 6:
                    temp.color = 'U'; // purple
                    break;
                case 7:
                    temp.color = 'P'; // pink
                    break;
                case 8:
                    temp.color = 'U'; // purple
                    break;
                case 9:
                    temp.color = 'U'; // purple
                    break;
                }
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[path][i] = temp;
    }
}
/*Board::Board()
{
    _player_count = 1;
    // Initialize player position
    _player_position[0] = 0;
    // Initialize tiles
    initializeTiles(0);
}
*/
Board::Board(int player_count, int playerOnePath, int playerTwoPath)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // set paths
    paths[0] = playerOnePath;
    paths[1] = playerTwoPath;
    // Initialize tiles
    initializeBoard();
}
bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}
void Board::displayTile(int player_index, int pos)
{
    string space = " ";

    int player = isPlayerOnTile(player_index, pos);
    int otherPlayer;
    int path;
    int otherPath;
    string color = "";
    if (player_index == 0)
    {
        otherPlayer = 1;
        path = paths[0];
        otherPath = paths[1];
    }
    else
    {
        otherPlayer = 0;
        path = paths[1];
        otherPath = paths[0];
    }

    // Template for displaying a tile: <line filler space> <color start> |<player
    // symbol or blank space > | <reset color><line filler space><endl>
    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
        color = RED;
        tileColor = 'R';
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
        color = GREEN;
        tileColor = 'G';
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
        color = BLUE;
        tileColor = 'B';
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
        color = PURPLE;
        tileColor = 'U';
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
        color = BROWN;
        tileColor = 'N';
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
        color = PINK;
        tileColor = 'P';
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
        color = ORANGE;
        tileColor = 'O';
    }
    else if (_tiles[player_index][pos].color == 'Y')
    {
        color = GREY;
        tileColor = 'Y';
    }
    if (player == true && !isPlayerOnTile(otherPlayer, pos) && path == player_index)
    {

        cout << color << "|" << (player_index + 1) << "|" << RESET;
       
    }
    else if (player == true && isPlayerOnTile(otherPlayer, pos) && path == otherPath && path == player_index)
    {

        cout << color << "|1&2|" << RESET;
       
    }
    else if (player == true && !isPlayerOnTile(otherPlayer, pos) && path == otherPath && path == player_index)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
        
    }
    else if (isPlayerOnTile(otherPlayer, pos) && otherPath == player_index)
    {

        cout << color << "|" << (otherPlayer + 1) << "|" << RESET;
        
    }
    else if (player == true && isPlayerOnTile(otherPlayer, pos) && path != otherPath && path == player_index)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
        
    }
    else if (player == true && isPlayerOnTile(otherPlayer, pos) && path != otherPath && otherPath == player_index)
    {
        cout << color << "|" << (otherPlayer + 1) << "|" << RESET;
     
    }
    else
    {

        cout << color << "| |" << RESET;
       
    }
    
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
   
    cout << endl;
}
void Board::displayBoard()
{
    cout << "------KEY------" << endl;
    cout << "Brown: Den of Hyenas" << endl;
    cout << "Green: Grasslands" << endl;
    cout << "Blue: Open Oasis" << endl;
    cout << "Red: Graveyard" << endl;
    cout << "Purple: Challenge" << endl;
    cout << "Pink: Counseling" << endl;
    cout << endl;

    cout << "Path One: Cub Training" << endl;
    displayTrack(0);
    
    cout << endl;
    cout << "Path Two: The Pridelands" << endl;
    displayTrack(1);
    
}

bool Board::movePlayer(int player_index, bool direction)
{
    // Increment player position
    if (direction == true)
    {
        if (_player_position[player_index] < _BOARD_SIZE - 1)
        {
            _player_position[player_index]++;
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        _player_position[player_index]--;
        if (_player_position[player_index] < 0)
        {
            _player_position[player_index]++;
        }
        return false;
    }
}
int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

char Board::getTileColor(int player_index, int path)
{
    return _tiles[path][getPlayerPosition(player_index)].color;
}

// returns true if both players have reach pride rock
// returns false otherwise
bool Board::bothPlayersReachedPrideRock()
{
    if (_player_position[0] == 51 && _player_position[0] == _player_position[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}
