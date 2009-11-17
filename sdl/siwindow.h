#ifndef INC_SIWINDOW_H
#define INC_SIWINDOW_H

#include "guiframework/sdlwindow.h"
#include "guiframework/events/callbacks.h"

namespace sisdl {
	using namespace sdlframework;


	class SIWindow : public  SDLWindow {
	public:
		void run();

		void onQuit(SDL_MouseButtonEvent);
		void confirmQuit(SDL_MouseButtonEvent);
		void cancelQuit(SDL_MouseButtonEvent);
	};

	class SIWindowMouseButtonCallback : public IMouseButtonCallback {
	public:
		SIWindowMouseButtonCallback(SIWindow*, void (SIWindow::*)(SDL_MouseButtonEvent));
		virtual void call(SDL_MouseButtonEvent);
	private:
		SIWindow* fWindow;
		void (SIWindow::* fFunction)(SDL_MouseButtonEvent);
	};

}

#endif // INC_SIWINDOW_H
