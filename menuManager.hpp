
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int menuImage;
int focusStart;
int focusCredits;
int focusControls;
int focusScore;
int focusQuit;


int houseSelectionPage;
int gryffindor;
int slytherin;
int hufflepuff;
int ravenclaw;

int gryffindorInfo;
int slytherinInfo;
int hufflepuffInfo;
int ravenclawInfo;

int focusBack;

int levelSelectionPage;
int level1;
int level2;
int level3;
int level4;

int pause;
int controls;
int win;
int lose;
int credits;
int score;

int level_map1;


void menuImageSourcer()
{
	menuImage = iLoadImage("assets\\startMenu\\menuImage.png");
	focusStart = iLoadImage("assets\\startMenu\\white_play1.png");
	focusCredits = iLoadImage("assets\\startMenu\\white_credits1.png");
	focusControls = iLoadImage("assets\\startMenu\\white_controls.png");
	focusScore = iLoadImage("assets\\startMenu\\white_score.png");
	focusQuit = iLoadImage("assets\\startMenu\\white_quit1.png");
	focusBack = iLoadImage("assets\\houseSelection\\backButton.png");


	houseSelectionPage = iLoadImage("assets\\startMenu\\houseSelectionPage2.png");

	gryffindor = iLoadImage("assets\\houseSelection\\gryffindor1.png");
	slytherin = iLoadImage("assets\\houseSelection\\slytherin1.png");
	hufflepuff = iLoadImage("assets\\houseSelection\\hufflepuff1.png");
	ravenclaw = iLoadImage("assets\\houseSelection\\ravenclaw1.png");

	gryffindorInfo = iLoadImage("assets\\houseSelection\\gryffindorInfo3.png");
	slytherinInfo = iLoadImage("assets\\houseSelection\\slytherinInfo3.png");
	hufflepuffInfo = iLoadImage("assets\\houseSelection\\hufflepuffInfo3.png");
	ravenclawInfo = iLoadImage("assets\\houseSelection\\ravenclawInfo3.png");

	focusBack = iLoadImage("assets\\houseSelection\\backButton1.png");


	levelSelectionPage = iLoadImage("assets\\levelSelection\\LevelSelctionScreen.png");
	level1 = iLoadImage("assets\\levelSelection\\lvsHover1.png");
	level2 = iLoadImage("assets\\levelSelection\\lvsHover2.png");
	level3 = iLoadImage("assets\\levelSelection\\lvsHover3.png");
	level4 = iLoadImage("assets\\levelSelection\\lvsHover4.png");

	pause = iLoadImage("assets\\startMenu\\pause_menu.png");
	controls = iLoadImage("assets\\startMenu\\controls2.png");
	win = iLoadImage("assets\\startMenu\\win.png");
	lose = iLoadImage("assets\\startMenu\\gameOver.png");
	credits = iLoadImage("assets\\startMenu\\credits.png");
	score = iLoadImage("assets\\startMenu\\score.png");





}

enum GameState {
	MENU,
	SCORE,
	CREDITS,

	HOUSE_SELECTION,
	LEVEL_SELECTION,

	GAMEPLAY,
	PAUSE_MENU,
	CONTROLS, 
	PAUSE_CONTROLS,
	WINSCREEN,
	GAMEOVER

}; GameState currentGameState = MENU;


enum HouseState {

	GRYFFINDOR,
	SLYTHERIN,
	HUFFLEPUFF,
	RAVENCLAW

}; HouseState currentHouseState;

enum LevelState {
	
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4

}; LevelState currentLevelState = LEVEL1;


enum harryStateEnum {
	harry_still,
	left,
	right,
	attack,
	
};

harryStateEnum harry_state = harry_still;


void gamestateChanger()
{
	if (currentGameState == MENU)
		iShowImage(0, 0, 1280, 720, menuImage);
	
	else if (currentGameState == CREDITS)
		iShowImage(0, 0, 1280, 720, credits);

	else if (currentGameState == SCORE)
		iShowImage(0, 0, 1280, 720, score);
	
	else if (currentGameState == HOUSE_SELECTION)
		iShowImage(0, 0, 1280, 720, houseSelectionPage);
	
	else if (currentGameState == LEVEL_SELECTION)
		iShowImage(0, 0, 1280, 720, levelSelectionPage);

	else if (currentGameState == GAMEPLAY && currentLevelState == LEVEL1)
		iShowImage(0, 0, 2560, 720, level_map1);
	
	else if (currentGameState == PAUSE_MENU)
		iShowImage(0, 0, 1280, 720, pause);
	
	else if (currentGameState == CONTROLS || currentGameState == PAUSE_CONTROLS)
		iShowImage(0, 0, 1280, 720, controls);

	else if (currentGameState == WINSCREEN)
		iShowImage(0, 0, 1280, 720, win);

	else if (currentGameState == GAMEOVER)
		iShowImage(0, 0, 1280, 720, lose);
}


int hoverPlay		= 0;
int hoverSettings	= 0;
int hoverCredits	= 0;
int hoverStore		= 0;
int hoverQuit		= 0;
int hoverBack		= 0;


