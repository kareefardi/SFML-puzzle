#include"Enemy.h"

Enemy::Enemy(){
	pX=pY=0;
	animation=0;moving=false;
	valid=false;posX=0;
	enemymoveX=0;enemymoveY=0;
	enemyMove=0;i=0;
	framecounter=0;framelimit=120;frameswitch=5;
}
Enemy::Enemy(Texture character){
	enemy.setTexture(character);
	pX=pY=0;

}
void Enemy::setTxtre(string path){

	if(!enemy_texture.loadFromFile(path)){
		cout<<"error cannot load background"<<endl;
	}
	enemy.setTexture(enemy_texture);
}
void Enemy::setPosition(double x, double y){
	enemy.setPosition(x,y);
}
bool Enemy::isValid( int x, int y, int move){
	int j=y;
	int i=x;
	switch(move){
	case 1: y++; break;
	case 2: y--; break;
	case 3: x--; break;
	case 4: x++; break;
	}
	//cout<<grid[i][j]<<" "<<grid[x][y]<<" " <<i<<" "<< j<<" "<<x<< " "<<y<<endl;
	if(int(grid[i][j]-grid[x][y])==int('.')-int('#'))
		return false;
	return true;
}
void Enemy::updatePosition(int &x, int &y, int move, bool valid){
	if(valid){
		
		switch(move){
		case 1: y++; break;
		case 2: y--; break;
		case 3: x--; break;
		case 4: x++; break;
		}
	}
}
void Enemy::setScene(char scene[][12]){
	for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)
			grid[i][j]=scene[i][j];
}
void Enemy::displayEnemy(RenderWindow &win){
	win.draw(enemy);
}
void Enemy::setPhase(double posY, int &posX, float &framecounter,double x, double y, int &l){
	//cout<<framecounter<<" "<<animation<<endl;
	if(framecounter>=5&&l<10 ){
		cout<<x<<" "<<y<<endl;
		l=l%10+1;
		framecounter=0;
		posX++;
		//cout<<"sdsdafd";
		if(posX*32>=enemy_texture.getSize().x){
			posX=0;
		}
		enemy.move(x,y);
	}

	enemy.setTextureRect(IntRect(posX*32,posY*32,32,32));
}
void Enemy::animateEnemy(){
	if(!moving){		
			enemyMove=rand()%4+1;
			valid=isValid(pX,pY,enemyMove);
			
			if (valid){
				i=0;
				switch(enemyMove){
				case 1: enemymoveY=3.2;enemymoveX=0;posY=2; break;
				case 2: enemymoveY=-3.2;enemymoveX=0;posY=1;break;
				case 3: enemymoveX=-3.2;enemymoveY=0;posY=3; break;
				case 4: enemymoveX=3.2;enemymoveY=0;posY=0; break;
				}
			}
		}
		if(i<=10){	
			setPhase(posY,posX,framecounter,enemymoveY,enemymoveX,i);
			moving=true;
		}
		if(i>=10){updatePosition(pX,pY,enemyMove,valid);moving =false;}	
}
