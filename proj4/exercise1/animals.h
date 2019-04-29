// You are to provide files animals.h and animals.cpp that define classes Mouse, Cat, and Person

#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>

#include "positions.h"
#include "park.h"
#include "animals.h"

class Mouse : public Animal {
public:
	Mouse(string s, Position p);
	bool Chase();

};

class Cat : public Animal {
public:
	Cat(string s, Position p);
	bool Chase();

};

class Person : public Animal {
public:
	Person(string s, Position p);
	bool Chase();

};

#endif