#include "sprite.hpp"
#include "declarations.hpp"

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H



struct Level {
	int bgImage;
	int x;          // Current x offset
	int width;
	int height;
	int mob;
};

Level currentLevel;


void loadLevelImages() {
	
	if (currentLevelState == LEVEL1)
	{
		currentLevel.bgImage = iLoadImage("assets\\levelMap\\level1_f.png");
		currentLevel.x = 0;
		currentLevel.width = 12800;
		currentLevel.height = 720;
	}
}


void renderLevel() 
{
	if (currentGameState != GAMEPLAY) return;
	iShowImage(currentLevel.x, 0, currentLevel.width, currentLevel.height, currentLevel.bgImage);
	
	

}


void updateLevelScroll() 
{
	if (currentGameState != GAMEPLAY) return;

	int scrollSpeed = 5;
	
	// right shift
	if (harry.x > (SCREEN_WIDTH / 2) - 70 && currentLevel.x > -(currentLevel.width - SCREEN_WIDTH)) 
	{
			harry.x = (SCREEN_WIDTH / 2) - 70;  // Keep hero fixed 
			currentLevel.x -= scrollSpeed;
	}
	// left shift
	if (harry.x < SCREEN_WIDTH / 9 && currentLevel.x < 0) 
	{
		harry.x = SCREEN_WIDTH / 9;  // Keep hero fixed
		currentLevel.x += scrollSpeed;
	}
	


	int worldX = -currentLevel.x;

	checkSpiderSpawn(worldX);
	checkBossSpawn(worldX); 

}


#endif








