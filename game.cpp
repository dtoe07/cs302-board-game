
// implementations for game.h file

#include "game.h"

// PLayer constructor
Player::Player(const string& _name) : name(_name), position(0) {}

// << for PLayer class
ostream& operator<<(ostream& os, const Player& player) {
    	os << "Name: " << player.name << ", Position: " << player.position;
    	return os;
}

bool Player::setPosition(int step, int size) {
    	position += step;

    	// Restrict the position within the valid range of the board
    	if (position < 0) {
        	position = 0;  // Restrict the position to the start of the board
		return false;
    	} else if(position >= size-1) return true;	// return true if player reach or pass the end of the board
	return false; 					// return false if player pos is still within the board
}

int Player::getPosition() const {
    return position;
}





// Node constructor
Node::Node(const string& _obstacle)
    	: obstacle(_obstacle), next(nullptr), prev(nullptr) {}






// Board constructor
Board::Board(int _size, int _numPlayers) : size(_size), numPlayers(_numPlayers) {
	const string obstacles[] = {
		"Do nothing",
		"Obstacle",
		"Move back 3",
		"Challenge",
		"Rest area",
		"Move forward 3",
		"Wild"
		// add more obstacles later dont forget to increase the first arguement to pass
		// to generatePath to match the number of obstacles in the list
	};
	srand(static_cast<unsigned int>(time(nullptr)));	//seed the random number generator
	generatePath(7, obstacles, 0, size-1);
	
	// adding players to fill number of players wanted to create
	for (int i = 0; i < numPlayers; ++i) {
        addPlayer();
    }

}

// generating the path with random obstacles
void Board::generatePath(int numObstacles, const string obstacles[], int start, int end) {
	head = new Node("Start");
  	Node* currentNode = head;

	for (int i = 1; i < size - 1; ++i) {
		// Generate a random obstacle index
    		int obstacleIndex = rand() % numObstacles;
		Node* newNode = new Node(obstacles[obstacleIndex]);
		
		// Connect the new node to the current node
		currentNode->next = newNode;
    		newNode->prev = currentNode;

		// Move to the next node
    		currentNode = newNode;
	} // end for loop
	
	// Create the tail node
  	tail = new Node("End");

	// Connect the tail node to the last node
  	currentNode->next = tail;
  	tail->prev = currentNode;
}

// Implementation of operator[] to access nodes in the DLL
Node& Board::operator[](int index) {
	if (index < 0 || index >= size)
        	throw out_of_range("Invalid index");

    	Node* currentNode = head;
    	for (int i = 0; i < index; ++i) {
        	if (currentNode) currentNode = currentNode->next;
        	else throw out_of_range("Invalid index");
    	}

    	return *currentNode;
}

// overloading <<
ostream& operator<<(ostream& os, const Node& node) {
    os << node.obstacle;
    return os;
}

// dislaying the board layout
void Board::displayPath(Node* currentNode) {
    	// Base case: If the current node is null or the tail node, return
    	if (currentNode == nullptr || currentNode == tail) {
        	return;
    	}
  
    	// Print the obstacle of the current node
    	cout << currentNode->obstacle << " -> ";
  
    	// Recursively call the function for the next node
    	displayPath(currentNode->next);
}

void Board::printBoard() {
    	cout << "Path: ";
    	displayPath(head);
    	cout << "End" << endl;
}

// adding new player to the list
void Board::addPlayer() {
    	string name;
    	cout << "Enter player name: ";
    	cin >> name;
    	Player player(name);
    	players.push_back(player);
}

// display a player by index
string Board::displayPlayer(int playerIndex) {
    	if (playerIndex < 0 || playerIndex >= players.size()) {
        	return "Invalid player index.";
    	}

    	int index = 0;
    	for (const Player& player : players) {
        	if (index == playerIndex) {
            		return player.name + " in position = " + to_string(player.position);
        	}
        	index++;
    	}
	return "PLayer not found";
}

// display all players
void Board::displayPlayers() {
    for (const Player& player : players) {
        cout << player << endl;
    }
}

// move player base on value passed in, can be negative int if moving backward
bool Board::movePlayer(int playerIndex, int step) {
    	if (playerIndex < 0 || playerIndex >= numPlayers) {
        	cout << "Invalid player index!" << endl;
        	return false;
    }
	auto it = players.begin();
    	advance(it, playerIndex);
    	Player& player = *it;
    	return player.setPosition(step, size);
}

// rolling the dice
int Board::rollDice(){
	return rand() % 6+1;
}

// getting task
string Board::getTask(int playerIndex) {
    if (playerIndex < 0 || playerIndex >= numPlayers) {
        return "Invalid player index.";
    }

    int index = 0;
        for (const Player& player : players) {
                if (index == playerIndex) {
			Node& node = operator[](player.position);
			return node.obstacle;
		}
		index++;
	}
	return "PLayer not found";
}


