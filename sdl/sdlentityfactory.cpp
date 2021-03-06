/** \file
 * File for the SDL entity factory.
 *
 * @author Nathan Samson
*/

#include "sdlentityfactory.h"
#include "sdlship.h"
#include "sdlusership.h"
#include "sdlbullet.h"
#include "sdlclusterbomb.h"

namespace SISDL {
	/**
	 * Public constructor
	 *
	 * @param w The window
	*/
	SDLEntityFactory::SDLEntityFactory(Zabbr::SDLWindow* w): fWindow(w) {
	}
	
	/**
	 * Creates a user ship.
	 *
	 * @param driver The driver for the ship.
	 * @param v The initial position.
	 * @param d The initial direction of the ship.
	 * @param g The group of the entity.
	 * @param w The weaponery of th entity.
	 * @param t The type of the ship.
	*/
	SI::Ship* SDLEntityFactory::createUserShip(SI::VShipDriver* driver, SI::Vector2 v, int d, SI::EntityGroup* g, SI::Weaponery* w, SI::ShipType t) {
		return new SDLUserShip(driver, v, d, g, t, this, w, fWindow);
	}

	/**
	 * Creates an AI ship.
	 *
	 * @param driver The driver for the ship.
	 * @param v The initial position.
	 * @param d The initial direction of the ship.
	 * @param g The group of the entity.
	 * @param w The weaponery of th entity.
	 * @param t The type of the ship.
	*/
	SI::Ship* SDLEntityFactory::createAIShip(SI::VShipDriver* driver, SI::Vector2 v, int d, SI::EntityGroup* g, SI::Weaponery* w, SI::ShipType t) {
		return new SDLShip(driver, v, d, g, t, this, w, fWindow);
	}
	
	/**
	 * Creates a bullet
	 *
	 * @param pos The initial position of the bullet.
	 * @param dir The initial direction of the bullet.
	 * @param g The group of the bullet.
	 * @param t Bullet information
	*/
	SI::Bullet* SDLEntityFactory::createBullet(SI::Vector2 pos, int dir, SI::EntityGroup* g, SI::BulletType* t) {
		return new SDLBullet(pos, dir, g, t, this, fWindow);
	}
	
	/**
	 * Creates a cluster bomb
	 *
	 * @param pos The initial position of the cluster bomb.
	 * @param dir The initial direction of the cluster bomb.
	 * @param g The group of the bomb.
	 * @param t Cluster bomb information
	*/
	SI::ClusterBomb* SDLEntityFactory::createClusterBomb(SI::Vector2 pos, int dir,
	                  SI::EntityGroup* g, SI::ClusterBombType* t) {
		return new SDLClusterBomb(pos, dir, g, t, this, fWindow);
	}
}
