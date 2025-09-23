#include "iGraphics.h"
#include "declarations.hpp"
#include "menuManager.hpp"
#include "levelManager.hpp"
#include "sounds.hpp"
#include "sprite.hpp"


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: reset start :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

static void clearProjectiles() {
	for (int i = 0; i < MAX_FIREBALLS; i++) fireballs[i].alive = false;
}

static void resetBossState() {
	malfoy.hp = BOSS_BASE_HP;
	malfoy.alive = false;
	malfoy.spawned = false;
	malfoy.isAttacking = false;
	malfoy.hitCooldown = 0;
	malfoy.attackCooldown = 0;
	malfoy.attackWindow = 0;
	malfoy.fireballCooldown = 0;
	malfoy.meleeActive = false;
	malfoy.rangedCasting = false;
	malfoy.entering = false;
	malfoy.x = SCREEN_WIDTH;  
	malfoy.y = 45;
}

static void resetSpiders() {
	initSpider(); 
	spiderCnt = spiderCount;
}

static void resetHero() {
	initHealthBar();          
	heroScore = 0;
	harry.x = 0;  harry.y = 20;
	harry.rightIndex = harry.leftIndex = 0;
	harry.isAttacking = false;
	attackWindow = 0;
	harry_state = harry_still;
	lookRight = true;
	heroDamageCooldown = 0;
}

static void resetLevelScrollState() {

	currentLevelState = LEVEL1;
	currentLevel.x = 0;
}

static void fullResetCore() {
	resetHero();
	resetSpiders();
	resetBossState();
	clearProjectiles();
	resetLevelScrollState();
}




//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: reset end :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://


void win_lose_score(){
	
	if (currentGameState == WINSCREEN || currentGameState == GAMEOVER) {
		int bg = (currentGameState == WINSCREEN) ? win : lose;
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, bg);
		
		char scoreTxt[64];
		sprintf_s(scoreTxt, "%d", heroScore);
		iSetColor(64,22,2);
		iText(766, 350, scoreTxt, GLUT_BITMAP_TIMES_ROMAN_24);
		return;
	}
}


void iDraw() {
	iClear();

	win_lose_score();
	if ( currentGameState == WINSCREEN ||currentGameState == GAMEOVER) return; 
	

	gamestateChanger();
	menuButtonHover();
	houseFlagHover();
	levelHover();

	renderLevel();
	renderHero();
	renderSpider();
	renderBoss();

	checkHeroAttackCollision();

	renderFireballs();
	renderHUD();
	renderBossHUD();
}
	


void iMouseMove(int mx, int my){}


void iPassiveMouseMove(int mx, int my)
{
	hoverButtonPosition(mx, my);
	
	hoverHouseFlagPosition(mx, my);
	
	hoverLevelPosition(mx, my);
}


void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		printf("x = %d\ny = %d\n", mx, my);

		if (currentGameState == MENU )
			menuButtonClicker(mx, my);
		
		else if (currentGameState == HOUSE_SELECTION)
			houseFlagClicker(mx, my);
		
		else if (currentGameState == LEVEL_SELECTION)
			levelClicker(mx, my);
		
		else if (currentGameState == CONTROLS)
			controlsClicker(mx, my);
		
		else if (currentGameState == PAUSE_MENU)
			pauseMenuClicker(mx, my);
	
		else if (currentGameState == PAUSE_CONTROLS)
			pauseControlsClicker(mx, my);

		else if (currentGameState == WINSCREEN || currentGameState == GAMEOVER)
			winLoseScreenClicker(mx, my);

		else if (currentGameState == SCORE || currentGameState== CREDITS)
			commonButtonClicker(mx, my);

	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

// Special Keys:
// GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
// GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT


void gameControls(){
	if (currentGameState != GAMEPLAY) return;
	if (isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		heroMoveLeft();
		updateLevelScroll();
	}
	if (isKeyPressed('d') || isSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		heroMoveRight();
		updateLevelScroll();
	}
	if (isKeyPressed('f') || isKeyPressed(32)) // isKeyPressed() checks ASCII value. ASCII for spacebar = 32;
	{
		heroAttack();
	}
	if (!(isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT)) &&
		!(isKeyPressed('d') || isSpecialKeyPressed(GLUT_KEY_RIGHT)) &&
		!(isKeyPressed('f') || isKeyPressed(32)))
	{
		harry_state = harry_still;
	}
}

void menuControls(){

	bool pause = true;

	static bool escLatch = false;                 
	bool escNow = isKeyPressed(27);               

	if (currentGameState == GAMEPLAY) {
		if (escNow && !escLatch) {
			currentGameState = PAUSE_MENU;        
		}
	}
	else if (currentGameState == PAUSE_MENU) {
		
		 if (escNow && !escLatch) {
		     currentGameState = GAMEPLAY;       
		 }
		escLatch = escNow;
		return;
	}
	escLatch = escNow;

	if (currentGameState != GAMEPLAY) return;
}



void fixedUpdate()
{
	gameControls();
	menuControls();
			
}

int main() {
	iInitialize(SCREEN_WIDTH, SCREEN_HEIGHT, "Ashborn: Echoes of Defiance");

	iSetTimer(70, animateHero);

	iSetTimer(130, updateSpiderFrame);
	iSetTimer(50, moveSpider);

	iSetTimer(50, moveMalfoy);
	iSetTimer(70, updateMalfoyFrame);

	iSetTimer(50, moveFireballs); 


	menuImageSourcer();
	heroImageSourcer();
	spiderImageSourcer();
	bossImageSourcer(); 
	initSpider();
	bossProjectileImageSourcer(); 
	initFireballs();              
	        


	loadLevelImages();
	menuMusic();
	iStart();
	return 0;
}