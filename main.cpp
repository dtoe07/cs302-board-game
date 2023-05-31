// Program Assignment 2 for CS302
// Created by Dinh Nguyen
// 5-14-2023
// a simple multi-players board game


#include "game.h"
#include "deck.h"

int main() {

	// creating 3 decks of Obstacle, Challenge and Wild cards
	Deck<Obstacle> oCard;
	Deck<Challenge> cCard;
	Deck<Wild> wCard;

	// set number of steps for the board path and number of players
	int boardSize  = 15;
	int numPlayers = 2;

	// create a new board
	Board board(boardSize, numPlayers);
        board.printBoard(); 			// Display the path
        board.displayPlayers();			// display all players

	int currentPlayerIndex = 0;		// set current player Index to keep track for the loop
    	bool gameEnd = false;			// bool variable to check when to end the game

	cout << "========================================" << endl;
	cout << "============= Game starts ! ============" << endl;
	cout << "========================================" << endl;
	while (!gameEnd) {
		// display current player info
		cout << endl << "Current player: " << board.displayPlayer(currentPlayerIndex) << endl;

		// Roll the dice
        	int diceValue = board.rollDice();
		cout << "Dice was rolled with a value = " << diceValue << endl;

		// Move the player by the dice value
        	gameEnd = board.movePlayer(currentPlayerIndex, diceValue);

		// checking the current step if there is any actitivy needed to be done
		// also check if the player has won the game or not after rolling the dice
		if(!gameEnd){
			string task = board.getTask(currentPlayerIndex);
			cout << "Current task: " << task << endl;
			
			if(task == "Obstacle") 	cout << "Drawed from Obstacle deck: " 	<< oCard.getRandomCard() << endl;
			if(task == "Challenge") cout << "Drawed from Challenge deck: " 	<< cCard.getRandomCard() << endl;
			if(task == "Wild") 	cout << "Drawed from Wild deck: " 	<< wCard.getRandomCard() << endl;

			if(task == "Move back 3") gameEnd = board.movePlayer(currentPlayerIndex, -3);
			if(task == "Move forward 3") gameEnd = board.movePlayer(currentPlayerIndex, 3);
		}
		
		cout << endl << "--------------------------------" << endl;

		//check if the current player has won the game
		if(gameEnd){
			cout << "Player " << board.displayPlayer(currentPlayerIndex) << " has won the game!!!" << endl;
		}
	// Move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % numPlayers;
	}//end while loop








// testing codes to reuse for later testing


	// Get the number of players
//	int numPlayers = board.getNumPlayers();

/*
	// Game loop
  	bool gameOver = false;
	while (!gameOver) {
	
		// play the game later
	}
*/
/*
	Obstacle obj1, obj2, obj3; 
	obj1 = "this is object 1";
	obj2 = "this is object 2";
	obj3 += obj2;

	//cout<< "enter description for obj3: ";
	//cin>>obj3;

	cout << "showing from operator obj1: " << obj1 << endl;
	cout << "showing from operator obj2: " << obj2 << endl;
	cout << "showing from operator obj3: " << obj3 << endl;
	if(obj1 != obj2) cout << "it is not the same" << endl;
	cout << " obj1 index 2: " <<obj1[2] << endl;

	cout<<"end cards classes test"<<endl;
	Deck<Obstacle> obstacleDeck;

	cout <<"a random card: " << obstacleDeck.getRandomCard() << endl;
	cout <<"a random card: " << obstacleDeck.getRandomCard() << endl;


	Deck<Wild> c;
	cout <<"a random card: " << c.getRandomCard() << endl;
	cout <<"a random card: " << c.getRandomCard() << endl;


	Board board(10, 2);
	board.printBoard(); // Display the path
	cout << "step 4: " << board[4] <<endl;
	board.displayPlayers();
*/


return 0;
} // end main
