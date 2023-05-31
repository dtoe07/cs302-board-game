
// header file to manage a hierarchy of 3 different kinds of cards: Obstacle, Challenge, Wild with a base class Card


#ifndef CARDS_H
#define CARDS_H

//#include "game.h"
#include <iostream>
#include <vector>
#include <cstdlib>      // for rand() and srand()
#include <ctime>        // for time()
#include <algorithm>
#include <cstring>


using namespace std;
const int MAX_CHAR = 50;

class Card {
	private:
		char* toDo;					// store a task that all cards will have to perform
	protected:
    		const char* getToDo() const;
	public:
		Card();
		Card(const Card& other);  			// Copy constructor
		~Card();
		
		//Operators
		Card& operator=(const char* _toDo);		// assign new description to the card by passing in a string
		ostream& operator<<(ostream& os) const;		// show the card
		istream& operator>>(istream& is);		// assign new description to the card by cin
		bool operator==(const Card& other) const;	// return true if both cards are the same
		bool operator!=(const Card& other) const;	// return true if both cards are not the same
		const char* operator+(const Card& other) const;	// return const char* combination of both descriptions
		Card& operator+=(const Card& other);		// combine other card description to the current card
								//
		friend istream& operator>>(istream& is, Card& card);
};


class Obstacle : public Card {
	private:
		vector<const char*> obstacles = {
			"Take a shot",
        		"Sing a song",
        		"Run up the stairs and down",
        		"Drink a glass of water",
        		"Let the next person pull your ear"	
		};	// vector list of obstacles to initialize the card stack
	public:
		Obstacle();
		Obstacle(const Obstacle& other);
		~Obstacle(){};
	
		Obstacle& operator=(const char* _toDo);
		ostream& operator<<(ostream& os) const ;

    		istream& operator>>(istream& is) ;
		bool operator==(const Card& other) const ;
		bool operator!=(const Card& other) const ;
		const char* operator+(const Card& other) const ;
		Card& operator+=(const Card& other) ;
		const char* operator[](int index) const;

		friend ostream& operator<<(ostream& os, const Obstacle& obstacle);
};


class Challenge : public Card {
	private:
		vector<const char*> challenges = {
                        "Do 10 pushups",
                        "Do 5 jumps",
                        "Run outside and back in 20 seconds",
                        "Do a flip bottle challenge",
                        "Eat an ice cube"
                };	// List of challenges
	public:
		Challenge();
		Challenge(const Challenge& other);
		~Challenge(){};

		Challenge& operator=(const char* _toDo);
		ostream& operator<<(ostream& os) const ;
    		istream& operator>>(istream& is) ;
		bool operator==(const Card& other) const ;
		bool operator!=(const Card& other) const ;
		const char* operator+(const Card& other) const ;
		Card& operator+=(const Card& other) ;
		const char* operator[](int index) const;

		friend ostream& operator<<(ostream& os, const Challenge& challenge);
};


class Wild : public Card {
	private:
		vector<const char*> wilds = {
                        "Make one other player do a random challenge",
                        "Do 5 jumps and 5 pushups",
                        "Down a beer",
                        "Make any player finish a glass of water",
                        "Make any player do 10 pushups"
                };	// list of wild card descriptions
	public:
		Wild();
		Wild(const Wild& other);
		~Wild(){};

		Wild& operator=(const char* _toDo);
		ostream& operator<<(ostream& os) const ;
                istream& operator>>(istream& is) ;
		bool operator==(const Card& other) const ;
		bool operator!=(const Card& other) const ;
		const char* operator+(const Card& other) const ;
		Card& operator+=(const Card& other) ;
		const char* operator[](int index) const;

		friend ostream& operator<<(ostream& os, const Wild& wild);
};

#endif
