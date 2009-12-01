#ifndef INC_GAMEENTITYFACTORY_H
#define INC_GAMEENTITYFACTORY_H

#include "game/shipdriver.h"
#include "game/ship.h"

namespace SI {
	/**
	 * The Game Entity Factory. Classes that implement this interface
	 * are responsible of creating the specific entity objects that can visualize themselves.
	*/
	class IGameEntityFactory {
	public:
		/**
		 * Creates a Ship.
		*/
		virtual Ship* createShip(VShipDriver*, Vector2) = 0;
	};
}

#endif // INC_GAMEENTITYFACTORY_H
