#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    void displayTile(int player_index, int pos);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos);
    int paths[2];
    char tileColor;
    
    

public:
    Board();
    Board(int player_count, int playerOnePath, int playerTwoPath);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index, bool direction);
    int getPlayerPosition(int player_index) const;
    char getTileColor(int player_index, int path);
    bool bothPlayersReachedPrideRock();

};
#endif