void hoverButtonPosition(int mx, int my)
{
	if (currentGameState == MENU && (mx >= 515 && mx <= 770) && (my >= 421 && my <= 478))
		hoverPlay = 1;
	else hoverPlay = 0;

	if (currentGameState == MENU && (mx >= 200 && mx <= 370) && (my >= 55 && my <= 95))
		hoverCredits = 1;
	else hoverCredits = 0;

	if (currentGameState == MENU && (mx >= 435 && mx <= 605) && (my >= 55 && my <= 95))
		hoverStore = 1;
	else hoverStore = 0;

	if (currentGameState == MENU && (mx >= 670 && mx <= 842) && (my >= 55 && my <= 95))
		hoverSettings = 1;
	else hoverSettings = 0;

	if (currentGameState == MENU && (mx >= 908 && mx <= 1080) && (my >= 55 && my <= 95))
		hoverQuit = 1;
	else hoverQuit = 0;


	if (currentGameState == HOUSE_SELECTION && (mx >= 51 && mx <= 155) && (my >= 30 && my <= 80))
		hoverBack = 1;
	else hoverBack = 0;

}

void menuButtonHover()
{
	if (currentGameState != MENU) return;
	
	else if (hoverPlay)
		iShowImage(504, 410, 276, 77, focusStart);
	
	else if (hoverCredits)
		iShowImage(193, 48, 185, 52, focusCredits);
	
	else if(hoverStore)
		iShowImage(429, 48, 185, 52, focusScore);
	
	else if(hoverSettings)
		iShowImage(665, 48, 185, 52, focusControls);
	
	else if (hoverQuit)
		iShowImage(901, 48, 185, 52, focusQuit);
	
}



void menuButtonClicker(int mx, int my)
{
	if (currentGameState == MENU && (mx >= 515 && mx <= 770) && (my >= 421 && my <= 478)) // play
		currentGameState = HOUSE_SELECTION;

	if (currentGameState == MENU && (mx >= 200 && mx <= 370) && (my >= 55 && my <= 95)) // credits
		currentGameState = CREDITS;

	if (currentGameState == MENU && (mx >= 435 && mx <= 605) && (my >= 55 && my <= 95)) // store
		currentGameState = SCORE;

	if (currentGameState == MENU && (mx >= 670 && mx <= 842) && (my >= 55 && my <= 95)) // settings
		currentGameState = CONTROLS;
	
	if (currentGameState == MENU && (mx >= 908 && mx <= 1080) && (my >= 55 && my <= 95)) // quit
		exit(0);

}

void controlsClicker(int mx, int my)
{
	if (currentGameState == CONTROLS && (mx >= 1109 && mx <= 1221) && (my >= 69 && my <= 122))
		currentGameState = MENU;
}



int hoverGryffindor = 0;
int hoverSlytherin = 0;
int hoverHufflepuff = 0;
int hoverRavenclaw = 0;

void hoverHouseFlagPosition(int mx, int my)
{
	if (currentGameState == HOUSE_SELECTION && (mx >= 124 && mx <= 219) && (my >= 321 && my <= 584))
		hoverGryffindor = 1;
	else hoverGryffindor = 0;

	if (currentGameState == HOUSE_SELECTION && (mx >= 269 && mx <= 342) && (my >= 284 && my <= 490))
		hoverSlytherin = 1;
	else hoverSlytherin = 0;

	if (currentGameState == HOUSE_SELECTION && (mx >= 932 && mx <= 1004) && (my >= 270 && my <= 484))
		hoverHufflepuff = 1;
	else hoverHufflepuff = 0;

	if (currentGameState == HOUSE_SELECTION && (mx >= 1033 && mx <= 1125) && (my >= 323 && my <= 583))
		hoverRavenclaw = 1;
	else hoverRavenclaw = 0;
}



void houseFlagHover()
{

	if (currentGameState != HOUSE_SELECTION) return;

	if (hoverGryffindor){
		iShowImage(125, 248, 95, 337, gryffindor);
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, gryffindorInfo);
	}

	if (hoverSlytherin){
		iShowImage(267, 218, 77, 268, slytherin);
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, slytherinInfo);
	}

	if (hoverHufflepuff){
		iShowImage(932, 220, 73, 265, hufflepuff);
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, hufflepuffInfo);
	}

	if (hoverRavenclaw){
		iShowImage(1033, 254, 94, 329, ravenclaw);
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, ravenclawInfo);
	}

	if (hoverBack)
		iShowImage(46, 24, 114, 59, focusBack);
}


