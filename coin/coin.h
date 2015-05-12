#ifndef COIN_H
#define COIN_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace std;
using namespace sf;


class coin
{
public: 
	Sprite coinsprite;
	coin();
    coin(const sf::Texture& cointexture);
	void coinsettexture(string coinpath);
	void setcoinposition(int x,int y);
	void animatecoin(int cposx,int framecounter1);
	~coin();
	
private:
	
	Texture cointexture;
	string coinpath;
	int x,y;
	float framecounter1,framelimit1,frameswitch1;
	
};

#endif
