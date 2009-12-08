#include "zabbr/controller/sdlcontroller.h"
#include "zabbr/controller/menucontroller.h"
#include "zabbr/misc/stopwatch.h"
#include "src/game/game.h"

#include "sdlinputdriver.h"

namespace SISDL {
	
	/**
	 * The game controller.
	*/
	class GameController: public Zabbr::VSDLController {
	public:
		GameController(Zabbr::SDLWindow*);
		virtual ~GameController();
	
		virtual void draw();
		virtual void keyDown(SDL_KeyboardEvent);
		virtual void keyRelease(SDL_KeyboardEvent);
		
		void onRequestQuitGame();
		void onResumeGame(SDL_MouseButtonEvent);
		void onQuitGame(SDL_MouseButtonEvent);
		void onCloseGame(SDL_MouseButtonEvent);
	private:
		/**
		 * The game
		*/
		SI::Game* fGame;
		
		/**
		 * The input driver for the user.
		*/
		SDLInputDriver* fInputDriver;
		
		/**
		 * The timer.
		*/
		Zabbr::Stopwatch fTimer;
		
		/**
		 * The remaining time of last frame.
		*/
		double fTimeRemainder;
		
		/**
		 * The quit confirmation dialog.
		*/
		Zabbr::MenuController* fQuitConfirmation;
		
		/**
		 * Flag to see if we should close.
		*/
		bool fClosed;
	};
}
