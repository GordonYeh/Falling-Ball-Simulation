#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <math.h>
#include <windows.h>
#include "ball.h"
#include "vectorCalc.h"

#define g 9.81
#define m2p 50.0
#define density 12;
using namespace std;
const float e = 0.7;


ball::ball()
: vx0(0), vy0(0)
{
	t0y = clock();
	t0x = clock();
	srand(time(0));
	r = 35 + rand() % 30;
	mass = 4 / 3 * 3.14* pow(r / m2p, 3) * density;
}

void ball::initialize(sf::CircleShape *S, sf::Vector2f *p0){
	//set the radius
	S->setRadius(r);

	//set origin
	S->setOrigin(sf::Vector2f(r, r));

	//poistion the ball
	x0 = p0->x;
	y0 = p0->y;
	S->setPosition(*p0);
}

void ball::switchVelo(float v[], float s[]){
	x0 = s[0];
	y0 = s[1];
	vx0 = v[0];
	vy0 = v[1];
	t0x = clock();
	t0y = clock();
}

void ball::moveNext(sf::CircleShape *S){
	if (vy0 == 0 || vy0 > 0.01 || vy0 < -0.01){
		//change in time calc
		dty = (clock() - t0y) / (float)CLOCKS_PER_SEC;
		dtx = (clock() - t0x) / (float)CLOCKS_PER_SEC;
		//y displacement calc
		y = (0.5*g*pow(dty, 2) + vy0*dty)*m2p + y0;
		//x displacement calc
		x = vx0*dtx*m2p + x0;

		S->setPosition(sf::Vector2f(x, y));

		//check if it hit the ground or not
		if (y > 1000 - r && vy0 + 0.8*(g*dty) > 0){
			vy0 = -e*(vy0 + (g*dty));
			//vx0 = vx0 + vy0*0.1 - rand() % 2;
			y0 = y;
			x0 = x;
			t0x = clock();
			t0y = clock();
		}

		if (x < (0 + r) || x >(1000 - r)){
			if (x < (0 + r)) x = 0.1 + r;
			else x = 999.9 - r;
			vx0 = -vx0*e;
			x0 = x;
			t0x = clock();
		}

	}
	else if (vx0 != 0){
		vx0 *= 0.98;
		dtx = (clock() - t0x) / (float)CLOCKS_PER_SEC;
		x = vx0*dtx*m2p + x0;
		S->setPosition(sf::Vector2f(x, y));
	}
}


void ball::getVelo(float v[]){
	v[0] = vx0;
	v[1] = (vy0 + (g*dty));
}

void ball::getPosition(float s[]){
	s[0] = x;
	s[1] = y;
}

float ball::getRadius(){
	return r;
}

float ball::getMass(){
	return mass;
}