
// header file to manage a template class that can take any type of card class and create a stack of LLL cards

#ifndef DECK_H
#define DECK_H

#include <chrono>
#include "cards.h"

template<typename T>
class CardNode {
        private:
                T card;
                CardNode<T>* next;
        public:
                CardNode(T card): card(card), next(nullptr) {}
                ~CardNode(){}

                CardNode<T>* getNext(){
        		return next;
    		}
                void setNext(CardNode<T>* next){
        		this->next = next;
    		}

		 T getCard() const {
        		return card;
    		}
};


template<typename T>
class Deck {
        private:
                CardNode<T>* head;
                CardNode<T>* tail;
        public:
                Deck(): head(nullptr), tail(nullptr) {
    			createStack();
		}

                ~Deck() {
        		destroy(head);
		}

		// destroy the LLL to be called by destructor
                void destroy(CardNode<T>* node){
        		if (node) {
                		destroy(node->getNext());
                		delete node;
			}
		}

		// create a stack of cards to be called by constructor when a Deck object is created
                void createStack(){
        		head = nullptr; 
        		tail = nullptr;

        		// Create a stack of 5 cards for each class
        		for (int i = 0; i < 5; i++) {
                		// Create a new card using the respective class constructor
                		T card;
                        
                		// Set the card description using the operator[]
                		const char* description = card[i];
                		card = description;
                
                		// Create a new CardNode and add it to the deck
                		CardNode<T>* newNode = new CardNode<T>(card);
                		if (head == nullptr) {
                        		head = newNode;
                        		tail = newNode;
                		} else {
                        		tail->setNext(newNode);
                			tail = newNode;
                		}       
        		}// end for loop
		}// end create stack function

		// randomly display a card
		T getRandomCard() {
			// Seed the random number generator with a higher precision timer
    			unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    			srand(seed);

        		// Generate a random number between 0 and the number of cards in the deck
        		int randomIndex = rand() % 5;

        		// Traverse the deck to the randomly selected card
        		CardNode<T>* currentNode = head;
        		for (int i = 0; i < randomIndex; i++) {
            			currentNode = currentNode->getNext();
        		}

        		// Return the card at the random index
        		return currentNode->getCard();
    		}
};

#endif


