#ifndef SPRITE_H
#define SPRITE_H

#include "menuManager.hpp"
#include <stdio.h>

#if defined(_MSC_VER)
#define SAFE_SNPRINTF(buf, size, fmt, ...) sprintf_s((buf), (size), (fmt), __VA_ARGS__)
#else
#define SAFE_SNPRINTF(buf, size, fmt, ...) snprintf((buf), (size), (fmt), __VA_ARGS__)
#endif


// Health bar config                                                                                      
#define HERO_MAX_HP        100                                            
#define HP_BAR_WIDTH       220                                                                            
#define HP_BAR_HEIGHT      18
#define HP_BAR_MARGIN_X    20   
#define HP_BAR_MARGIN_Y    20   


void initHealthBar(void);
void hero_take_damage(int dmg);
void hero_heal(int amount);                                                                               
void renderHUD(void);														                              
																										  




/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  Hero Start  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int heroHP = 100;    
int heroScore = 0;  

int attackWindow = 0;          
const int attackWindowMax = 8; 


struct Hero {

	int x, y, width, height, attImgWidth;
	
	int rightCount, rightIndex;
	int leftCount, leftIndex;
	
	int GmoveRight[100];
	int GmoveLeft[100];
	int SmoveRight[100];
	int SmoveLeft[100];
	int HmoveRight[100];
	int HmoveLeft[100];
	int RmoveRight[100];
	int RmoveLeft[100];
	
	bool isAttacking;

	int GstillImageRight;
	int GstillImageLeft;
	int SstillImageRight;
	int SstillImageLeft;
	int HstillImageRight;
	int HstillImageLeft;
	int RstillImageRight;
	int RstillImageLeft;

	int GattackRight;
	int GattackLeft;
	int SattackRight;
	int SattackLeft;
	int HattackRight;
	int HattackLeft;
	int RattackRight;
	int RattackLeft;

	Hero(){}

	Hero(int _x, int _y, int _width, int _height, int _attImgWidth){
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		attImgWidth = _attImgWidth;

		// Initializing animation index
		rightCount = rightIndex = 0;
		leftCount = leftIndex = 0;

		isAttacking = false;
		
	}
}; 


Hero harry = Hero(0, 20, 452, 339, 904); //Initializing Harry [5th value is for attack image(sloppy bugfix)]


