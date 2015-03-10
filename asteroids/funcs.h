#ifndef _FUNCS_H
#define _FUNCS_H

#include <time.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <SDL2/SDL2_rotozoom.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 650;

using namespace std;


//Found and modified code to implement a timer for the game.

class timer {
	public:
		timer();
		void           start();
		void           stop();
		void           reset();
		bool           isRunning();
		float	       getTime();
		bool 	       isOver(unsigned long seconds);
	private:
		bool           resetted;
		bool           running;
		float  time;
		float  end;
};




timer::timer() {
	resetted = true;
	running = false;
	time = 0;
	end = 0;
}


void timer::start() {
	if(! running) {
		if(resetted)
			time = (unsigned long) clock();
		else
			time -= end - (unsigned long) clock();
		running = true;
		resetted = false;
	}
}


void timer::stop() {
	if(running) {
		end = (unsigned long) clock();
		running = false;
	}
}


void timer::reset() {
	bool wereRunning = running;
	if(wereRunning)
		stop();
	resetted = true;
	time = 0;
	end = 0;
	if(wereRunning)
		start();
}


bool timer::isRunning() {
	return running;
}


float timer::getTime() 
{
	if(running)
		return ((((float) clock() - time) / CLOCKS_PER_SEC) * 10);
	else
		return (((float)end - time)/100);

}





#endif
