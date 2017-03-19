#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
#include <iostream>
#define _USE_MATH_DEFINES
using namespace sf;
using namespace std;

class Branch
{
public:
	Branch(Vector2f, Vector2f);
	~Branch();
	void show(RenderWindow &);
	Branch branch();
protected:
	Vector2f begin;
	Vector2f end;
};

