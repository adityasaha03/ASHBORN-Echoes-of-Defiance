
#include "menuManager.hpp"
#ifndef SOUNDS_H
#define SOUNDS_H

void menuMusic(){

	mciSendString("open \"assets\\Audio\\Background.mp3\" alias bgsong", NULL, 0, NULL);
	
	

	// Playing the background audio on repeat
	mciSendString("play bgsong repeat", NULL, 0, NULL);
}




#endif