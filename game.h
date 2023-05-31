
// header file to manage players can the board with its path


#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib> 	// for rand() and srand()
#include <ctime> 	// for time()
#include <list>

using namespace std;

// Forward declaration of Node class
class Node;


class Player {
	private:
		string name;		// player's name using string to meet requirements
		int position;		// index position of the player
	public:
		Player(const string& _name);
		bool setPosition(int step, int size);
		int getPosition() const;
		
		// displaying player name and pos with <<
		friend ostream& operator<<(ostream& os, const Player& player);

		friend class Board;

};


class Node {
	private:
		string  obstacle;
		Node* next;
		Node* prev;
	public:
		Node(const string& _obstacle);

		friend ostream& operator<<(ostream& os, const Node& node);      // show a step in the board by <<
		friend class Board; // Declare Board as a friend class
};


class Board {
	private:
		Node* head;
		Node* tail;
		int size;			// size of the path
		int numPlayers;			// number of players
		list<Player> players;		// using list to manage the players
		void generatePath(int numObstacles, const string obstacles[], int start, int end);
	public:
		Board();					
		Board(int _size, int _numPlayers);

		Node& operator[](int index); 			// access a node by index number

		void addPlayer();				// add a player
		void displayPlayers();				// display all players
		string displayPlayer(int playerIndex);		// display a player by index
		string getTask(int playerIndex); 		// get the current task base on player's position
		bool movePlayer(int playerIndex, int step);	// move a player's position
		void printBoard();				// print the whole board
		void displayPath(Node* currentNode); 		// print board helper
		int rollDice();					// return a random dice value
};



#endif
