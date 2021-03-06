#ifndef INC_SDLGAMEVISUALIZER_H
#define INC_SDLGAMEVISUALIZER_H

/** \file
 * File for the SDL entity factory.
 *
 * @author Nathan Samson
*/

#include "zabbr/sdlwindow.h"
#include "zabbr/widgets/label.h"

#include "src/game/gamevisualizer.h"

namespace SISDL {
	/**
	 * SDL Implementation of game visualizer.
	*/
	class SDLGameVisualizer: public SI::IGameVisualizer {
	public:
		SDLGameVisualizer(Zabbr::SDLWindow*);
		~SDLGameVisualizer();
	
		virtual void draw();
		virtual bool inNonGamePhase();
		virtual void userDies();
		virtual void userWins();
		virtual void levelChange(std::string);
		void keyPress(SDL_KeyboardEvent);
	private:
		/**
		 * The window to draw the game on.
		*/
		Zabbr::SDLWindow* fWindow;
		
		/**
		 * Flag to see if we are in non game phase.
		*/
		bool fInNonGamePhase;
		
		/**
		 * The status text.
		*/
		Zabbr::Label* fStatusLabel;
	};
}

#endif // INC_SDLGAMEVISUALIZER_H
