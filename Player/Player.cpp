#include"Player.h"

Player::Player(){
	pX=pY=0;
	animation=0;
}

Player::Player(Texture character){
	player.setTexture(character);
	pX=pY=0;

}

void Player::setTxtre(string path){

	if(!player_texture.loadFromFile(path)){
		cout<<"error cannot load background"<<endl;
	}
	player.setTexture(player_texture);
}

void Player::setPosition(double x, double y){
	player.setPosition(x,y);
}

bool Player::isValid( int x, int y, int move){
	int j=y;
	int i=x;
	switch(move){
	case 1: y++; break;
	case 2: y--; break;
	case 3: x--; break;
	case 4: x++; break;
	}
	if(int(grid[i][j]-grid[x][y])==int('.')-int('#'))
		return false;
	return true;
}

void Player::updatePosition(int &x, int &y, int move, bool valid){
	if(valid){
		switch(move){
		case 1: y++; break;
		case 2: y--; break;
		case 3: x--; break;
		case 4: x++; break;
		}
	}
}
void Player::getPosition(double &x, double &y){
	x=pX;
	y=pY;
}

void Player::setScene(char scene[][12]){
	for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)
			grid[i][j]=scene[i][j];
}

void Player::movePlayer(double x, double y){
	player.move(x,y);
}

void Player::displayPlayer(RenderWindow &win){
	win.draw(player);
}

void Player::setPhase(double posY, int &posX, float &framecounter,double x, double y){
	if(framecounter>=5&&animation<10 ){
		framecounter=0;
		posX++;
		cout<<animation<<endl;
		animation=animation%10+1;
		if(posX*32>=player_texture.getSize().x){
			posX=0;
		}
		player.move(x,y);
	}
	
	player.setTextureRect(IntRect(posX*32,posY*32,32,32));
}

void Player::resetAnimation(){
	animation=0;
}

void Player::setPhase(int posY){
	player.setTextureRect(IntRect(32,posY*32,32,32));
}