void heroImageSourcer() 
{

	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: GRYFFINDOR ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\\

		harry.GstillImageRight = iLoadImage("assets\\sprites\\Gryffindor\\gryffindor_harry_right_walk\\g_harry_stand_right.png");
		harry.GstillImageLeft = iLoadImage("assets\\sprites\\Gryffindor\\gryffindor_harry_left_walk\\g_harry_stand_left.png");

		harry.GattackRight = iLoadImage("assets\\sprites\\Gryffindor\\gryffindor_harry_attack\\g_attack_right.png");
		harry.GattackLeft = iLoadImage("assets\\sprites\\Gryffindor\\gryffindor_harry_attack\\g_attack_left.png");

		harry.rightCount = 11;
		for (int i = 0; i < harry.rightCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Gryffindor\\gryffindor_harry_right_walk\\g_wr%d.png", i + 1);
			harry.GmoveRight[i] = iLoadImage(path);
		}

		harry.leftCount = 11;
		for (int i = 0; i < harry.leftCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Gryffindor\\gryffindor_harry_left_walk\\g_wl%d.png", i + 1);
			harry.GmoveLeft[i] = iLoadImage(path);
		}
	


	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: SLYTHERIN ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\\


			
		harry.SstillImageRight = iLoadImage("assets\\sprites\\Slytherin\\slytherin_harry_right_walk\\s_harry_stand_right.png");
		harry.SstillImageLeft = iLoadImage("assets\\sprites\\Slytherin\\slytherin_harry_left_walk\\s_harry_stand_left.png");

		harry.SattackRight = iLoadImage("assets\\sprites\\Slytherin\\slytherin_harry_attack\\s_attack_right.png");
		harry.SattackLeft = iLoadImage("assets\\sprites\\Slytherin\\slytherin_harry_attack\\s_attack_left.png");

		harry.rightCount = 11;
		for (int i = 0; i < harry.rightCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Slytherin\\slytherin_harry_right_walk\\s_wr%d.png", i + 1);
			harry.SmoveRight[i] = iLoadImage(path);
		}

		harry.leftCount = 11;
		for (int i = 0; i < harry.leftCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Slytherin\\slytherin_harry_left_walk\\s_wl%d.png", i + 1);
			harry.SmoveLeft[i] = iLoadImage(path);
		}


	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: HUFFLEPUFF ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\\


		harry.HstillImageRight = iLoadImage("assets\\sprites\\Hufflepuff\\hufflepuff_harry_right_walk\\h_harry_stand_right.png");
		harry.HstillImageLeft = iLoadImage("assets\\sprites\\Hufflepuff\\hufflepuff_harry_left_walk\\h_harry_stand_left.png");

		harry.HattackRight = iLoadImage("assets\\sprites\\Hufflepuff\\hufflepuff_harry_attack\\h_attack_right.png");
		harry.HattackLeft = iLoadImage("assets\\sprites\\Hufflepuff\\hufflepuff_harry_attack\\h_attack_left.png");

		harry.rightCount = 11;
		for (int i = 0; i < harry.rightCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Hufflepuff\\hufflepuff_harry_right_walk\\h_wr%d.png", i + 1);
			harry.HmoveRight[i] = iLoadImage(path);
		}

		harry.leftCount = 11;
		for (int i = 0; i < harry.leftCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Hufflepuff\\hufflepuff_harry_left_walk\\h_wl%d.png", i + 1);
			harry.HmoveLeft[i] = iLoadImage(path);
		}

	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: RAVENCLAW ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\\

		harry.RstillImageRight = iLoadImage("assets\\sprites\\Ravenclaw\\ravenclaw_harry_right_walk\\r_harry_stand_right.png");
		harry.RstillImageLeft = iLoadImage("assets\\sprites\\Ravenclaw\\ravenclaw_harry_left_walk\\r_harry_stand_left.png");

		harry.RattackRight = iLoadImage("assets\\sprites\\Ravenclaw\\ravenclaw_harry_attack\\r_attack_right.png");
		harry.RattackLeft = iLoadImage("assets\\sprites\\Ravenclaw\\ravenclaw_harry_attack\\r_attack_left.png");

		harry.rightCount = 11;
		for (int i = 0; i < harry.rightCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Ravenclaw\\ravenclaw_harry_right_walk\\r_wr%d.png", i + 1);
			harry.RmoveRight[i] = iLoadImage(path);
		}

		harry.leftCount = 11;
		for (int i = 0; i < harry.leftCount; i++) {
			char path[100];
			sprintf_s(path, "assets\\sprites\\Ravenclaw\\ravenclaw_harry_left_walk\\r_wl%d.png", i + 1);
			harry.RmoveLeft[i] = iLoadImage(path);
		}
}


bool lookRight = true;