void houseFlagClicker(int mx, int my)
{

	if (currentGameState != HOUSE_SELECTION) return;
	
	if (currentGameState == HOUSE_SELECTION && (mx >= 124 && mx <= 219) && (my >= 321 && my <= 584)) // 
	{
		currentGameState = GAMEPLAY;
		currentHouseState = GRYFFINDOR;
	}

	if (currentGameState == HOUSE_SELECTION && (mx >= 269 && mx <= 342) && (my >= 284 && my <= 490)) // 
	{
		currentGameState = GAMEPLAY;
		currentHouseState = SLYTHERIN;
	}

	if (currentGameState == HOUSE_SELECTION && (mx >= 932 && mx <= 1004) && (my >= 270 && my <= 484)) // 
	{
		currentGameState = GAMEPLAY;
		currentHouseState = HUFFLEPUFF;
	}

	if (currentGameState == HOUSE_SELECTION && (mx >= 1033 && mx <= 1125) && (my >= 323 && my <= 583)) // 
	{
		currentGameState = GAMEPLAY;
		currentHouseState = RAVENCLAW;
	}



	if (currentGameState == HOUSE_SELECTION && (mx >= 51 && mx <= 155) && (my >= 30 && my <= 80)) // back
		currentGameState = MENU;

}



int hoverLevel1 = 0;
int hoverLevel2 = 0;
int hoverLevel3 = 0;
int hoverLevel4 = 0;

void hoverLevelPosition(int mx, int my)
{

	if (currentGameState == LEVEL_SELECTION && (mx >= 132 && mx <= 329) && (my >= 332 && my <= 479))
		hoverLevel1 = 1;
	else hoverLevel1 = 0;

	if (currentGameState == LEVEL_SELECTION && (mx >= 414 && mx <= 595) && (my >= 369 && my <= 520))
		hoverLevel2 = 1;
	else hoverLevel2 = 0;

	if (currentGameState == LEVEL_SELECTION && (mx >= 683 && mx <= 841) && (my >= 331 && my <= 448))
		hoverLevel3 = 1;
	else hoverLevel3 = 0;

	if (currentGameState == LEVEL_SELECTION && (mx >= 951 && mx <= 1151) && (my >= 353 && my <= 512))
		hoverLevel4 = 1;
	else hoverLevel4 = 0;

}


void levelHover()
{
	if (currentGameState != LEVEL_SELECTION) return;

	if (hoverLevel1 && currentLevelState == LEVEL1)
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, level1);
		
	if (hoverLevel2 && currentLevelState == LEVEL2)
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, level2);
		
	if (hoverLevel3 && currentLevelState == LEVEL3)
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, level3);
		
	if (hoverLevel4 && currentLevelState == LEVEL4)
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, level4);
		
}


void levelClicker(int mx, int my)
{
	if (currentGameState != LEVEL_SELECTION) return;

	if (currentGameState == LEVEL_SELECTION && (mx >= 132 && mx <= 329) && (my >= 332 && my <= 479)) // 
	{
		currentGameState = GAMEPLAY;
		currentLevelState = LEVEL1;
		
	}

	if (currentGameState == LEVEL_SELECTION && (mx >= 414 && mx <= 595) && (my >= 369 && my <= 520)) // 
	{
		//currentGameState = GAMEPLAY_Gryffindor;
	}

	if (currentGameState == LEVEL_SELECTION && (mx >= 683 && mx <= 841) && (my >= 331 && my <= 448)) // 
	{
		//currentGameState = GAMEPLAY_Gryffindor;
	}

	if (currentGameState == LEVEL_SELECTION && (mx >= 951 && mx <= 1151) && (my >= 353 && my <= 512)) // 
	{
		//currentGameState = GAMEPLAY_Gryffindor;
	}
	if (currentGameState == LEVEL_SELECTION && (mx >= 1198 && mx <= 1235) && (my >= 657 && my <= 691)) // 
	{
		currentGameState = HOUSE_SELECTION;
	}

}

void fullResetCore();

void pauseMenuClicker(int mx, int my)
{
	if (currentGameState == PAUSE_MENU && (mx >= 542 && mx <= 747) && (my >= 496 && my <= 541))  // resume
		currentGameState = GAMEPLAY;
	
	else if (currentGameState == PAUSE_MENU && (mx >= 542 && mx <= 747) && (my >= 407 && my <= 450)) // new game
	{
		currentGameState = HOUSE_SELECTION;
		fullResetCore();
	}
	
	else if (currentGameState == PAUSE_MENU && (mx >= 542 && mx <= 747) && (my >= 318 && my <= 362)) //controls
	{
		currentGameState = PAUSE_CONTROLS;
		bool pause = true;
	}

	else if (currentGameState == PAUSE_MENU && (mx >= 542 && mx <= 747) && (my >= 225 && my <= 271)) //quit game
	{
		currentGameState = MENU;
		fullResetCore();
	}
}

void pauseControlsClicker(int mx, int my)
{
	if (currentGameState == PAUSE_CONTROLS && (mx >= 1109 && mx <= 1221) && (my >= 69 && my <= 122))
		currentGameState = PAUSE_MENU;
}

void winLoseScreenClicker(int mx, int my)
{
		
	if (((mx >= 1109 && mx <= 1221) && (my >= 69 && my <= 122))) {
		fullResetCore();
		currentGameState = MENU;
	}
}

void commonButtonClicker(int mx, int my)
{

	if (((mx >= 1109 && mx <= 1221) && (my >= 69 && my <= 122))) {
		currentGameState = MENU;
	}
}

#endif