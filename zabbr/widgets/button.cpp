#include "widgets/button.h"
#include "resources/resourcemanager.h"

namespace Zabbr {

	/**
	 * Constructor.
	 *
	 * @param window The window of the button.
	 * @param label The textual label of the button.
	*/
	Button::Button(SDLWindow* window, std::string label)
	       : VWidget(window), fLabel(label), fWidth(0),
	         fHeight(0), fHover(false) {
		FontResource* font = ResourceManager::manager().font("../data/DejaVuSans-Bold.ttf", 24);
		SDL_Color c = {0, 0, 0};
		fStringLabel = ResourceManager::manager().string(label, font, c);
		ResourceManager::manager().free(font);
	}

	/**
	 * The destructor.
	*/
	Button::~Button() {
		ResourceManager::manager().free(fStringLabel);
	}

	/**
	 * Connects a message for a mouse click.
	 *
	 * @param e The mouse click event.
	*/
	void Button::connectOnMouseClick(IMouseButtonCallback* e) {
		fMouseClickEvent.connect(e);
	}

	/**
	 * Returns the width of the button.
	 *
	 * @return The width of the button.
	*/
	int Button::getWidth() {
		return fWidth ? fWidth : getRealWidth();
	}

	/**
	 * Sets the width of the button.
	 *
	 * @param w The new width of the button. 0 for the default width.
	*/
	void Button::setWidth(int w) {
		fWidth = w;
	}

	/**
	 * Returns the height of the button.
	 *
	 * @return The height of the button.
	*/
	int Button::getHeight() {
		return fHeight ? fHeight : getRealHeight();
	}

	/**
	 * Sets the height of the button.
	 *
	 * @param h The new height of the button. 0 for the default height.
	*/
	void Button::setHeight(int h) {
		fHeight = h;
	}

	/**
	 * Draws the button on a specified location on the window.
	 *
	 * @param x The x coordinate of the button.
	 * @param y The y coordinate of the button.
	*/
	void Button::draw(int x, int y) {
		if (! fFill) {
			x = x - getRealWidth() / 2;
			y = y + (getHeight() - getRealHeight()) / 2;
			if (! fHover) {
				fWindow->drawRectangle(x, y, getRealWidth(), getRealHeight()-10, 255, 0, 0);
			} else {
				fWindow->drawRectangle(x, y, getRealWidth(), getRealHeight()-10, 0, 255, 0);
			}
			fWindow->drawString(fStringLabel, x+10, y+5);

			fBoundingBox.x = x;
			fBoundingBox.y = y;
			fBoundingBox.w = getRealWidth();
			fBoundingBox.h = getRealHeight() - 10;
		} else {
			x = x - getWidth() / 2;
			fWindow->drawRectangle(x, y, getWidth(), getHeight(), 255, 0, 0);
		}
	}

	/**
	 * Function called by the SDLWindow if a mouse motion is fired on the window.
	 *
	 * @param e The SDL Mouse Motion event.
	*/
	void Button::mouseMotion(SDL_MouseMotionEvent e) {
		if (fBoundingBox.x < e.x && fBoundingBox.x + fBoundingBox.w > e.x &&
		    fBoundingBox.y < e.y && fBoundingBox.y + fBoundingBox.h > e.y ) {
			fHover = true;
		} else {
			fHover = false;
		}
	}

	/**
	 * Function called by the SDLWindow if a mouse button event is fired on the window.
	 *
	 * @param e The SDL Mouse Button event.
	*/
	void Button::mouseButton(SDL_MouseButtonEvent e) {
		if (fHover && e.button == SDL_BUTTON_LEFT) {
			fMouseClickEvent.fire(e);
		}
	}

	/**
	 * Returns the real width of the button.
	 *
	 * The real width is the width of the label + a margin.
	*/
	int Button::getRealWidth() {
		return fStringLabel->getWidth() + 20;
	}

	/**
	 * Returns the real height of the button.
	 *
	 * The real height is the height of the label + a margin.
	*/
	int Button::getRealHeight() {
		return fStringLabel->getHeight() + 20;
	}
}