void renderHero()
{
	if (currentGameState != (GAMEPLAY)) return;

	if (currentHouseState == GRYFFINDOR)
	{
		if (harry_state == harry_still)
		{
			if (lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.GstillImageRight);
			else if (!lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.GstillImageLeft);
		}
		else if (harry_state == left)
		{
			lookRight = false;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.GmoveLeft[harry.leftIndex]);
		}
		else if (harry_state == right)
		{
			lookRight = true;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.GmoveRight[harry.rightIndex]);
		}
		else if (harry_state == attack)
		{
			if (lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.GattackRight);
			else if (!lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.GattackLeft);
		}
	}

	else if (currentHouseState == SLYTHERIN)
	{
		if (harry_state == harry_still)
		{
			if (lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.SstillImageRight);
			else if (!lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.SstillImageLeft);
		}
		else if (harry_state == left)
		{
			lookRight = false;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.SmoveLeft[harry.leftIndex]);
		}
		else if (harry_state == right)
		{
			lookRight = true;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.SmoveRight[harry.rightIndex]);
		}
		else if (harry_state == attack)
		{
			if (lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.SattackRight);
			else if (!lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.SattackLeft);
		}
	}

	else if (currentHouseState == HUFFLEPUFF)
	{
		if (harry_state == harry_still)
		{
			if (lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.HstillImageRight);
			else if (!lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.HstillImageLeft);
		}
		else if (harry_state == left)
		{
			lookRight = false;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.HmoveLeft[harry.leftIndex]);
		}
		else if (harry_state == right)
		{
			lookRight = true;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.HmoveRight[harry.rightIndex]);
		}
		else if (harry_state == attack)
		{
			if (lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.HattackRight);
			else if (!lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.HattackLeft);
		}
	}

	else if (currentHouseState == RAVENCLAW)
	{
		if (harry_state == harry_still)
		{
			if (lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.RstillImageRight);
			else if (!lookRight) iShowImage(harry.x, harry.y, harry.width, harry.height, harry.RstillImageLeft);
		}
		else if (harry_state == left)
		{
			lookRight = false;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.RmoveLeft[harry.leftIndex]);
		}
		else if (harry_state == right)
		{
			lookRight = true;
			iShowImage(harry.x, harry.y, harry.width, harry.height, harry.RmoveRight[harry.rightIndex]);
		}
		else if (harry_state == attack)
		{
			if (lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.RattackRight);
			else if (!lookRight) iShowImage(harry.x - 225, harry.y, harry.attImgWidth, harry.height, harry.RattackLeft);
		}
	}


	
}


void animateHero() 
{
	if (currentGameState != GAMEPLAY) return;

	if (harry_state == right) 
	{
		harry.rightIndex++;
		if (harry.rightIndex >= harry.rightCount) harry.rightIndex = 0;
	}
	else if (harry_state == left) 
	{
		harry.leftIndex++;		
		if (harry.leftIndex >= harry.leftCount) harry.leftIndex = 0;
	}		
	else if (harry_state == attack && harry.isAttacking) 
	{
		if (attackWindow > 0) {
			attackWindow--;            
		}
		else {
			harry.isAttacking = false; // attack ends
			harry_state = harry_still; // return to idle
		}
	}
}


void heroMoveRight()
{
	harry_state = right;
	
	if (currentGameState == GAMEPLAY){
		if (harry.x <= (SCREEN_WIDTH / 2) - 70) harry.x += 5;
	}
}

void heroMoveLeft()
{
	harry_state = left;

	if (currentGameState == GAMEPLAY){
		if (harry.x >= SCREEN_WIDTH / 9) harry.x -= 5;
	}
}



void heroAttack() {
	harry_state = attack;
	if (currentGameState == GAMEPLAY){
		harry.isAttacking = true;
		attackWindow = attackWindowMax;
	}
}





// Hero damage tuning
const int HERO_CONTACT_DAMAGE = 1;
const int HERO_HIT_COOLDOWN_TICKS = 8;
int heroDamageCooldown = 0;


void initHealthBar(void) {
	heroHP = HERO_MAX_HP;
}

// Centralized damager
void hero_take_damage(int dmg) {
	if (heroDamageCooldown > 0 || heroHP <= 0) return;
	heroHP -= dmg;
	if (heroHP <= 0) {
		heroHP = 0;
		currentGameState = GAMEOVER;
		return;
	}
	heroDamageCooldown = HERO_HIT_COOLDOWN_TICKS;
}






/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  Hero End  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/


/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  Creep Start  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
                                                               
                                                                                            
struct Creep {
	int x, y;
	int width, height;
	int hp;
	bool alive;
	int frame, frameCount;
	int creepCount;
	int creepRun[100];
	bool spawned;

	int hitCooldown; 

	Creep(){}

	Creep(int x, int y, int width, int height, int hp, int frameCount){
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->hp = hp;
		this->frameCount = frameCount;

		this->alive = true;
		this->frame = 0;
		this->hitCooldown = 0;
	}

};


/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  spider  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

const int SPIDER_HIT_COOLDOWN_TICKS = 3;
int const spiderCount = 10;
int spiderCnt = 10;
Creep spider[spiderCount];
int spiderSpawnAt[spiderCount] = { 500, 1000, 1700 ,3200, 4500, 6000, 7500, 8900, 9700, 10000};



