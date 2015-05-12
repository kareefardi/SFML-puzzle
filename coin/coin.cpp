#include "coin.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

coin::coin(){

}


coin::~coin() {}



void coin::setcoinposition(int x,int y){
	if(x!=0 && y!=0){
	coinsprite.setPosition(x,y);
	}
}

void coin::coinsettexture(string coinpath){
	if(!cointexture.loadFromFile(coinpath)){
	cout<<"error cannot load background"<<endl;
	}
	coinsprite.setTexture(cointexture);
}

void coin::animatecoin(int cpx,int framecounter){
	float framelimit1=400,frameswitch1=2;
				if(framecounter>=frameswitch1){
			framecounter=0;
		cpx++;
	if(cpx>=7){
		cpx=0;
			}
		}
	coinsprite.setTextureRect(IntRect(cpx*32,0,32,32));
}
