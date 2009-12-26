#ifndef INC_NORMALGAMEPANEL_H
#define INC_NORMALGAMEPANEL_H

/** \file
 * File for the SDL game panel.
 *
 * @author Nathan Samson
*/

#include "gamepanel.h"

namespace SISDL {
	class NormalGamePanel: public GamePanel {
	public:
		NormalGamePanel(Zabbr::SDLWindow* w);
		~NormalGamePanel();
	
		virtual void draw();
		virtual void keyPress(SDL_KeyboardEvent);
		virtual void keyRelease(SDL_KeyboardEvent);
		
		void onRequestQuitGame();
		void onResumeGame(SDL_MouseButtonEvent);
		void onQuitGame(SDL_MouseButtonEvent);
		void onCloseGame(SDL_MouseButtonEvent);
	private:
		/**
		 * The input driver for the user.
		*/
		SDLInputDriver* fInputDriver;
		
		/**
		 * The quit confirmation dialog.
		*/
		Zabbr::MenuPanel* fQuitConfirmation;
		
		/**
		 * The driver factory.
		*/
		SDLDriverFactory* fDriverFactory;
		
				
		/**
		 * The font.
		*/
		Zabbr::FontResource* fFont;
		
		/**
		 * The text of the score.
		*/
		Zabbr::StringFontResource* fScoreText;
	};
}

#endif // INC_NORMALGAMEPANEL_H