void initSpider() {
	for (int i = 0, j = 0; i < spiderCount; i++) {
		int spider_x = SCREEN_WIDTH;
		spider[i] = Creep(spider_x, 43, 326, 200, 3+i, 5); 
		spider[i].spawned = false;
	}
}


int spiderRun[5];  

void spiderImageSourcer() {
	
	for (int i = 0; i < 5; i++){
		char path[100];
		sprintf_s(path, "assets\\creeps\\spider\\s%d.png", i + 1);
		spiderRun[i] = iLoadImage(path);
	}

}
void checkSpiderSpawn(int worldX) {
	for (int i = 0; i < spiderCount; i++) {
		if (!spider[i].spawned && worldX >= spiderSpawnAt[i]) {
			spider[i].spawned = true;

		}
	}
}
void updateSpiderFrame() {
	if (currentGameState != GAMEPLAY) return;
	for (int i = 0; i < spiderCount; i++) {
		if (spider[i].alive) {
			spider[i].frame = (spider[i].frame + 1) % spider[i].frameCount;
		}
	}
}
void renderSpider() {
	if (currentGameState != GAMEPLAY) return;
	if (currentGameState != GAMEPLAY && currentLevelState != LEVEL1) return;

	for (int i = 0; i < spiderCount; i++) {
		if (!spider[i].alive || !spider[i].spawned) continue;
		iShowImage(spider[i].x, spider[i].y, spider[i].width, spider[i].height, spiderRun[spider[i].frame]);

	}
}

void moveSpider() {

	if (currentGameState != GAMEPLAY) return;
	for (int i = 0; i < spiderCount; i++) {
		if (!spider[i].alive || !spider[i].spawned) continue;

		if (spider[i].hitCooldown > 0) spider[i].hitCooldown--;
		
		if (heroDamageCooldown > 0) heroDamageCooldown--;

		//check position
		if (spider[i].x <= harry.x + harry.width - 200) {
			
			spider[i].x = harry.x + harry.width - 200; //fix spider
					
			hero_take_damage(HERO_CONTACT_DAMAGE);
			continue; // skip movement
		}
		
		spider[i].x -= 5;	// Move spider
	}
}


