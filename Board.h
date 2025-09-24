#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

// Tile structure to represent each tile on the board
struct Tile {
    char color; // R, G, B, P, N, U, O, Y
};

class Board {
public:
    static const int _BOARD_SIZE = 52;   // Total number of tiles per path
    static const int _MAX_PLAYERS = 2;   // Maximum number of players

    // Constructors
    Board(int player_count = 1, int playerOnePath = 0, int playerTwoPath = 1);

    // Board initialization
    void initializeBoard();
    void initializeTiles(int path);

    // Display functions
    void displayTile(int player_index, int pos);
    void displayTrack(int player_index);
    void displayBoard();

    // Player movement and queries
    bool movePlayer(int player_index, bool direction);
    int getPlayerPosition(int player_index) const;
    char getTileColor(int player_index, int path);
    bool isPlayerOnTile(int player_index, int pos);
    bool bothPlayersReachedPrideRock();

private:
    Tile _tiles[_MAX_PLAYERS][_BOARD_SIZE]; // Board tiles for each path
    int _player_position[_MAX_PLAYERS];     // Current position of each player
    int _player_count;                       // Number of players
    int paths[_MAX_PLAYERS];                 // Path choices for each player
    char tileColor;                          // Current tile color for display
};

#endif // BOARD_H
