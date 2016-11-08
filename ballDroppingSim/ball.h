#pragma once
#include "C:\Users\Dink\Documents\SFML-2.3.2\include\SFML\Graphics\CircleShape.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <math.h>
#include <windows.h>
#define g 9.81
#define m2p 50.0

class ball :
	public sf::CircleShape
{
public:

	ball();

	//connects the ball object to the physical shape (CiricleShape object)
	//the initial position of the ball is set by the vector p0
	void initialize(sf::CircleShape *S, sf::Vector2f *p0);

	//steps forward to the next time frame
	//effects: the position of ball is changed to s[], s[0] being the x position, and s[1] being the y position
	//		   the velocity of the ball is changed to v[], v[0] being the velocity in x, v[1] being the velocity in y
	//		   the initial time used to calculate the next velocity changes to the time right now
	void switchVelo(float v[], float s[]);

	//effect: the ball moves to its next position in the 2D space
	void moveNext(sf::CircleShape *S);

	//modifies: v[] such that v[0] = Vx (the velocity on the ball in the x) and v[1] = Vy (the velocity on the ball in the y)
	void getVelo(float v[]);

	//modifies: s[] such that s[0] = x and s[1] = y 
	void getPosition(float s[]);

	//returns: radius of the ball
	float getRadius();

	//returns mass of the ball
	float getMass();

private:
	//data required for the displacemt and velocity calculations
	float y0, x0, mass, r;
	float x, y;
	float vx0, vy0;
	float t0y, t0x;
	float dty, dtx;
};

