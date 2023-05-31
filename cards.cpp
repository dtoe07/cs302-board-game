
// implementations for cards.h header file

#include "cards.h"

//////////////////////////////////////////////////////////////////////////////////////////////
// Card base class ---------------------------------------------------------------------------

Card::Card() {
    	toDo = nullptr;
}

Card::Card(const Card& other) {
    	// Allocate memory for the new toDo string
    	toDo = new char[strlen(other.toDo) + 1];

    	// Copy the contents of the other.toDo string to this->toDo
    	strcpy(toDo, other.toDo);
}

Card::~Card() {
        delete[] toDo;
}

const char* Card::getToDo() const {
    return toDo;
}

// Operators:+++++++++++++++++++++++++++++++++++++++++

// =
Card& Card::operator=(const char* _toDo) {
    	delete[] toDo;
    	toDo = new char[MAX_CHAR];
    	strcpy(toDo, _toDo);
    	return *this;
}

// <<
ostream& Card::operator<<(ostream& os) const {
    	return os << getToDo();
}


// >>
istream& Card::operator>>(istream& is) {
    	char buffer[MAX_CHAR];
    	is.getline(buffer, MAX_CHAR);
    	*this = buffer;
    	return is;
}

// ==
bool Card::operator==(const Card& other) const {
    	return strcmp(getToDo(), other.getToDo()) == 0;
}

// !=
bool Card::operator!=(const Card& other) const {
    	return !(*this == other);
}

// +
const char* Card::operator+(const Card& other) const {
    	size_t combinedLength = strlen(toDo) + strlen(other.toDo) + 4;
    	char* combinedDescription = new char[combinedLength];
    	strcpy(combinedDescription, toDo);
	strcat(combinedDescription, " + "); // Add a space
    	strcat(combinedDescription, other.toDo);
    	return combinedDescription;
}

// +=
Card& Card::operator+=(const Card& other) {
	size_t combinedLength;
    	if(toDo) combinedLength = strlen(toDo) + strlen(other.toDo) + 4;
	else combinedLength = strlen(toDo) + strlen(other.toDo) + 1;
    	char* combinedDescription = new char[combinedLength];
    	strcpy(combinedDescription, toDo);
	if(toDo) strcat(combinedDescription, " + "); // Add a space only if toDo is not empty
    	strcat(combinedDescription, other.toDo);
    	delete[] toDo;
    	toDo = combinedDescription;
    	return *this;
}

// friend function to help with >> operator
istream& operator>>(istream& is, Card& card) {
    	char buffer[MAX_CHAR];
    	is.getline(buffer, MAX_CHAR);
    	card = buffer;
    	return is;
}


//////////////////////////////////////////////////////////////////////////////////////////////
// Obstacle class ----------------------------------------------------------------------------

// randomly initialize a card within the list
Obstacle::Obstacle() : Card() {
//    	random_shuffle(obstacles.begin(), obstacles.end());
	*this = obstacles[0];
//	cout << "new card created"  << endl;
}

Obstacle::Obstacle(const Obstacle& other) : Card(other) {
    	obstacles = other.obstacles;
}

Obstacle& Obstacle::operator=(const char* _toDo) {
    	Card::operator=(_toDo);
    	return *this;
}

ostream& Obstacle::operator<<(ostream& os) const {
	return os << this->getToDo();;
}

// friend function to help <<
ostream& operator<<(ostream& os, const Obstacle& obstacle) {
    	return obstacle.operator<<(os);
}

istream& Obstacle::operator>>(istream& is) {
    	return Card::operator>>(is);
}

bool Obstacle::operator==(const Card& other) const {
    	return Card::operator==(other);
}

bool Obstacle::operator!=(const Card& other) const {
    	return !(*this == other);
}

const char* Obstacle::operator+(const Card& other) const {
    	return Card::operator+(other);
}

Card& Obstacle::operator+=(const Card& other) {
    	return Card::operator+=(other);
}

const char* Obstacle::operator[](int index) const {
    	if (index >= 0 && index < obstacles.size()) {
        	return obstacles[index];
    	}
    	else {
        	// Handle index out of range error
        	throw std::out_of_range("Index out of range");
    	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Challenge class ----------------------------------------------------------------------------

Challenge::Challenge() : Card() {
    	random_shuffle(challenges.begin(), challenges.end());
    	*this = challenges[0];
}

Challenge::Challenge(const Challenge& other) : Card(other) {
	challenges = other.challenges;
}


Challenge& Challenge::operator=(const char* _toDo) {
    	Card::operator=(_toDo);
    	return *this;
}

ostream& Challenge::operator<<(ostream& os) const {
    	return os << this->getToDo();
}

// friend function to help <<
ostream& operator<<(ostream& os, const Challenge& challenge) {
    	return challenge.operator<<(os);
}

istream& Challenge::operator>>(istream& is) {
    	return Card::operator>>(is);
}

bool Challenge::operator==(const Card& other) const {
        return Card::operator==(other);
}

bool Challenge::operator!=(const Card& other) const {
    	return !(*this == other);
}

const char* Challenge::operator+(const Card& other) const {
    	return Card::operator+(other);
}

Card& Challenge::operator+=(const Card& other) {
    	return Card::operator+=(other);
}


const char* Challenge::operator[](int index) const {
    	if (index >= 0 && index < challenges.size()) {
        	return challenges[index];
    	}
    	else {
        	// Handle index out of range error
        	throw std::out_of_range("Index out of range");
    	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Wild class ---------------------------------------------------------------------------------

Wild::Wild() : Card() {
    	random_shuffle(wilds.begin(), wilds.end());
    	*this = wilds[0];
}

Wild::Wild(const Wild& other) : Card(other) {
	wilds = other.wilds;
}


Wild& Wild::operator=(const char* _toDo) {
    Card::operator=(_toDo);
    return *this;
}

ostream& Wild::operator<<(ostream& os) const {
    	return os << this->getToDo();
}

// friend function to help <<
ostream& operator<<(ostream& os, const Wild& wild) {
    	return wild.operator<<(os);
}

istream& Wild::operator>>(istream& is) {
    	return Card::operator>>(is);
}

bool Wild::operator==(const Card& other) const {
        return Card::operator==(other);
}

bool Wild::operator!=(const Card& other) const {
    	return !(*this == other);
}

const char* Wild::operator+(const Card& other) const {
    	return Card::operator+(other);
}


Card& Wild::operator+=(const Card& other) {
    	return Card::operator+=(other);
}

const char* Wild::operator[](int index) const {
    	if (index >= 0 && index < wilds.size()) {
        	return wilds[index];
    	}
    	else {
        	// Handle index out of range error
        	throw std::out_of_range("Index out of range");
    	}
}











