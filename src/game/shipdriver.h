#ifndef INC_SHIPDRIVER_H
#define INC_SHIPDRIVER_H

/** \file
 * File for the ship driver.
 *
 * @author Nathan Samson
*/

#include "misc/vector2.h"

namespace SI {
	class Ship;

	/**
	 * A virtual ship driver.
	*/
	class VShipDriver {
	public:
		VShipDriver();

		/**
		 * Update the ship.
		*/
		virtual void update(int) = 0;
		void bind(Ship*);
	protected:
		void move(Vector2&, int);
		void fire();
	private:
		/**
		 * The ship to driver.
		*/
		Ship* fEntity;
	};
}

#endif // INC_SHIPDRIVER_H
