/*
Author:			Charlie Mathews
Created:		November 6th, 2015
Derived from:	Charles Kelly, Programming 2D Games (c) 2011,2012
*/

#ifndef _MY_GAME_H      // Prevent multiple definitions if this 
#define _MY_GAME_H      // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

class myGame;

#include <cmath>
#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "constants.h"
#include "entityManager.h"
#include "game.h"
#include "graphics.h"
#include "image.h"
#include "textureManager.h"
#include "textDX.h"
#include "textManager.h"

#include "pattern.h"
#include "menu.h"
#include "player.h"
#include "city.h"
#include "alien.h"
#include "projectile.h"
#include "bolide.h"
#include "spitball.h"
#include "rocket.h"
#include "particleManager.h"
#include "explosion.h"

//=============================================================================
// This class is the core of the game
//=============================================================================
class myGame : public Game
{
private:
	TextureManager alienTM, rocketTM,bolideTM,cityTM,playerTM, spitTM, explosionTM ;
	TextureManager menubTM, backgroundTM, background2TM,starsTM,creditsTM,instructTM,crossHairTM;

	Image menub, backgroundImage, backgroundImage2, starImage, creditsImage, instructImage, crossHairImage, rocketsRemaining[MAX_ROCKETS];
	VECTOR2 collisionVector ;

	GameStates gameStates ;
	Menu *menu ;
	bool sfxOn ;

	TextDX* dxFont;
	TextDX* scoreFont;
	TextDX* smallFont; 
	int scoreWidth;
	TextManager scoreUI ;

	Alien mAlien;
	Player thePlayer ;
	EntityManager aliens ;
	EntityManager rockets ;
	EntityManager bolides ;
	EntityManager cities ;
	EntityManager spits ;
	EntityManager explosions ;
	
	int score ;
	float timer ;
	float bolideTimer ;
	float alienTimer ;
	float scoreDispCounter ;
	int tickCounter;
	bool getMouseDepressedLast;
	bool enterDepressedLastFrame;
	int nightCount, numCities;
	bool endedGame;
	//text
	std::stringstream buffer ;
	//particles
	ParticleManager pm;
	ParticleManager pmCity;
	//patterns
	Pattern* alienPattern;
	Pattern* alienPattern2;
	Pattern* alienPattern3;
	Pattern* alienPattern4;

	bool isNight;
	bool isTutorial;

	std::string scoreName;
	std::pair<std::string,int> topTenScores[MAX_SCORES_DISPLAYED];

public:
	// Constructor
	myGame();

	// Destructor
	virtual ~myGame();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
	void spawnBolide(VECTOR2 target);
	void scrollBG();
	void setSFX(){sfxOn = !sfxOn;}
	void fireRocket();
	void spawnAlien();
	void makeExplosion(VECTOR2 source);
	void fireSpitball(VECTOR2 source);
	void createParticleEffect(VECTOR2 pos, VECTOR2 vel, int numParticles);
	void createSmoke(VECTOR2 pos, VECTOR2 vel, int numParticles);
	void addHighScores(int newScore, std::string name);
	void restartGame();
	void loadHighScores();
	//void sortHighScores(string scores[], int size);
};
#endif