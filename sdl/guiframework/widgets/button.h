#ifndef INC_BUTTON_H
#define INC_BUTTON_H

#include <string>
#include <list>
#include "SDL.h"

#include "guiframework/widgets/widget.h"
#include "guiframework/events/callbacks.h"
#include "guiframework/events/event.h"

#include "guiframework/resources/stringfontresource.h"

namespace sdlframework {

	class Button : public VWidget {
	public:
		Button(SDLWindow*, std::string label);
		virtual ~Button();

		virtual void draw(int, int);
		virtual int getWidth();
		virtual void setWidth(int);
		virtual int getHeight();
		virtual void setHeight(int);

		// Events
		virtual void mouseMotion(SDL_MouseMotionEvent);
		virtual void mouseButton(SDL_MouseButtonEvent);

		void connectOnMouseClick(IMouseButtonCallback*);
	private:
		Button();
		std::string fLabel;
		int fWidth;
		int fHeight;
		bool fHover;
		StringFontResource* fStringLabel;
		SDL_Rect fBoundingBox;

		int getRealWidth();
		int getRealHeight();

		MouseButtonEvent fMouseClickEvent;
	};
}

#endif // INC_BUTTON_H
