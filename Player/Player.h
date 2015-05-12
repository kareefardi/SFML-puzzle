
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
using namespace std;
using namespace sf;


class Player{
public:
	Player();
	Player(Texture character);
	void updatePosition(int &x, int &y, int move, bool valid);
	void getPosition(double &x, double &y);
	void setPosition(double x, double y );
	void setTxtre(string path);
	void setPhase(double posY,int &posX, float &framecounter, double x, double y);
	void setPhase(int posY);
	bool animatePlayer( double posX, double framecounter, RenderWindow win);
	void setScene(char scene[][12]);
	void movePlayer(double x, double y);
	void displayPlayer(RenderWindow &win);
	bool isValid( int x, int y, int move);
	void resetAnimation();
	
private:
	Sprite player;
	int animation;
	double pX, pY;
	char grid[12][12];
	Texture player_texture;
	bool validmove;
};

#endif
