
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include <time.h>
enum direction{down,left,right,up};
using namespace std;
using namespace sf;


class Enemy{
public:
	Enemy();
	Enemy(Texture character);
	void updatePosition(int &x, int &y, int move, bool valid);
	void getPosition(double &x, double &y);
	void setPosition(double x, double y );
	void setTxtre(string path);
	void setPhase(double posY,int &posX, float &framecounter, double x, double y, int &l);
	void setScene(char scene[][12]);
	void moveEnemy();
	void displayEnemy(RenderWindow &win);
	bool isValid( int x, int y, int move);
	void animateEnemy();
	void resetAnimation();
	int animation;
	int pX,pY;
	float framecounter,framelimit,frameswitch;
private:
	Sprite enemy;
	int posX, posY;
	double enemymoveX,enemymoveY;
	char grid[12][12];
	bool moving;
	bool valid;
	int i;
	int enemyMove;
	Texture enemy_texture;
	bool validmove;
};

#endif