void renderHUD() {
	if (currentGameState != GAMEPLAY) return;

	// Position
	int barX = HP_BAR_MARGIN_X;
	int barY = SCREEN_HEIGHT - HP_BAR_MARGIN_Y - HP_BAR_HEIGHT;

	// Bar background and border
	iSetColor(50, 50, 50);
	iFilledRectangle(barX, barY, HP_BAR_WIDTH, HP_BAR_HEIGHT);

	iSetColor(0, 0, 0);
	iRectangle(barX, barY, HP_BAR_WIDTH, HP_BAR_HEIGHT);

	// Robust max-HP reference:
	static int hudMaxHP = -1;
	if (hudMaxHP <= 0) {
		hudMaxHP = (HERO_MAX_HP > 0) ? HERO_MAX_HP : heroHP; 
	}
	if (heroHP > hudMaxHP) {
		hudMaxHP = heroHP; 
	}


	float ratio = (hudMaxHP > 0) ? (float)heroHP / (float)hudMaxHP : 0.0f;
	if (ratio < 0.0f) ratio = 0.0f;
	if (ratio > 1.0f) ratio = 1.0f;

	int innerW = HP_BAR_WIDTH - 2;
	int fillW = (int)(ratio * (float)innerW);

	// Color by health
	if (ratio > 0.5f)        iSetColor(0, 158, 4);
	else if (ratio > 0.25f)  iSetColor(255, 200, 0);
	else                     iSetColor(220, 40, 40);

	if (fillW > 0) {
		iFilledRectangle(barX + 1, barY + 1, fillW, HP_BAR_HEIGHT - 2);
	}

	// Text overlays
	iSetColor(0, 0, 0);
	char hpTxt[32];
	sprintf_s(hpTxt, sizeof(hpTxt), "HP: %d/%d", heroHP, hudMaxHP);
	iText(barX + 8, barY + 4, hpTxt, GLUT_BITMAP_HELVETICA_12);

	iSetColor(255, 255, 255);
	char scoreTxt[64];
	sprintf_s(scoreTxt, sizeof(scoreTxt), "Score: %d", heroScore);
	iText(barX + HP_BAR_WIDTH + 20, barY + 2, scoreTxt, GLUT_BITMAP_HELVETICA_18);
	
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  Spider end  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/




/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  boss start ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

// Boss tuning
const int BOSS_WORLD_SPAWN_X = 10500;  
const int BOSS_BASE_HP = 50;           
const int BOSS_SPEED = 5;             
const int BOSS_CONTACT_DAMAGE = 2;     
const int MALFOY_HIT_COOLDOWN_TICKS = 3; 
const int MALFOY_ATTACK_WINDOW_MAX = 6;  

const int BOSS_FIXED_SCREEN_X = SCREEN_WIDTH - 500; 
const int BOSS_ENTRY_START_X = SCREEN_WIDTH + 120; 

const int BOSS_MELEE_TRIGGER_GAP = 80;  
const int BOSS_RANGED_TRIGGER_GAP = 186;  
const int BOSS_MELEE_STRIKE_GAP = -170;  

const int FIREBALL_SPEED = 8;    
const int FIREBALL_DAMAGE = 2;    
const int FIREBALL_COOLDOWN_TICKS = 50; 
const int FIREBALL_WIDTH = 94;
const int FIREBALL_HEIGHT = 53;

struct Boss {
	int x, y;
	int width, height;
	int hp;
	bool alive;
	bool spawned;
	bool isAttacking;

	int hitCooldown;
	int attackCooldown;
	int attackWindow;

	int stillImg;
	int attackImg;

	int fireballCooldown;

	
	bool meleeActive;     
	bool rangedCasting;   

	
	int rangedImg;        
	bool entering;

	Boss() {}
	Boss(int x, int y, int w, int h, int hp) {
		this->x = x; this->y = y;
		this->width = w; this->height = h;
		this->hp = hp;
		alive = false;
		spawned = false;
		isAttacking = false;

		hitCooldown = 0;
		attackCooldown = 0;
		attackWindow = 0;
		fireballCooldown = 0;

		meleeActive = false;
		rangedCasting = false;

		
		rangedImg = -1;
		entering = false;
	}
};

Boss malfoy = Boss(SCREEN_WIDTH, 45, 420, 300, BOSS_BASE_HP);

int malfoyIdleImg;
int malfoyAttackImg;

void bossImageSourcer() {

	malfoy.stillImg = iLoadImage("assets\\boss\\level1\\malfoy0.png");
	malfoy.attackImg = iLoadImage("assets\\boss\\level1\\malfoy1.png");
	malfoy.rangedImg = iLoadImage("assets\\boss\\level1\\malfoy2.png");

}
int fireballImg = -1;
void bossProjectileImageSourcer() {
	fireballImg = iLoadImage("assets\\fireball.png"); 

}


struct Fireball {
	int x, y, w, h;
	int vx;
	bool alive;
	Fireball() : x(0), y(0), w(0), h(0), vx(0), alive(false) {}
};

const int MAX_FIREBALLS = 12;
Fireball fireballs[MAX_FIREBALLS];

void initFireballs() {
	for (int i = 0; i < MAX_FIREBALLS; i++) fireballs[i].alive = false;
}

void spawnFireballFromMalfoy() {
	for (int i = 0; i < MAX_FIREBALLS; i++) {
		if (!fireballs[i].alive) {
			fireballs[i].alive = true;
			fireballs[i].w = FIREBALL_WIDTH;
			fireballs[i].h = FIREBALL_HEIGHT;

			fireballs[i].x = malfoy.x - 20;
			fireballs[i].y = malfoy.y + (malfoy.height / 2) - (FIREBALL_HEIGHT / 2);
			fireballs[i].vx = -FIREBALL_SPEED;

			
			malfoy.isAttacking = true;
			malfoy.attackWindow = MALFOY_ATTACK_WINDOW_MAX;

			malfoy.rangedCasting = true;
			malfoy.meleeActive = false;

			malfoy.fireballCooldown = FIREBALL_COOLDOWN_TICKS;
			break;
		}
	}
}


void moveFireballs() {
	if (currentGameState != GAMEPLAY) return;

	for (int i = 0; i < MAX_FIREBALLS; i++) {
		if (!fireballs[i].alive) continue;

		fireballs[i].x += fireballs[i].vx;

		
		int hx1 = harry.x, hy1 = harry.y;
		int hx2 = harry.x + harry.width - 170;
		int hy2 = harry.y + harry.height;

		// Fireball AABB
		int fx1 = fireballs[i].x, fy1 = fireballs[i].y;
		int fx2 = fireballs[i].x + fireballs[i].w;
		int fy2 = fireballs[i].y + fireballs[i].h;

		bool overlapX = (hx2 >= fx1) && (hx1 <= fx2);
		bool overlapY = (hy2 >= fy1) && (hy1 <= fy2);

		if (overlapX && overlapY) {
			hero_take_damage(FIREBALL_DAMAGE);
			fireballs[i].alive = false;
			continue;
		}

		// Off-screen cleanup
		if (fireballs[i].x < -FIREBALL_WIDTH || fireballs[i].x > SCREEN_WIDTH + FIREBALL_WIDTH) {
			fireballs[i].alive = false;
		}
	}
}

void renderFireballs() {
	if (currentGameState != GAMEPLAY) return;
	for (int i = 0; i < MAX_FIREBALLS; i++) {
		if (!fireballs[i].alive) continue;
		iShowImage(fireballs[i].x, fireballs[i].y, fireballs[i].w, fireballs[i].h, fireballImg);
	}
}


bool allSpidersDefeated() {
	
	for (int i = 0; i < spiderCount; i++) {
		if (!spider[i].spawned || spider[i].alive) return false;
		
	}
	return true;
}


void checkBossSpawn(int worldX) {
	if (!malfoy.spawned && allSpidersDefeated() && worldX >= BOSS_WORLD_SPAWN_X) {
		malfoy.spawned = true;
		malfoy.alive = true;

		
		malfoy.x = BOSS_ENTRY_START_X;
		malfoy.y = 45;
		malfoy.entering = true;

		// Reset combat state
		malfoy.hitCooldown = 0;
		malfoy.attackCooldown = 0;
		malfoy.attackWindow = 0;
		malfoy.fireballCooldown = 12; // slight delay before first ranged shot

		malfoy.isAttacking = false;
		malfoy.meleeActive = false;
		malfoy.rangedCasting = false;
	}
}

void moveMalfoy() {
	if (currentGameState != GAMEPLAY) return;
	if (!malfoy.spawned || !malfoy.alive) return;

	// Tick cooldowns
	if (malfoy.hitCooldown > 0)      malfoy.hitCooldown--;
	if (malfoy.attackCooldown > 0)   malfoy.attackCooldown--;
	if (malfoy.fireballCooldown > 0) malfoy.fireballCooldown--;
	if (heroDamageCooldown > 0)      heroDamageCooldown--;

	
	if (malfoy.entering) {
		malfoy.x -= BOSS_SPEED;
		if (malfoy.x <= BOSS_FIXED_SCREEN_X) {
			malfoy.x = BOSS_FIXED_SCREEN_X;
			malfoy.entering = false; // anchor reached
		}
		return; 
	}

	// Anchored each frame
	malfoy.x = BOSS_FIXED_SCREEN_X;

	
	int gap = malfoy.x - (harry.x + harry.width);

	
	const int MELEE_STRIKE_GAP = BOSS_MELEE_STRIKE_GAP;
	bool meleeNow = (gap < MELEE_STRIKE_GAP);
	bool rangedNow = (gap >= MELEE_STRIKE_GAP);

	
	if (malfoy.rangedCasting && malfoy.attackWindow > 0) {
		return; 
	}

	if (meleeNow) {
		
		if (malfoy.attackWindow == 0 && malfoy.attackCooldown == 0) {
			malfoy.isAttacking = true;
			malfoy.attackWindow = MALFOY_ATTACK_WINDOW_MAX;
			malfoy.attackCooldown = 4;
			malfoy.meleeActive = true;
			malfoy.rangedCasting = false;
		}

		
		if (malfoy.meleeActive && malfoy.attackWindow > 0) {
			int hx1 = harry.x, hy1 = harry.y;
			int hx2 = harry.x + harry.width;
			int hy2 = harry.y + harry.height;

			int bx1 = malfoy.x, by1 = malfoy.y;
			int bx2 = malfoy.x + malfoy.width;
			int by2 = malfoy.y + malfoy.height;

			bool overlapX = (hx2 >= bx1) && (hx1 <= bx2);
			bool overlapY = (hy2 >= by1) && (hy1 <= by2);

			if (overlapX && overlapY) {
				
				hero_take_damage(BOSS_CONTACT_DAMAGE);
			}
		}
	}
	else if (rangedNow) {
		
		if (malfoy.fireballCooldown == 0) {
			spawnFireballFromMalfoy(); 
			malfoy.meleeActive = false;
			malfoy.fireballCooldown = FIREBALL_COOLDOWN_TICKS;
			
		}
	}
}

void updateMalfoyFrame() {
	if (currentGameState != GAMEPLAY) return;
	if (!malfoy.spawned || !malfoy.alive) return;

	if (malfoy.attackWindow > 0) {
		malfoy.attackWindow--;
		malfoy.isAttacking = true;
		if (malfoy.attackWindow == 0) {
			malfoy.isAttacking = false;
			malfoy.meleeActive = false;   
			malfoy.rangedCasting = false;  
		}
	}
}

void renderBoss() {
	if (currentGameState != GAMEPLAY) return;
	if (!malfoy.spawned || !malfoy.alive) return;

	if (malfoy.isAttacking && malfoy.attackWindow > 0) {
		
		int img = (malfoy.rangedCasting && malfoy.rangedImg > 0) ? malfoy.rangedImg : malfoy.attackImg;
		iShowImage(malfoy.x, malfoy.y, malfoy.width, malfoy.height, img);
	}
	else {
		iShowImage(malfoy.x, malfoy.y, malfoy.width, malfoy.height, malfoy.stillImg);
	}
}

void checkHeroAttackCollision() {
	if (currentGameState != GAMEPLAY) return;
	if (!(harry_state == attack && harry.isAttacking)) return;
	if (attackWindow <= 0) return;

	// Attack IMAGE bounds
	int attackX1 = harry.x - 225;
	int attackY1 = harry.y;
	int attackX2 = attackX1 + harry.attImgWidth;  
	int attackY2 = attackY1 + harry.height;

	// Spiders
	for (int i = 0; i < spiderCount; i++) {
		if (!spider[i].alive || !spider[i].spawned) continue;

		int sx1 = spider[i].x + 30;
		int sy1 = spider[i].y;
		int sx2 = sx1 + spider[i].width;
		int sy2 = sy1 + spider[i].height;

		bool overlapX = (attackX2 >= sx1) && (attackX1 <= sx2);
		bool overlapY = (attackY2 >= sy1) && (attackY1 <= sy2);

		if (overlapX && overlapY) {
			if (spider[i].hitCooldown == 0) {
				spider[i].hp -= 1;
				spider[i].hitCooldown = SPIDER_HIT_COOLDOWN_TICKS;

				if (spider[i].hp <= 0) {
					spider[i].alive = false;
					heroScore += 10;
					spiderCnt--;
				}
			}
		}
	}

	// Boss (Malfoy) 
	if (malfoy.spawned && malfoy.alive) {
		const int ATT_INSET_TOP = 40;
		const int ATT_INSET_BOTTOM = 40;

		const int ATT_INSET_LEFT_R = 260;
		const int ATT_INSET_RIGHT_R = 200;
		const int ATT_INSET_LEFT_L = 200;
		const int ATT_INSET_RIGHT_L = 260;

		int hitX1 = attackX1;
		int hitX2 = attackX2;
		int hitY1 = attackY1 + ATT_INSET_BOTTOM;
		int hitY2 = attackY2 - ATT_INSET_TOP;

		if (lookRight) {
			hitX1 = attackX1 + ATT_INSET_LEFT_R;
			hitX2 = attackX2 - ATT_INSET_RIGHT_R;
		}
		else {
			hitX1 = attackX1 + ATT_INSET_LEFT_L;
			hitX2 = attackX2 - ATT_INSET_RIGHT_L;
		}

		if (hitX1 > hitX2) { int t = hitX1; hitX1 = hitX2; hitX2 = t; }
		if (hitY1 > hitY2) { int t = hitY1; hitY1 = hitY2; hitY2 = t; }

		// Boss AABB 
		int bx1 = malfoy.x + 120, by1 = malfoy.y;
		int bx2 = malfoy.x + malfoy.width;
		int by2 = malfoy.y + malfoy.height;

		bool overlapBossX = (hitX2 >= bx1) && (hitX1 <= bx2);
		bool overlapBossY = (hitY2 >= by1) && (hitY1 <= by2);

		if (overlapBossX && overlapBossY) {
			if (malfoy.hitCooldown == 0) {
				malfoy.hp -= 1;
				malfoy.hitCooldown = MALFOY_HIT_COOLDOWN_TICKS;

				if (malfoy.hp <= 0) {
					malfoy.alive = false;
					malfoy.isAttacking = false;
					heroScore += 100;
					currentGameState = WINSCREEN; 
				}
			}
		}
	}

	// Fireball
	for (int i = 0; i < MAX_FIREBALLS; i++) {
		if (!fireballs[i].alive) continue;

		int fx1 = fireballs[i].x;
		int fy1 = fireballs[i].y;
		int fx2 = fireballs[i].x + fireballs[i].w;
		int fy2 = fireballs[i].y + fireballs[i].h;

		bool overlapXFb = (attackX2 >= fx1) && (attackX1 <= fx2);
		bool overlapYFb = (attackY2 >= fy1) && (attackY1 <= fy2);

		if (overlapXFb && overlapYFb) {
			fireballs[i].alive = false; 
		}
	}
}


// Boss health bar 
#define BOSS_BAR_WIDTH     HP_BAR_WIDTH
#define BOSS_BAR_HEIGHT    HP_BAR_HEIGHT
#define BOSS_BAR_MARGIN_X  20   
#define BOSS_BAR_MARGIN_Y  20   


void renderBossHUD(void);

void renderBossHUD() {
	if (currentGameState != GAMEPLAY) return;
	
	if (!malfoy.spawned || !malfoy.alive) return;

	
	int barW = BOSS_BAR_WIDTH;
	int barH = BOSS_BAR_HEIGHT;
	int barX = SCREEN_WIDTH - BOSS_BAR_MARGIN_X - barW;
	int barY = SCREEN_HEIGHT - BOSS_BAR_MARGIN_Y - barH;

	// Background and border
	iSetColor(50, 50, 50);
	iFilledRectangle(barX, barY, barW, barH);

	iSetColor(0, 0, 0);
	iRectangle(barX, barY, barW, barH);

	static int bossHudMaxHP = -1;
	if (bossHudMaxHP <= 0) {
		bossHudMaxHP = (BOSS_BASE_HP > 0) ? BOSS_BASE_HP : malfoy.hp;
	}
	if (malfoy.hp > bossHudMaxHP) {
		bossHudMaxHP = malfoy.hp; 
	}


	float ratio = (bossHudMaxHP > 0) ? (float)malfoy.hp / (float)bossHudMaxHP : 0.0f;
	if (ratio < 0.0f) ratio = 0.0f;
	if (ratio > 1.0f) ratio = 1.0f;

	int innerW = barW - 2;
	int fillW = (int)(ratio * (float)innerW);


	if (ratio > 0.5f)        iSetColor(200, 40, 40);   // bright red
	else if (ratio > 0.25f)  iSetColor(255, 160, 0);   // orange
	else                     iSetColor(160, 0, 0);     // dark red

	if (fillW > 0) {
		iFilledRectangle(barX + 1, barY + 1, fillW, barH - 2);
	}

	// Text label
	iSetColor(256, 256, 256);
	char bossTxt[40];
	SAFE_SNPRINTF(bossTxt, sizeof(bossTxt), "Malfoy: %d/%d", malfoy.hp, bossHudMaxHP);
	iText(barX + 8, barY + 4, bossTxt, GLUT_BITMAP_HELVETICA_12);
}



#endif SPRITE_H